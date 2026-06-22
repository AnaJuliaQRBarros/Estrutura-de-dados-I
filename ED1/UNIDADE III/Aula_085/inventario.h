#ifndef INVENTARIO_H
#define INVENTARIO_H

// Estrutura que representa um Item
typedef struct {
    int id;
    char nome[50];
} Item;

// Estrutura do Nó da lista encadeada
typedef struct no {
    Item dado;
    struct no* proximo;
} No;

// Estrutura que gerencia o Inventário
typedef struct {
    No* inicio;
} Inventario;

void inicializa_inventario(Inventario* inv);
void insere_inicio(Inventario* inv, int id, const char* nome);
void insere_fim(Inventario* inv, int id, const char* nome);
void insere_depois_de(Inventario* inv, int id_alvo, int novo_id, const char* novo_nome);
void mostra_inventario(const Inventario* inv);
void libera_inventario(Inventario* inv);

#endif // INVENTARIO_H