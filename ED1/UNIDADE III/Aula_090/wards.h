#ifndef WARDS_H
#define WARDS_H

// Estrutura para representar um Ward
typedef struct {
    int id;
    char nome[100];
} Ward;

// Estrutura do nó da lista encadeada
typedef struct No {
    Ward dado;
    struct No *prox;
} No;

// Estrutura de controle da Lista
typedef struct {
    No *inicio;
} Lista;

// Protótipos das funções
void inicializar_lista(Lista *lista);
void menu();
void adicionar_ward(Lista *lista, Ward w);
void deletar_apos(Lista *lista, int id_referencia);
void mostrar_wards(Lista *lista);

#endif // WARDS_H