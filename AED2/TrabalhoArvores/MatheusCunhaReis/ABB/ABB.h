typedef struct registro reg;
typedef struct no *Arv;

Arv cria_vazia();
Arv cria_arvore(reg elem, Arv esq, Arv dir);
void libera_arvore(Arv *A);
void exibe_arvore(Arv A);
void exibe_ordenado(Arv A);
int insere_ord(Arv *A, reg elem);
int remove_ord(Arv *A, int chave);
Arv busca_bin(Arv A, int chave);
