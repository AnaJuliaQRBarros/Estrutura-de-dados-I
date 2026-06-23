#ifndef GUILDA_H
#define GUILDA_H

// Estrutura para representar o Membro
typedef struct {
    int id;
    char nome[100];
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
void menu();
void inserir_fim(Lista *lista, Membro m);
void mostrar_lista(Lista *lista);
No* pesquisar(Lista *lista, int id);
void alterar_nome(Lista *lista, int id, char novo_nome[]);

#endif // GUILDA_H