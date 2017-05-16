#include <stdio.h>
#include <stdlib.h>
#include "ArvoreGenerica.h"

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

int altura_no_aux(Arv A){
  if (A == NULL) return 0;
  else if (A->esq == NULL && A->dir == NULL) return 1;
  else if (A->esq == NULL && A->dir != NULL)
  {
    return altura_no_aux(A->dir);
  }
  else if (A->esq != NULL && A->dir == NULL) return 1 + altura_no_aux(A->esq);
  else
  {
    int res = altura_no_aux(A->esq);
    int res2 = altura_no_aux(A->dir);

    if (res > res2) return res+1;
    else res2;
  }
}

int altura_no(Arv A, int elem){
  Arv B = busca(A, elem);

  if (B == NULL) return -1;
  return altura_no_aux(B)-1;
}

int altura_arv(Arv A){
  return altura_no_aux(A)-1;
}
