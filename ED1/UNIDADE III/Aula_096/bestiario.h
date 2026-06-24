#ifndef BESTIARIO_H
#define BESTIARIO_H

// Estrutura para representar o Monstro
typedef struct {
    int id;
    char nome[100];
} Monstro;

// Estrutura do nó da lista encadeada
typedef struct No {
    Monstro dado;
    struct No *prox;
} No;

// Estrutura de controle da Lista
typedef struct {
    No *inicio;
} Lista;

// Protótipos das funções
void inicializar_lista(Lista *lista);
void menu();
void adicionarMonstro(Lista *lista, Monstro m);
void mostrarBestiario(Lista *lista);
void ordenarBestiario(Lista *lista);

#endif // BESTIARIO_H