#ifndef PILHA_H
#define PILHA_H

// Estrutura pura para os dados do feitiço
typedef struct {
    char nome[100];
    int custo_mana;
} Feitico;

// Estrutura do nó da lista encadeada
typedef struct No {
    Feitico dado;
    struct No *prox;
} No;

// Estrutura de controle da Pilha
typedef struct {
    No *topo;
} Pilha;

// Protótipos das funções
void inicializar_pilha(Pilha *p);
void menu();
void push(Pilha *p, Feitico f);
Feitico pop(Pilha *p);
void mostrar_pilha(Pilha *p);
void liberar_pilha(Pilha *p);
int vazia(Pilha *p); // Nova

#endif // PILHA_H