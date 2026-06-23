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
    printf("3. Declarar falencia\n");
    printf("4. Sair\n");
    printf("============================================\n");
    printf("Escolha uma opcao: ");
}

// Insere um mercenário sempre no final da lista
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

// Percorre a lista exibindo todos os mercenários ativos
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

// Remove todos os nós da lista, limpando a memória por completo
void demitir_todos_mercenarios(Lista *lista) {
    if (lista == NULL || lista->inicio == NULL) {
        printf("\nA companhia ja esta vazia. Nao ha ninguem para demitir.\n");
        return;
    }

    No *atual = lista->inicio;
    No *proximo = NULL;

    printf("\nProcessando demissoes e limpando registros...\n");
    while (atual != NULL) {
        proximo = atual->prox; // Guarda a referência do próximo nó
        printf("Liberando contrato do mercenario: %s (ID: %d)\n", atual->dado.nome, atual->dado.id);
        free(atual);           // Libera a memória do nó atual
        atual = proximo;       // Avança para o próximo
    }

    lista->inicio = NULL; // Garante que o ponteiro de início volte a ser NULL

    // Confirmação exigida pelo requisito
    if (lista->inicio == NULL) {
        printf("Falencia declarada! Todos os contratos foram rescindidos e a lista esta vazia.\n");
    }
}