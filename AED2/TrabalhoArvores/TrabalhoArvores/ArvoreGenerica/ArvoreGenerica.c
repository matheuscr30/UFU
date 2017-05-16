#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArvoreGenerica.h"
#include "Fila.h"

struct no{
  int info;
  struct no*esq;
  struct no*dir;
};

Arv cria_arvore(int elem){
  Arv novo = (Arv)malloc(sizeof(Arv));

  if (novo == NULL)
    return NULL;

  novo->info = elem;
  novo->esq = NULL;
  novo->dir = NULL;

  return novo;
}

int insere(Arv A, Arv sa){
  if (A == NULL)
    return 0;

  sa->dir = A->esq;
  A->esq = sa;

  return 1;
}

void libera_arvore(Arv *A){
  if (A != NULL)
  {
    libera_arvore(&(*A)->esq);
    libera_arvore(&(*A)->dir);
    free(*A);
  }

  A = NULL;
}

int remove_folha(Arv *A, int elem){
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

void exibe_arvore(Arv A){
  if (A != NULL)
  {
    printf("<");

    printf("%d", A->info);
    exibe_arvore(A->esq);
    printf(">");
    exibe_arvore(A->dir);
  }
}

Arv busca(Arv A, int elem){
  if (A == NULL)
    return NULL;

  if(A->info == elem)
    return A;

  Arv res;
  res = busca(A->esq, elem);
  if (res != NULL)
    return res;

  res = busca(A->dir, elem);
  if (res != NULL)
    return res;

  return NULL;
}

void preorder(Arv A){
  if (A == NULL)
    return;

    printf("<");

    printf("%d", A->info);
    preorder(A->esq);
    printf(">");
    preorder(A->dir);
}

void postorder(Arv A){
  if (A == NULL)
    return;

    printf("<");

    postorder(A->esq);
    printf("%d", A->info);
    printf(">");
    postorder(A->dir);


}

int nro_folha(Arv A){
  if (A == NULL) return 0;
  else if(A->esq == NULL && A->dir == NULL) return 1;
  else if(A->esq != NULL && A->dir == NULL) return nro_folha(A->esq);
  else if(A->esq == NULL && A->dir != NULL) return 1;
  else
  {
    int res = nro_folha(A->esq);
    res += nro_folha(A->dir);

    return res;
  }
}

int grau_no(Arv A){
  Arv aux = A->esq;
  if (aux == NULL) return 0;

  int cont = 1;
  while(aux->dir != NULL)
  {
    aux = aux->dir;
    cont++;
  }

  return cont;
}

int max (int a, int b){
  if (a > b) return a;
  else return b;
}

int grau_arv(Arv A){
  if (A == NULL) return 0;
  else if(A->esq == NULL && A->dir == NULL) return 0;
  else if(A->esq != NULL && A->dir == NULL)
  {
    int res = grau_no(A);
    int res2 = grau_arv(A->esq);

    if (res > res2) return res;
    else return res2;
  }
  else if(A->esq == NULL && A->dir != NULL)
  {
    return grau_arv(A->dir);
  }
  else
  {
    int res = grau_no(A);
    int res2 = grau_arv(A->esq);
    int res3 = grau_arv(A->dir);

    res = max(res, res2);
    res = max(res, res3);
    return res;
  }
}

int qtde_nos(Arv A, int grau){
  if (A == NULL) return 0;
  else if(A->esq == NULL && A->dir == NULL)
  {
    return (grau_no(A) == grau);
  }
  else if(A->esq == NULL && A->dir != NULL)
  {
    return qtde_nos(A->dir, grau) + (grau_no(A) == grau);
  }
  else if(A->esq != NULL && A->dir == NULL)
  {
    return qtde_nos(A->esq, grau) + (grau_no(A) == grau);
  }
  else
  {
    int res = 0;
    int g = grau_no(A);
    if (g == grau) res++;

    int res2 = qtde_nos(A->esq, grau);
    int res3 = qtde_nos(A->dir, grau);

    return res + res2 + res3;
  }
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

void percorre_nivel(Arv A){
  int car;
  TipoFila fila;
  FFVazia(&fila);
  int *visitados = (int*)calloc(sizeof(int),30);
  Enfileira(A->info, &fila);

  while(!Vazia(fila))
  {
    Desenfileira(&fila, &car);

    visitados[car] = 1;

    Arv novo = busca(A, car);
    if (novo == NULL) return;

    printf("%d", novo->info);

    if (novo->esq != NULL)
    {
      if (visitados[novo->esq->info] == 0){
        Enfileira(novo->esq->info, &fila);
        visitados[novo->esq->info] = 1;
      }

      Arv aux = novo->esq->dir;
      if (aux == NULL) continue;

      while(aux != NULL){
        Enfileira(aux->info, &fila);
        visitados[aux->info] = 1;
        aux = aux->dir;
      }
    }
  }
  printf("\n");
}

void gera_notacao_aux(Arv A, char *S, int* n){

  if (A != NULL){
    S[*n] = '<';
    (*n)++;

    S[*n] = itoa(A->info);
    (*n)++;
    gera_notacao_aux(A->esq, S, n);
    (*n)++;
    S[*n] = '>';
    (*n)++;
    gera_notacao_aux(A->dir, S, n);
  }
}

int gera_notacao(Arv A, char *S){
  if (A == NULL) return 0;

  int n = 0;
  gera_notacao_aux(A, S, &n);
  printf("\n");
  return 1;
}

int carrega_aux(Arv* A,char* S,int* n){
	if(S[(*n)] == '<'){	// Raiz
		(*n)++;
		if(S[(*n)]=='<'){
			return -1;
		}
		else if(S[(*n)]!='>'){
			(*A) = cria_arvore((int)S[(*n)]-'0');
			(*n)++;
			if(carrega_aux(&(*A)->esq,S,n)==-1){
				return -1;}
			(*n)++;
			if(carrega_aux(&(*A)->dir,S,n)==-1){
				return -1;}
			(*n)++;
		}
		else{
			(*n)++;
		}
	}
		return 1;
}

int carrega_arvore(Arv* A,char* S){
	int n =0,a=0,b=0;
	for(int i=0;i<strlen(S);i++){
		if(S[i]=='<')
			a++;
		else if(S[i]=='>')
			b++;
	}
	if(a==b && carrega_aux(A,S,&n)==-1){
		libera_arvore(A);
		return 0;
	}
	else{
		return 1;
	}
}
