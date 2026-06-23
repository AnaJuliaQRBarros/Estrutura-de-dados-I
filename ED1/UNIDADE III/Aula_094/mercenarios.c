#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mercenarios.h"

void inicializar_lista(Lista *lista) {
    lista->inicio = NULL;
}

void menu() {
    printf("\n========= COMPANHIA DE MERCENÁRIOS =========\n");
    printf("1. Contratar mercenario\n");
    printf("2. Exibir companhia\n");
    printf("3. Verificar tamanho atual da guilda\n");
    printf("4. Declarar falencia\n");
    printf("5. Sair\n");
    printf("============================================\n");
    printf("Escolha uma opcao: ");
}

void contratar_mercenario(Lista *lista, Mercenario m) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return;
    }
    novo->dado = m;
    novo->prox = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novo;
    } else {
        No *aux = lista->inicio;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    printf("Mercenario '%s' (ID: %d) contratado com sucesso!\n", m.nome, m.id);
}

void exibir_companhia(Lista *lista) {
    printf("\n--- Integrantes da Companhia ---\n");
    if (lista->inicio == NULL) {
        printf("A companhia nao possui mercenarios ativos no momento.\n");
        return;
    }
    
    No *aux = lista->inicio;
    while (aux != NULL) {
        printf("[ID: %d | Nome: %s]\n", aux->dado.id, aux->dado.nome);
        aux = aux->prox;
    }
    printf("--------------------------------\n");
}

void demitir_todos_mercenarios(Lista *lista) {
    if (lista == NULL || lista->inicio == NULL) {
        printf("\nA companhia ja esta vazia.\n");
        return;
    }

    No *atual = lista->inicio;
    No *proximo = NULL;

    while (atual != NULL) {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    lista->inicio = NULL;
    printf("Todos os contratos foram rescindidos com sucesso.\n");
}

//FUNÇÃO SOLICITADA
int tamanho(Lista *lista) {
    // Se a lista estiver vazia (ou não inicializada), retorna 0
    if (lista == NULL || lista->inicio == NULL) {
        return 0;
    }

    int contador = 0;
    No *aux = lista->inicio;

    // Percorre a lista do início ao fim incrementando o contador
    while (aux != NULL) {
        contador++;
        aux = aux->prox; // Avança para o próximo nó
    }

    return contador;
}