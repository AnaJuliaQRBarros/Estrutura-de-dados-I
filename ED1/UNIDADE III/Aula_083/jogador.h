#ifndef JOGADOR_H
#define JOGADOR_H

typedef struct {
    int matricula;
    char nome[50];
} Jogador;

typedef struct no {
    Jogador dado;
    struct no* proximo;
} No;

typedef struct {
    No* inicio;
} FilaJogadores;

void inicializa_fila(FilaJogadores* f);
void insere_inicio(FilaJogadores* f, int matricula, const char* nome);
void insere_fim(FilaJogadores* f, int matricula, const char* nome);
void mostra_fila(const FilaJogadores* f);
void libera_fila(FilaJogadores* f);

#endif // JOGADOR_H