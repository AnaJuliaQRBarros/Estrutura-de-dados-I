#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "batalha.h"

// Inicializa a formação com a lista vazia
void inicializa_formacao(Formacao* f) {
    if (f != NULL) {
        f->inicio = NULL;
    }
}

// Função auxiliar interna para alocar e configurar um novo nó de herói
No* cria_no_heroi(int id, const char* nome) {
    No* novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro de alocacao de memoria!\n");
        exit(1);
    }
    novo_no->dado.id = id;
    strncpy(novo_no->dado.nome, nome, 49);
    novo_no->dado.nome[49] = '\0';
    novo_no->proximo = NULL;
    return novo_no;
}

// Opção 1: Adicionar Herói no Fim da Formação
void insere_fim(Formacao* f, int id, const char* nome) {
    if (f == NULL) return;

    No* novo_no = cria_no_heroi(id, nome);

    if (f->inicio == NULL) {
        f->inicio = novo_no;
    } else {
        No* atual = f->inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo_no;
    }

    printf("Heroi \"%s\" adicionado ao final da formacao!\n", nome);
}

// Opção 2: Adicionar Guarda-Costas imediatamente ANTES do VIP (Foco do Exercício)
void inserir_antes(Formacao* f, int id_vip, int novo_id, const char* novo_nome) {
    if (f == NULL) return;

    // CASO A: Lista Vazia
    if (f->inicio == NULL) {
        printf("\nA insercao nao foi possivel: A formacao esta vazia!\n");
        return;
    }

    // CASO B: O VIP é o primeiro da lista
    if (f->inicio->dado.id == id_vip) {
        No* novo_no = cria_no_heroi(novo_id, novo_nome);
        novo_no->proximo = f->inicio; // O guarda-costas aponta para o VIP (antigo primeiro)
        f->inicio = novo_no;          // O guarda-costas passa a ser o novo primeiro da lista
        printf("Guarda-costas \"%s\" inserido com sucesso na frente do VIP!\n", novo_nome);
        return;
    }

    // CASO C: Procurar o VIP no meio ou fim da lista mantendo o rastro do nó anterior
    No* anterior = f->inicio;
    No* atual = f->inicio->proximo;

    while (atual != NULL && atual->dado.id != id_vip) {
        anterior = atual;
        atual = atual->proximo;
    }

    // CASO D: O VIP não foi encontrado (percorreu toda a lista e atual virou NULL)
    if (atual == NULL) {
        printf("\nA insercao nao foi possivel: Heroi VIP com ID %d nao foi encontrado!\n", id_vip);
        return;
    }

    // Se encontrou o VIP no meio/fim, faz o encaixe
    No* novo_no = cria_no_heroi(novo_id, novo_nome);
    novo_no->proximo = atual;       // O guarda-costas aponta para o VIP (atual)
    anterior->proximo = novo_no;   // O herói que vinha antes do VIP agora aponta para o guarda-costas

    printf("Guarda-costas \"%s\" inserido com sucesso imediatamente antes do VIP!\n", novo_nome);
}

// Opção 3: Mostrar Formação
void mostra_formacao(const Formacao* f) {
    if (f == NULL || f->inicio == NULL) {
        printf("\nA formacao esta vazia atualmente.\n");
        return;
    }

    printf("\n=========================================\n");
    printf("          FORMACAO DE HEROIS             \n");
    printf("=========================================\n");

    No* atual = f->inicio;
    int posicao = 1;
    while (atual != NULL) {
        printf("[%dº] ID: %d | Nome: %s\n", posicao, atual->dado.id, atual->dado.nome);
        atual = atual->proximo;
        posicao++;
    }
    printf("=========================================\n");
}

// Liberação de memória
void libera_formacao(Formacao* f) {
    if (f == NULL) return;

    No* atual = f->inicio;
    while (atual != NULL) {
        No* aux = atual->proximo;
        free(atual);
        atual = aux;
    }
    f->inicio = NULL;
}