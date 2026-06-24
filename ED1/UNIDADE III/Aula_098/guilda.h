#ifndef GUILDA_H
#define GUILDA_H

// Estrutura para representar um Membro da guilda
typedef struct {
    int id;
    char nome[100];
    int nivel;
} Membro;

// Estrutura do nó da lista encadeada
typedef struct No {
    Membro dado;
    struct No *prox;
} No;

// Estrutura de controle da Lista
typedef struct {
    No *inicio;
} Lista;

// Protótipos das funções
void inicializar_lista(Lista *lista);
void inserir_fim(Lista *lista, Membro m);
void mostrar_guilda(Lista lista);
Lista carregar_guilda();
void salvar_guilda_teste();

#endif // GUILDA_H