// www.GeeksBR.com

/*Programa que recebe dois números, informa se eles são primos entre si, o
  MDC e o MMC com base no algoritmo de Euclides*/

/*O algoritmo de Euclides para determinar o MDC (Máximo Divisor
Comum) entre dois números inteiros, consiste em formar uma seqüência de números
inteiros cujos dois primeiros elementos são os números dados. Cada elemento seguinte
da sequência corresponde ao resto da divisão dos dois números anteriores. A seqüência
terminará quando um elemento da mesma for nulo.*/

/*A partir desta sequência, o MDC é definido exatamente pelo elemento anterior ao elemento
nulo. Como exemplo, dados os números inteiros 12 e 15, será formada a seqüência:
12, 15, 12, 3, 0 e o MDC entre 12 e 15 é 3.*/

/*Dois números são primos entre si quando o único divisor comum entre os dois
  é 1, portanto esse será o MDC e o MMC será a multiplicação entre os dois
  números. Ex.: 20 e 21 são primos entre si cujo MDC é 1 e o MMC é 20*21 = 420*/

/*Dados dois números a e b, o MMC pode ser calculado usando o MDC através da
  relação: MMC(a,b)*MDC(a,b) = a*b */

#include <stdio.h>
#include <conio.h>


int calculaMDC(int n1, int n2){
      int maior, menor, MDC, resto;
  if(n1>n2)
  {
    maior = n1;
    menor = n2;
  }else{
    maior = n2;
    menor = n1;
  }
  do {
    resto = maior%menor;
    if(resto==0 || resto==1)
    {
      if(resto==1) MDC = 1;
      if(resto==0) MDC = menor;
      break;
    } else {
      maior = menor;
      menor = resto;
    }
  }while(resto!=0 || resto!=1);
  return MDC;
}

int main() {
      int n1, n2, MDC, cont=0;
      n1 = 2147483646;
      n2 = 1;
      printf("\nPrimos relativos a %d no intervalo i de 1 a 100: \n", n1);
      while(n2 < 100){
          if(n1!=n2)
          {
            MDC = calculaMDC(n1, n2);
            if(MDC==1){
                    printf("%5d ", n2);
                    cont++;
                    if(cont % 12 == 0){
                        printf("\n");
                    }
                }
          }
          n2++;
      }
  return 0;
}
