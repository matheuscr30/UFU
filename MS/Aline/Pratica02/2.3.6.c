#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define MODULUS    2147483647 /* DON'T CHANGE THIS VALUE                  */
#define MULTIPLIER 48271      /* DON'T CHANGE THIS VALUE                  */
#define CHECK      399268537  /* DON'T CHANGE THIS VALUE                  */
#define STREAMS    256        /* # of streams, DON'T CHANGE THIS VALUE    */
#define A256       22925      /* jump multiplier, DON'T CHANGE THIS VALUE */
#define DEFAULT    123456789  /* initial seed, use 0 < DEFAULT < MODULUS  */

static long seed[STREAMS] = {DEFAULT};  /* current state of each stream   */
static int  stream        = 0;          /* stream index, 0 is the default */
static int  initialized   = 0;          /* test for stream initialization */

double Random(void)
/* ----------------------------------------------------------------
 * Random returns a pseudo-random real number uniformly distributed
 * between 0.0 and 1.0.
 * ----------------------------------------------------------------
 */
{
  const long Q = MODULUS / MULTIPLIER;
  const long R = MODULUS % MULTIPLIER;
        long t;

  t = MULTIPLIER * (seed[stream] % Q) - R * (seed[stream] / Q);
  if (t > 0)
    seed[stream] = t;
  else
    seed[stream] = t + MODULUS;
  return ((double) seed[stream] / MODULUS);
}

void PutSeed(long x)
/* ---------------------------------------------------------------
 * Use this function to set the state of the current random number
 * generator stream according to the following conventions:
 *    if x > 0 then x is the state (unless too large)
 *    if x < 0 then the state is obtained from the system clock
 *    if x = 0 then the state is to be supplied interactively
 * ---------------------------------------------------------------
 */
{
  char ok = 0;

  if (x > 0)
    x = x % MODULUS;                       /* correct if x is too large  */
  if (x < 0)
    x = ((unsigned long) time((time_t *) NULL)) % MODULUS;
  if (x == 0)
    while (!ok) {
      printf("\nEnter a positive integer seed (9 digits or less) >> ");
      scanf("%ld", &x);
      ok = (0 < x) && (x < MODULUS);
      if (!ok)
        printf("\nInput out of range ... try again\n");
    }
  seed[stream] = x;
}

void GetSeed(long *x)
/* ---------------------------------------------------------------
 * Use this function to get the state of the current random number
 * generator stream.
 * ---------------------------------------------------------------
 */
{
  *x = seed[stream];
}

long Equilikely(long a, long b){
    return (a + (long) ((b - a + 1) * Random()));
}

double Games (long N, long win)
{
    int i, roll, wins = 0;

    for (i=1; i<N; i++){
        roll = Equilikely(1,6) + Equilikely(1,6) + Equilikely(1,6);
        if(roll == win)
            wins++;
    }

    double result = wins;
    result /= N;

    return result;
}

int main()
{
    FILE *arq;
    int i, seed, N;
    char nome[20];

    int seeds[] = {12345, 54321, 2121212};

    for(i=0; i<3; i++)
    {
        PutSeed(seeds[i]);
        sprintf(nome, "%d", seeds[i]);
        strcat(nome, ".csv");
        arq = fopen(nome, "w");

        for(N=20; N<=1000; N+=20)
        {
            fprintf(arq, "%d,%f\n", N, Games(N, 9));
        }
    }

    fclose(arq);

    return 0;
}
