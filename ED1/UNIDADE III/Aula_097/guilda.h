#ifndef GUILDA_H
#define GUILDA_H

// Estrutura pura de dados
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
void mostrar_lista(Lista lista);
void salvar_guild_arquivo(Lista lista);

#endif // GUILDA_H