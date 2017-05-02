#include <stdio.h>
#include <stdlib.h>
#include "ABB.h"

struct registro{
  int chave;
  char nome[30];
  int idade;
};

struct no{
  reg info;
  struct no*sae;
  struct no*sad;
};

Arv cria_vazia()
{
  return NULL;
}

Arv cria_arvore(reg elem, Arv esq, Arv dir)
{
  Arv novo = (Arv)malloc(sizeof(Arv));

  if (novo == NULL)
    return NULL;

  novo->info = elem;
  novo->sae = esq;
  novo->sad = dir;

  return novo;
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

void exibe_arvore(Arv A)
{
  if (A == NULL)
    printf("<>");

  printf("<");

  printf("%d", A->info.chave);
  exibe_arvore(A->sae);
  exibe_arvore(A->sad);

  printf(">");
}

void exibe_ordenado(Arv A)
{
  if (A != NULL)
  {
    exibe_ordenado(A->sae);
    printf("%d", A->info.chave);
    exibe_ordenado(A->sad);
  }
}

int insere_ord(Arv *A, reg elem)
{
  if (A == NULL)
    return 0;

  if (*A == NULL)
  {
    Arv novo = (Arv)malloc(sizeof(Arv));
    if (novo == NULL)
      return 0;

    novo->info = elem;
    novo->sae = NULL;
    novo->sad = NULL;
    *A = novo;
    return 1;
  }

  if (elem > reg.info)
    return insere_ord(&(*A)->sad, elem);
  else
    return insere_ord(&(*A)->sae, elem);
}

int remove_ord(Arv *A, int chave)
{
  if (A == NULL || (*A) == NULL)
    return 0;

  if (chave > (*A)->info.chave)
    remove_ord(&(*A)->sad, chave);
  else if (chave < (*A)->info.chave)
    remove_ord(&(*A)->sae, chave);
  else
  {
    if ((*A)->sae == NULL && (*A)->sad == NULL) //Nó folha
    {
      free(*A);
      A = NULL;
      return 1;
    }
    else if ((*A)->sae != NULL && (*A)->sad == NULL) //Nó com 1 filho a esquerda
    {
      Arv aux = (*A);
      *A = &aux->sae;
      free(aux);
      return 1;
    }
    else if ((*A)->sae == NULL && (*A)->sad != NULL) //Nó com 1 filho a direita
    {
      Arv aux = (*A);
      *A = &aux->sad;
      free(aux);
      return 1;
    }
    else //Nó com 2 filhos
    {
      Arv aux = (*A)->sae;

      while(aux->sad != NULL)
      {
        aux = aux->sad;
      }

      reg temp = (*A)->info;
      (*A)->info = aux->info;
      aux->info = temp;
      return remove_ord(&(*A)->sae, chave);
    }

  }
}

Arv busca_bin(Arv A, int chave)
{
  if (A == NULL)
    return NULL;

  if (A->info.chave == chave)
    return A;
  else if (chave > A->info.chave)
    return busca_bin(A->sad, chave);
  else
    return busca_bin(A->sae, chave);
}
