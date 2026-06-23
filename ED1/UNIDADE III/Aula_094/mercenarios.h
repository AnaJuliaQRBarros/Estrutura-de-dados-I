#ifndef MERCENARIOS_H
#define MERCENARIOS_H

// Estrutura para representar um Mercenário
typedef struct {
    int id;
    char nome[100];
} Mercenario;

// Estrutura do nó da lista encadeada
typedef struct No {
    Mercenario dado;
    struct No *prox;
} No;

// Estrutura de controle da Lista
typedef struct {
    No *inicio;
} Lista;

// Protótipos das funções
void inicializar_lista(Lista *lista);
void menu();
void contratar_mercenario(Lista *lista, Mercenario m);
void exibir_companhia(Lista *lista);
void demitir_todos_mercenarios(Lista *lista);
int tamanho(Lista *lista);

#endif // MERCENARIOS_H