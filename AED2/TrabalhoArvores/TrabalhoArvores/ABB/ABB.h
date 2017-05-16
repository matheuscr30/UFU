struct registro{
  char nome[50];
  int idade;
  char curso[100];
};
typedef struct registro reg;

struct no{
  reg info;
  struct no*sae;
  struct no*sad;
};
typedef struct no *Arv;

Arv cria_vazia();
void libera_arvore(Arv *A);
void exibe_arvore(Arv A);
void exibe_ordenado(Arv A);
int insere_ord(Arv *A, reg elem);
int remove_ord(Arv *A, int idade);
Arv busca_bin(Arv A, int idade);
reg* maior(Arv A);
int de_maior(Arv A);
int qtde_nos(Arv A, int ini, int fim);
void juntarAux(Arv A, Arv A2);
Arv juntar(Arv A1, Arv A2);
