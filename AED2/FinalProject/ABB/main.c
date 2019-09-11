#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ABB.h"

int main()
{
  struct registro A, B, C, D, E, F, G, H;
  struct registro L, M, N, O, P, Q, R;

  char s1[] = "A", s2[] = "B";
  A.idade = 14;
  B.idade = 25;
  C.idade = 10;
  D.idade = 5;
  E.idade = 8;
  F.idade = 9;
  G.idade = 30;
  H.idade = 37;

  L.idade = 3;
  M.idade = 4;
  N.idade = 5;
  O.idade = 6;
  P.idade = 10;
  Q.idade = 8;
  R.idade = 9;

  Arv arvore = cria_vazia(), arvore2 = cria_vazia();
  insere_ord(&arvore, A);
  insere_ord(&arvore, B);
  insere_ord(&arvore, C);
  insere_ord(&arvore, D);
  insere_ord(&arvore, E);
  insere_ord(&arvore, F);
  insere_ord(&arvore, G);
  insere_ord(&arvore, H);

  insere_ord(&arvore2, N);
  insere_ord(&arvore2, M);
  insere_ord(&arvore2, O);
  insere_ord(&arvore2, L);
  insere_ord(&arvore2, P);
  insere_ord(&arvore2, Q);
  insere_ord(&arvore2, R);

  int escolha;

  while(escolha != 5)
  {
    printf("A arvore ordenada eh: ");
    exibe_ordenado(arvore);
    printf("\n");
    printf("1 - Retornar o aluno mais velho cadastrado\n");
    printf("2 - Retornar a quantidade de alunos maiores de idade\n");
    printf("3 - Retornar a quantidade de alunos em um intervalo\n");
    printf("4 - Juntar duas arvores\n");
    printf("5 - Sair\n");
    scanf("%d", &escolha);

    int res2, ini, fim;
    struct registro*res;
    switch(escolha){
      case 1:
        res = maior(arvore);
        printf("O aluno mais velho tem %d\n\n", (*res).idade);
        break;
      case 2:
        res2 = de_maior(arvore);
        printf("A quantidade de alunos é maiores de idade eh %d\n\n", res2);
        break;
      case 3:
        printf("Digite o inicio do intervalo: ");
        scanf("%d", &ini);
        printf("Digite o fim do intervalo: ");
        scanf("%d", &fim);
        res2 = qtde_nos(arvore, ini, fim);
        printf("A quantidade de alunos neste intervalo eh %d\n\n", res2);
        break;
      case 4:
        printf("Primeira arvore ordenada: ");
        exibe_ordenado(arvore);
        printf("\n");
        printf("Segunda arvore ordenada: ");
        exibe_ordenado(arvore2);
        printf("\n");
        Arv arvore3 = juntar(arvore, arvore2);
        printf("Juncao das arvores: ");
        exibe_ordenado(arvore3);
        printf("\n\n");
        break;
    }
  }
  return 0;
}
