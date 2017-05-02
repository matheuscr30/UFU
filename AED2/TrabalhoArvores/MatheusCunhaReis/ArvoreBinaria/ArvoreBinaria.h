typedef struct no *Arv;

Arv cria_arvore(int elem, Arv esq, Arv dir);
Arv cria_vazia();
int remove_folha(Arv *A, int elem);
void libera_arvore(Arv *A);
void exibe_arvore(Arv A);
int arvore_vazia(Arv A);
int busca(Arv a, int elem);
int altura_arv(Arv A);
int altura_no(Arv A, int elem);
int altura_noaux(Arv A);
