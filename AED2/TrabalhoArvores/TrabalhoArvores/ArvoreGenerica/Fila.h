typedef struct TipoCelula *TipoApontador;
typedef struct TipoCelula TipoCelula;

typedef struct TipoFila {
  TipoApontador Frente, Tras;
} TipoFila;

void FFVazia(TipoFila *Fila);
int Vazia(TipoFila Fila);
void Enfileira(int x, TipoFila *Fila);
void Desenfileira(TipoFila *Fila, int *Item);
void Imprime(TipoFila Fila);
