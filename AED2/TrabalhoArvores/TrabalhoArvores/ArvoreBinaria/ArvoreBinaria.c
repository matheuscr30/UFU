#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArvoreBinaria.h"
#include "Fila.h"

Arv cria_vazia(){
  return NULL;
}

Arv cria_arvore(char elem, Arv esq, Arv dir){
  Arv novo = (Arv)malloc(sizeof(Arv));

  if (novo == NULL)
    return NULL;

  novo->info = elem;
  novo->sae = esq;
  novo->sad = dir;

  return novo;
}

int arvore_vazia(Arv A){
  if (A == NULL)
    return 1;
  else
    return 0;
}

void libera_arvore(Arv *A){
  if (A != NULL)
  {
    libera_arvore(&(*A)->sae);
    libera_arvore(&(*A)->sad);
    free(*A);
  }

  A = NULL;
}

Arv busca(Arv A, char elem){
  if (A == NULL)
    return NULL;

  if(A->info == elem)
    return A;

  Arv res = busca(A->sae, elem);
  if (res != NULL)
    return res;

  res = busca(A->sad, elem);
  if (res != NULL)
    return res;

  return NULL;
}

int remove_folha(Arv *A, char elem){
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

void exibe_arvore(Arv A){
  if (A == NULL){
    printf("<>");
    return;
  }

  printf("<");

  printf("%c", A->info);
  exibe_arvore(A->sae);
  exibe_arvore(A->sad);

  printf(">");
}

void preorder(Arv A){
  if (A == NULL){
    printf("<>");
    return;
  }

    printf("<");

    printf("%c", A->info);
    preorder(A->sae);
    preorder(A->sad);

    printf(">");
}

void postorder(Arv A){
  if (A == NULL)
  {
    printf("<>");
    return;
  }
    printf("<");

    postorder(A->sae);
    postorder(A->sad);
    printf("%c", A->info);

    printf(">");
}

void inorder(Arv A){
  if (A == NULL){
    printf("<>");
    return;
  }

    printf("<");

    inorder(A->sae);
    printf("%c", A->info);
    inorder(A->sad);

    printf(">");
}

void percorre_nivel(Arv A){
  char car;
  TipoFila fila;
  FFVazia(&fila);
  int *visitados = (int*)calloc(sizeof(int),30), num;
  Enfileira(A->info, &fila);

  while(!Vazia(fila))
  {
    Desenfileira(&fila, &car);

    visitados[(int)car -'a'] = 1;

    Arv novo = busca(A, car);
    if (novo == NULL) return;

    printf("%c", novo->info);

    if (novo->sae != NULL && visitados[(int)novo->sae->info - 'a'] == 0)
    {
      Enfileira(novo->sae->info, &fila);
      visitados[(int)novo->sae->info - 'a'] = 1;
    }

    if (novo->sad != NULL && visitados[(int)novo->sad->info - 'a'] == 0)
    {
      Enfileira(novo->sad->info, &fila);
      visitados[(int)novo->sad->info - 'a'] = 1;
    }
  }
}

void gera_notacao_aux(Arv A, char *S, int* n){
  if (A == NULL){
    S[*n] = '<';
    (*n)++;
    S[*n] = '>';
    return;
  }

  S[*n] = '<';
  (*n)++;

  S[*n] = A->info;
  (*n)++;
  gera_notacao_aux(A->sae, S, n);
  (*n)++;
  gera_notacao_aux(A->sad, S, n);
  (*n)++;

  S[*n] = '>';
}

int gera_notacao(Arv A, char *S){
  if (A == NULL) return 0;

  int n = 0;
  gera_notacao_aux(A, S, &n);
  return 1;
}

int nro_folha(Arv A){
    if (A == NULL) return 0;
    else if (A->sae == NULL && A->sad == NULL) return 1;
    else if(A->sae == NULL && A->sad != NULL)  return nro_folha(A->sad);
    else if (A->sae != NULL && A->sad == NULL) return nro_folha(A->sae);
    else
    {
      int res = nro_folha(A->sae);
      return res + nro_folha(A->sad);
    }
}

int nro_derivacao(Arv A){
  if (A == NULL) return 0;
  else if (A->sae == NULL && A->sad == NULL) return 0;
  else if(A->sae == NULL && A->sad != NULL)  return 1+nro_derivacao(A->sad);
  else if (A->sae != NULL && A->sad == NULL) return 1+nro_derivacao(A->sae);
  else
  {
    int res = 1+nro_derivacao(A->sae);
    return res + nro_derivacao(A->sad);
  }
}

int um_filho(Arv A){
  if (A == NULL) return 0;
  else if (A->sae == NULL && A->sad == NULL) return 0;
  else if(A->sae == NULL && A->sad != NULL)  return 1+um_filho(A->sad);
  else if (A->sae != NULL && A->sad == NULL) return 1+um_filho(A->sae);
  else
  {
    int res = um_filho(A->sae);
    return res + um_filho(A->sad);
  }
}

int cheia(Arv A){
  if (A == NULL) return 0;
  else if (A->sae == NULL && A->sad == NULL) return 1;
  else if(A->sae == NULL && A->sad != NULL)  return 0;
  else if (A->sae != NULL && A->sad == NULL) return 0;
  else
  {
    int res = cheia(A->sae);
    return res && cheia(A->sad);
  }
}

int nivel_no(Arv A, char elem){
  return anivel_no(A, elem)-1;
}

int anivel_no(Arv A, char elem){
  if (A == NULL) return 0;
  else if (A->info == elem) return 1;
  else if (A->sae == NULL && A->sad == NULL) return 0;
  else if(A->sae == NULL && A->sad != NULL)
  {
    if (anivel_no(A->sad, elem) >= 1)
      return 1 + anivel_no(A->sad, elem);
    else
      return anivel_no(A->sad, elem);
  }
  else if (A->sae != NULL && A->sad == NULL)
  {
    if (anivel_no(A->sae, elem) >= 1)
      return 1 + anivel_no(A->sae, elem);
    else
      return anivel_no(A->sae, elem);
  }
  else
  {
    int res = anivel_no(A->sae, elem);
    if (res >= 1) res++;

    int res2 = anivel_no(A->sad, elem);
    if (res2 >= 1) res2++;

    return res+res2;
  }
}

int valida(Arv A, Arv B){
  return A->info == B->info;
}

int iguais(Arv A, Arv B){
  if (A->sae == NULL && B->sae == NULL && A->sad == NULL && B->sad == NULL && valida(A, B)) return 1;
  else if(A->sae == NULL && B->sae == NULL && A->sad != NULL && B->sad != NULL && valida(A, B)) return 1 && iguais(A->sad, B->sad);
  else if (A->sae != NULL && B->sae != NULL && A->sad == NULL && B->sad == NULL && valida(A, B)) return 1 && iguais(A->sae, B->sae);
  else if (A->sae != NULL && B->sae != NULL && A->sad != NULL && B->sad != NULL && valida(A, B))
  {
    int res = 1 && iguais(A->sae, B->sae);
    int res2 = 1 && iguais(A->sad, B->sad);
    return res && res2;
  }
  else return 0;
}

int altura_arv(Arv A){
  return altura_no(A, A->info);
}

int altura_no(Arv A, char elem){
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
int carrega_aux(Arv* A,char* S,int* n){
	if(S[(*n)] == '<'){	// Raiz
		(*n)++;
		if(S[(*n)]=='<'){
			return -1;
		}
		else if(S[(*n)]!='>'){
			(*A) = cria_arvore(S[(*n)],NULL,NULL);
			(*n)++;
			if((S[(*n)]!='<' || carrega_aux(&(*A)->sae,S,n)==-1
				|| carrega_aux(&(*A)->sad,S,n)==-1) && S[(*n)]!='\0'){
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
	if(a==b && S[n]=='<' && carrega_aux(A,S,&n)==-1){
		libera_arvore(A);
		return 0;
	}
	else{
		return 1;
	}
}
