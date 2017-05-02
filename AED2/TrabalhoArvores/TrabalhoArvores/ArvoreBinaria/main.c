#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"
#include "Fila.h"

int main()
{
  Arv arvore, arvore2;
  char elem;
  int condicao = 0, escolha, tipoarv, res;
  char *string = (char*)malloc(sizeof(char) * 150);
  while(condicao == 0)
  {
    printf("O que deseja fazer:\n");
    printf("1 - Percorrer a arvore em pre ordem\n");
    printf("2 - Percorrer a arvore em pos ordem\n");
    printf("3 - Percorrer a arvore em in ordem\n");
    printf("4 - Pecorrer a arvore por nivel\n");
    printf("5 - Carregar a arvore\n");
    printf("6 - Gerar notacao\n");
    printf("7 - Verificar a quantidade de nos folhas\n");
    printf("8 - Verificar a quantidade de nos de derivacao\n");
    printf("9 - Verificar a quantidade de nos que tem so um filho\n");
    printf("10 - Verificar se a arvore é cheia\n");
    printf("11 - Retornar o nivel de um no\n");
    printf("12 - Comparar duas arvores binarias\n");
    printf("13 - Verificar a altura da arvore\n");
    printf("14 - Verificar a altura de um certo no\n");
    printf("15 - Sair\n");
    scanf("%d", &escolha);
    printf("Arvore 1 ou 2: ");
    scanf("%d", &tipoarv);

    switch (escolha){
      case 1:
        if (tipoarv == 1) preorder(arvore);
        else preorder(arvore2);
        break;
      case 2:
        if (tipoarv == 1) postorder(arvore);
        else postorder(arvore2);
        break;
      case 3:
        if (tipoarv == 1) inorder(arvore);
        else inorder(arvore2);
        break;
      case 4:
        if (tipoarv == 1) percorre_nivel(arvore);
        else percorre_nivel(arvore2);
        break;
      case 5:
        printf("Escreva a sequencia da arvore: ");
        scanf("%s", string);
        if (tipoarv == 1) carrega_arvore(&arvore, string);
        else carrega_arvore(&arvore2, string);
        break;
      case 6:
        string[0] = '\0';
        if (tipoarv == 1) gera_notacao(arvore, string);
        else gera_notacao(arvore2, string);
        break;
      case 7:
        if (tipoarv == 1) res = nro_folha(arvore);
        else res = nro_folha(arvore2);
        printf("A arvore tem %d no(s) folha(s)\n", res);
        break;
      case 8:
        if (tipoarv == 1) res = nro_derivacao(arvore);
        else res = nro_derivacao(arvore2);
        printf("A arvore tem %d no(s) de derivacao\n", res);
        break;
      case 9:
        if (tipoarv == 1) res = um_filho(arvore);
        else res = um_filho(arvore2);
        printf("A arvore tem %d no(s) que possuem somente um filho\n", res);
        break;
      case 10:
        if (tipoarv == 1) res = cheia(arvore);
        else res = cheia(arvore2);
        if (cheia)
          printf("A arvore eh cheia\n");
        else
          printf("A arvore nao eh cheias\n");
        break;
      case 11:
        printf("Digite o elemento que deseja saber a altura: ");
        scanf("%c", &elem);
        if (tipoarv == 1) res = nivel_no(arvore, elem);
        else res = nivel_no(arvore, elem);
        printf("O elemento %c tem altura %d\n", elem, res);
        break;
      case 12:
        res = iguais(arvore, arvore2);
        if (res == 1)
          printf("As arvores sao iguaisn\n");
        else
          printf("As arvores nao sao iguais\n");
        break;
      case 13:
        if (tipoarv == 1) res = altura_arv(arvore);
        else res = altura_arv(arvore2);
        printf("A altura da arvore eh %d\n", res);
        break;
      case 14:
        printf("Digite o elemento que deseja saber a altura: ");
        scanf("%c", &elem);
        if (tipoarv == 1) res = altura_no(arvore, elem);
        else res = altura_no(arvore2, elem);
        printf("A altura do no %d eh %d\n", elem, res);
        break;
      case 15:
        return 0;
        break;

    }

  }
}
