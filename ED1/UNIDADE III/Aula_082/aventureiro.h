#ifndef AVENTUREIRO_H
#define AVENTUREIRO_H

//Cada aventureiro deve ser representado por uma struct contendo um ID (inteiro) e um nome (string).
typedef struct {
    int id;
    char nome[50];
} Aventureiro;

typedef struct no {
    Aventureiro dado;
    struct no* proximo;
} No;

typedef struct {
    No* inicio;
} ListaAventureiros;

void inicializa_lista(ListaAventureiros* l);
void adicionar_aventureiro(ListaAventureiros* l, int id, const char* nome);
void mostrar_grupo(const ListaAventureiros* l);
void libera_lista(ListaAventureiros* l);

#endif //AVENTUREIRO_H