#include <stdio.h>
#include <stdlib.h>
#include "ArvoreGenerica.h"
#include "Fila.h"

int main()
{
  Arv arvore;
  int elem;
  int condicao = 0, escolha, res, g;
  char *string = (char*)malloc(sizeof(char) * 150);
  while(condicao == 0)
  {
    printf("EH NECESSARIO CARREGAR A ARVORE ANTES\n");
    printf("O que deseja fazer:\n");
    printf("1 - Percorrer a arvore em pre ordem\n");
    printf("2 - Percorrer a arvore em pos ordem\n");
    printf("3 - Pecorrer a arvore por nivel\n");
    printf("4 - Carregar a arvore\n");
    printf("5 - Gerar notacao\n");
    printf("6 - Verificar a quantidade de nos folhas\n");
    printf("7 - Retornar o grau da arvore\n");
    printf("8 - Retornar a quantidade de nos que tem um certo grau\n");
    printf("9 - Verificar a altura da arvore\n");
    printf("10 - Verificar a altura de um certo no\n");
    printf("11 - Sair\n");
    scanf("%d", &escolha);

    switch(escolha){
      case 1:
        preorder(arvore);
        break;
      case 2:
        postorder(arvore);
        break;
      case 3:
        percorre_nivel(arvore);
        break;
      case 4:
        printf("Digite a string que deseja carregar: ");
        scanf("%s", string);
        carrega_arvore(&arvore, string);
        break;
      case 5:
        gera_notacao(arvore,string);
        printf("%s\n", string);
        break;
      case 6:
        res = nro_folha(arvore);
        printf("O numero de no folhas eh %d\n", res);
        break;
      case 7:
        res = grau_arv(arvore);
        printf("O grau da arvore eh %d\n", res);
        break;
      case 8:
        printf("Digite o grau desejado: ");
        scanf("%d", &g);
        res = qtde_nos(arvore, g);
        printf("O numero de nos com grau %d eh %d\n", g, res);
        break;
      case 9:
        res = altura_arv(arvore);
        printf("A altura da arvore eh %d\n", res);
        break;
      case 10:
        printf("Digite o numero do no que deseja descobrir a altura: ");
        scanf("%d", &g);
        res = altura_no(arvore, g);
        printf("A altura do no %d eh %d\n", g, res);
        break;
      case 11:
        return 0;
        break;
    }

  }
}
