typedef struct TipoCelula *TipoApontador;
typedef struct TipoCelula TipoCelula;

typedef struct TipoFila {
  TipoApontador Frente, Tras;
} TipoFila;

void FFVazia(TipoFila *Fila);
int Vazia(TipoFila Fila);
void Enfileira(char x, TipoFila *Fila);
void Desenfileira(TipoFila *Fila, char *Item);
void Imprime(TipoFila Fila);
