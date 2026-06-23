#ifndef GUILDA_H
#define GUILDA_H

//Definição das Estruturas
typedef struct {
    int id;
    char nome[50];
} Heroi;

typedef struct no {
    Heroi heroi;
    struct no *prox;
} No;

typedef struct {
    No *inicio;
} Lista;

//Protótipos das Funções
void inicializar_lista(Lista *lista);
void adicionar_heroi(Lista *lista, Heroi h);
void dispensar_heroi(Lista *lista, int id);
void mostrar_guilda(Lista *lista);
void menu();

#endif // GUILDA_H