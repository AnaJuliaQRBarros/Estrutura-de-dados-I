#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "partida.h"

// Inicializa a lista definindo o ponteiro inicial como NULL
void inicializa_lista(Lista* l) {
    if (l != NULL) {
        l->inicio = NULL;
    }
}

// Opção 1: Adicionar jogador ao fim da fila (inserir no fim)
void insere_fim(Lista* l, int id, const char* nome) {
    if (l == NULL) return;

    // Aloca memória para o novo nó
    No* novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro de alocacao de memoria!\n");
        exit(1);
    }

    // Preenche os dados do jogador
    novo_no->dado.id = id;
    strncpy(novo_no->dado.nome, nome, 49);
    novo_no->dado.nome[49] = '\0';
    novo_no->proximo = NULL;

    // Caso A: Se a fila estiver vazia, o novo nó torna-se o início
    if (l->inicio == NULL) {
        l->inicio = novo_no;
    } 
    // Caso B: Se já contiver elementos, caminha até o último nó
    else {
        No* atual = l->inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo_no;
    }

    printf("Jogador \"%s\" adicionado ao fim da fila de espera!\n", nome);
}

// Opção 2: Iniciar partida (deletar o primeiro jogador da fila)
void inicia_partida(Lista* l) {
    if (l == NULL) return;

    // Validação REQUISITO: Se a fila estiver vazia
    if (l->inicio == NULL) {
        printf("\nNao ha jogadores na fila.\n");
        return;
    }

    // Isola o primeiro nó para poder liberar a memória dele depois
    No* no_removido = l->inicio;

    // O início da lista passa a ser o segundo elemento (no_removido->proximo)
    l->inicio = l->inicio->proximo;

    printf("\n[Partida Iniciada!] O jogador \"%s\" (ID: %d) entrou na partida.\n", 
           no_removido->dado.nome, no_removido->dado.id);

    // Libera a memória do jogador que saiu da fila
    free(no_removido);
}

// Opção 3: Mostrar fila de espera
void mostra_fila(const Lista* l) {
    if (l == NULL || l->inicio == NULL) {
        printf("\nA fila de espera esta vazia no momento.\n");
        return;
    }

    printf("\n=========================================\n");
    printf("            FILA DE ESPERA               \n");
    printf("=========================================\n");

    No* atual = l->inicio;
    int posicao = 1;
    while (atual != NULL) {
        printf("[%dº] ID: %d | Nome: %s\n", posicao, atual->dado.id, atual->dado.nome);
        atual = atual->proximo;
        posicao++;
    }
    printf("=========================================\n");
}

// Libera toda a memória dinâmica restante antes de fechar o programa
void libera_lista(Lista* l) {
    if (l == NULL) return;

    No* atual = l->inicio;
    while (atual != NULL) {
        No* aux = atual->proximo;
        free(atual);
        atual = aux;
    }
    l->inicio = NULL;
}