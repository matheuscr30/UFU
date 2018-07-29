// www.GeeksBR.com

/*Programa que recebe dois n�meros, informa se eles s�o primos entre si, o
  MDC e o MMC com base no algoritmo de Euclides*/

/*O algoritmo de Euclides para determinar o MDC (M�ximo Divisor
Comum) entre dois n�meros inteiros, consiste em formar uma seq��ncia de n�meros
inteiros cujos dois primeiros elementos s�o os n�meros dados. Cada elemento seguinte
da sequ�ncia corresponde ao resto da divis�o dos dois n�meros anteriores. A seq��ncia
terminar� quando um elemento da mesma for nulo.*/

/*A partir desta sequ�ncia, o MDC � definido exatamente pelo elemento anterior ao elemento
nulo. Como exemplo, dados os n�meros inteiros 12 e 15, ser� formada a seq��ncia:
12, 15, 12, 3, 0 e o MDC entre 12 e 15 � 3.*/

/*Dois n�meros s�o primos entre si quando o �nico divisor comum entre os dois
  � 1, portanto esse ser� o MDC e o MMC ser� a multiplica��o entre os dois
  n�meros. Ex.: 20 e 21 s�o primos entre si cujo MDC � 1 e o MMC � 20*21 = 420*/

/*Dados dois n�meros a e b, o MMC pode ser calculado usando o MDC atrav�s da
  rela��o: MMC(a,b)*MDC(a,b) = a*b */

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
