#ifndef PARTIDA_H
#define PARTIDA_H

// Estrutura que representa os dados do Jogador
typedef struct {
    int id;
    char nome[50];
} Jogador;

// Estrutura do Nó da lista encadeada
typedef struct no {
    Jogador dado;
    struct no* proximo;
} No;

// Estrutura que gerencia a Lista (Fila de espera)
typedef struct {
    No* inicio;
} Lista;

// Protótipos das funções do TAD
void inicializa_lista(Lista* l);
void insere_fim(Lista* l, int id, const char* nome);
void inicia_partida(Lista* l);
void mostra_fila(const Lista* l);
void libera_lista(Lista* l);

#endif // PARTIDA_H