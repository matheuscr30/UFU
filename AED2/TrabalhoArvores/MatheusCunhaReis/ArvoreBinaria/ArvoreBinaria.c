#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

struct no{
  int info;
  struct no*sae;
  struct no*sad;
};

Arv cria_vazia()
{
  return NULL;
}

Arv cria_arvore(int elem, Arv esq, Arv dir)
{
  Arv novo = (Arv)malloc(sizeof(Arv));

  if (novo == NULL)
    return NULL;

  novo->info = elem;
  novo->sae = esq;
  novo->sad = dir;

  return novo;
}

int arvore_vazia(Arv A)
{
  if (A == NULL)
    return 1;
  else
    return 0;
}

void libera_arvore(Arv *A)
{
  if (A != NULL)
  {
    libera_arvore(&(*A)->sae);
    libera_arvore(&(*A)->sad);
    free(*A);
  }

  A = NULL;
}

int busca(Arv A, int elem)
{
  if (A == NULL)
    return 0;

  if(A->info == elem)
    return 1;

  int res = busca(A->sae, elem);
  if (res == 1)
    return 1;

  res = busca(A->sad, elem);
  if (res == 1)
    return 1;

  return 0;
}

int remove_folha(Arv *A, int elem)
{
  if (A == NULL)
    return 0;

  if ((*A)->info == elem)
  {
    if ((*A)->sae == NULL && (*A)->sad == NULL)
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
    int res = remove_folha(&(*A)->sae, elem);
    if (res == 1)
      return 1;

    res = remove_folha(&(*A)->sad, elem);
    if (res == 1)
      return 1;
  }

  return 0;
}

void exibe_arvore(Arv A)
{
  if (A == NULL)
    printf("<>");

  printf("<");

  printf("%d", A->info);
  exibe_arvore(A->sae);
  exibe_arvore(A->sad);

  printf(">");
}

int altura_arv(Arv A){
  return altura_no(A, A->info);
}

int altura_no(Arv A, int elem){
  Arv achou = busca(A, elem);

  if (achou == NULL) return -1;

  return altura_noaux(achou)-1;
}

int altura_noaux(Arv A){
  if (A == NULL) return 0;
  else if (A->sae == NULL && A->sad == NULL) return 1;
  else if(A->sae == NULL && A->sad != NULL)  return 1 + altura_noaux(A->sad);
  else if (A->sae != NULL && A->sad == NULL) return 1 + altura_noaux(A->sae);
  else
  {
    int res = altura_noaux(A->sae);
    int res2 = altura_noaux(A->sad);

    if (res > res2) return res+1;
    else return res2+1;
  }
}
