#include <stdio.h>
#include <stdlib.h>
#include "GenericTree.h"

struct no{
  int info;
  struct no*esq;
  struct no*dir;
};

Arv cria_arvore(int elem)
{
  Arv novo = (Arv)malloc(sizeof(Arv));

  if (novo == NULL)
    return NULL;

  novo->info = elem;
  novo->esq = NULL;
  novo->dir = NULL;

  return novo;
}

int insere(Arv A, Arv sa)
{
  if (A == NULL)
    return 0;

  sa->dir = A->esq;
  A->esq = sa;

  return 1;
}

void libera_arvore(Arv *A)
{
  if (A != NULL)
  {
    libera_arvore(&(*A)->esq);
    libera_arvore(&(*A)->dir);
    free(*A);
  }

  A = NULL;
}

int remove_folha(Arv *A, int elem)
{
  if (A == NULL)
    return 0;

  if ((*A)->info == elem)
  {
    if ((*A)->esq == NULL && (*A)->dir == NULL)
    {
      free(*A);
      A = NULL;
      return 1;
    }
    else
      return 0;
  }
  else
  {
    int res = remove_folha(&(*A)->esq, elem);
    if (res == 1)
      return 1;

    res = remove_folha(&(*A)->dir, elem);
    if (res == 1)
      return 1;
  }

  return 0;
}

void exibe_arvore(Arv A)
{
  if (A != NULL)
  {
    printf("<");

    printf("%d", A->info);
    exibe_arvore(A->esq);
    printf(">");
    exibe_arvore(A->dir);
  }
}

int busca(Arv A, int elem)
{
  if (A == NULL)
    return 0;

  if(A->info == elem)
    return 1;

  int res = busca(A->esq, elem);
  if (res == 1)
    return 1;

  res = busca(A->dir, elem);
  if (res == 1)
    return 1;

  return 0;
}
