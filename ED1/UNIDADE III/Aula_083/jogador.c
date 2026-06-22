#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogador.h"

// Inicializa a fila apontando o início para NULL
void inicializa_fila(FilaJogadores* f) {
    if (f != NULL) {
        f->inicio = NULL;
    }
}

// Cria e aloca dinamicamente um novo nó (Função auxiliar interna)
No* cria_no(int matricula, const char* nome) {
    No* novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro de alocaçao de memoria!\n");
        exit(1);
    }
    novo_no->dado.matricula = matricula;
    strncpy(novo_no->dado.nome, nome, 49);
    novo_no->dado.nome[49] = '\0';
    novo_no->proximo = NULL;
    return novo_no;
}

// Opção 1: Adiciona jogador no início da fila (Prioridade)
void insere_inicio(FilaJogadores* f, int matricula, const char* nome) {
    if (f == NULL) return;

    No* novo_no = cria_no(matricula, nome);
    novo_no->proximo = f->inicio;
    f->inicio = novo_no;

    printf("Jogador \"%s\" inserido no INICIO da fila.\n", nome);
}

// Opção 2: Adiciona jogador no fim da fila (Foco Principal)
void insere_fim(FilaJogadores* f, int matricula, const char* nome) {
    if (f == NULL) return;

    No* novo_no = cria_no(matricula, nome);

    // CASO 1: Se a fila estiver vazia, o novo nó vira o início
    if (f->inicio == NULL) {
        f->inicio = novo_no;
    } 
    // CASO 2: Se a fila já tiver elementos, percorre até achar o último
    else {
        No* atual = f->inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo; // Avança até encontrar o nó que aponta para NULL
        }
        atual->proximo = novo_no; // O antigo último nó agora aponta para o novo nó
    }

    printf("Jogador \"%s\" inserido no FIM da fila.\n", nome);
}

// Opção 3: Mostra todos os jogadores na ordem da fila
void mostra_fila(const FilaJogadores* f) {
    if (f == NULL || f->inicio == NULL) {
        printf("\nA fila de jogadores esta vazia.\n");
        return;
    }

    printf("\n=========================================\n");
    printf("            FILA DE JOGADORES            \n");
    printf("=========================================\n");

    No* atual = f->inicio;
    int posicao = 1;
    while (atual != NULL) {
        printf("%dº -> Matricula: %d | Nome: %s\n", posicao, atual->dado.matricula, atual->dado.nome);
        atual = atual->proximo;
        posicao++;
    }
    printf("=========================================\n");
}

// Libera a memória alocada ao encerrar o programa
void libera_fila(FilaJogadores* f) {
    if (f == NULL) return;

    No* atual = f->inicio;
    while (atual != NULL) {
        No* aux = atual->proximo;
        free(atual);
        atual = aux;
    }
    f->inicio = NULL;
}