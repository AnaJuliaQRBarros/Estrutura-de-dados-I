#ifndef MISSOES_H
#define MISSOES_H

//ESTRUTURAS
typedef struct {
    int id;
    char descricao[100];
} Etapa;

typedef struct No {
    Etapa etapa;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
} Lista;

//PROTÓTIPOS
void menu();
void inserir_fim(Lista *lista, Etapa e);
void mostrar(Lista lista);
void deletar_antes(Lista *lista, int id_ref);

#endif // MISSOES_H