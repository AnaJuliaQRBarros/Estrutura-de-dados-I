#ifndef LISTA_H
#define LISTA_H

// Estrutura para os dados do jogador
typedef struct {
    int mat;
    char nome[100];
} Estudante;

// Estrutura do nó da lista
typedef struct No {
    Estudante dado;
    struct No *prox;
} No;

// Estrutura da lista, que contém o ponteiro para o início
typedef struct {
    No *inicio;
} Lista;

// Protótipos das funções
void menu();
void ler(Estudante *e);
void inserir_inicio(Lista *plista, Estudante dado);
void inserir_fim(Lista *plista, Estudante dado);
void mostrar(Lista lista);
void deletar_inicio(Lista *plista);
void deletar_fim(Lista *plista);

#endif // LISTA_H