#ifndef INIMIGOS_H
#define INIMIGOS_H

// Estrutura para representar um Inimigo
typedef struct {
    int id;
    char tipo[100];
} Inimigo;

// Estrutura do nó da lista encadeada
typedef struct No {
    Inimigo dado;
    struct No *prox;
} No;

// Estrutura de controle da Lista
typedef struct {
    No *inicio;
} Lista;

// Protótipos das funções
void inicializar_lista(Lista *lista);
void menu();
void inserir_fim(Lista *lista, Inimigo i);
void mostrar_onda(Lista *lista);
void limpar_lista(Lista *lista);
Lista criar_lista(int n);

#endif // INIMIGOS_H