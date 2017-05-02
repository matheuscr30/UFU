#include <stdio.h>
#include <stdlib.h>
#include "ABB.h"

Arv cria_vazia()
{
  return NULL;
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

  printf("%d", A->info.idade);
  exibe_arvore(A->sae);
  exibe_arvore(A->sad);

  printf(">");
}

void exibe_ordenado(Arv A)
{
  if (A != NULL)
  {
    exibe_ordenado(A->sae);
    printf("%d ", A->info.idade);
    exibe_ordenado(A->sad);
  }
}

int insere_ord(Arv *A, reg elem)
{
  if (A == NULL)
    return 0;


  if (*A == NULL)
  {
    Arv novo = (Arv)malloc(sizeof(struct no));
    if (novo == NULL)
      return 0;

    novo->info = elem;
    novo->sae = NULL;
    novo->sad = NULL;
    *A = novo;
    return 1;
  }


  if (elem.idade > (*A)->info.idade)
    return insere_ord(&(*A)->sad, elem);
  else
    return insere_ord(&(*A)->sae, elem);
}

int remove_ord(Arv *A, int idade)
{
  if (A == NULL || (*A) == NULL)
    return 0;

  if (idade > (*A)->info.idade)
    remove_ord(&(*A)->sad, idade);
  else if (idade < (*A)->info.idade)
    remove_ord(&(*A)->sae, idade);
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
      A = &aux->sae;
      free(aux);
      return 1;
    }
    else if ((*A)->sae == NULL && (*A)->sad != NULL) //Nó com 1 filho a direita
    {
      Arv aux = (*A);
      A = &aux->sad;
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
      return remove_ord(&(*A)->sae, idade);
    }

  }
}

Arv busca_bin(Arv A, int idade)
{
  if (A == NULL)
    return NULL;

  if (A->info.idade == idade)
    return A;
  else if (idade > A->info.idade)
    return busca_bin(A->sad, idade);
  else
    return busca_bin(A->sae, idade);
}

reg* maior(Arv A){
  if (A == NULL) return NULL;
  else if (A->sae == NULL && A->sad == NULL) return &A->info;
  else if (A->sae != NULL && A->sad == NULL) return &A->info;
  else if (A->sae == NULL && A->sad != NULL) return maior(A->sad);
  else
  {
    return maior(A->sad);
  }
}

int de_maior(Arv A){
  if (A == NULL) return 0;
  else if (A->sae == NULL && A->sad == NULL){
    if (A->info.idade >= 18) return 1;
    else return 0;
  }
  else if (A->sae != NULL && A->sad == NULL)
  {
    if (A->info.idade >= 18) return 1 + de_maior(A->sae);
    else return de_maior(A->sae);
  }
  else if (A->sae == NULL && A->sad != NULL)
  {
    if (A->info.idade >= 18) return 1 + de_maior(A->sad);
    else return de_maior(A->sad);
  }
  else{
    if (A->info.idade >= 18) return 1 + de_maior(A->sae) + de_maior(A->sad);
    else return de_maior(A->sae) + de_maior(A->sad);
  }
}

int qtde_nos(Arv A, int ini, int fim){
  if (A == NULL) return 0;
  else if (A->sae == NULL && A->sad == NULL){
    if (A->info.idade >= ini && A->info.idade <= fim) return 1;
    else return 0;
  }
  else if (A->sae != NULL && A->sad == NULL)
  {
    if (A->info.idade >= ini && A->info.idade <= fim) return 1 + qtde_nos(A->sae, ini, fim);
    else return qtde_nos(A->sae, ini, fim);
  }
  else if (A->sae == NULL && A->sad != NULL)
  {
    if (A->info.idade >= ini && A->info.idade <= fim) return 1 + qtde_nos(A->sad, ini, fim);
    else return qtde_nos(A->sad, ini, fim);
  }
  else{
    if (A->info.idade >= ini && A->info.idade <= fim) return 1 + qtde_nos(A->sae, ini, fim) + qtde_nos(A->sad, ini, fim);
    else return qtde_nos(A->sae, ini, fim) + qtde_nos(A->sad, ini, fim);
  }
}

void juntarAux(Arv A, Arv A2){
  if (A == NULL) return;
  else if (A->sae == NULL && A->sad == NULL) insere_ord(&A2, A->info);
  else if (A->sae != NULL && A->sad == NULL){
    insere_ord(&A2, A->info);
    juntarAux(A->sae, A2);
  }
  else if (A->sae == NULL && A->sad != NULL){
    insere_ord(&A2, A->info);
    juntarAux(A->sad, A2);
  }
  else{
    insere_ord(&A2, A->info);
    juntarAux(A->sae, A2);
    juntarAux(A->sad, A2);
  }
}

Arv juntar(Arv A1, Arv A2){
  juntarAux(A1, A2);
  return A2;
}
