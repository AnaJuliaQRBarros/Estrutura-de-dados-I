#ifndef BATALHA_H
#define BATALHA_H

// Estrutura que representa os dados do Herói
typedef struct {
    int id;
    char nome[50];
} Heroi;

// Estrutura do Nó da lista encadeada
typedef struct no {
    Heroi dado;
    struct no* proximo;
} No;

// Estrutura que gerencia a Lista de Formação
typedef struct {
    No* inicio;
} Formacao;

// Protótipos das funções
void inicializa_formacao(Formacao* f);
void insere_fim(Formacao* f, int id, const char* nome);
void inserir_antes(Formacao* f, int id_vip, int novo_id, const char* novo_nome);
void mostra_formacao(const Formacao* f);
void libera_formacao(Formacao* f);

#endif // BATALHA_H