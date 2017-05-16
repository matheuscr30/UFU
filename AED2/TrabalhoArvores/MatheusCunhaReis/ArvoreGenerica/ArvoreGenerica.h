typedef struct no *Arv;

Arv cria_arvore(int elem);
int insere(Arv A, Arv sa);
int remove_folha(Arv *A, int elem);
void libera_arvore(Arv *A);
void exibe_arvore(Arv A);
int busca(Arv A, int elem);
int altura_no_aux(Arv A);
int altura_no(Arv A, int elem);
int altura_arv(Arv A);
