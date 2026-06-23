#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "guilda.h"

void inicializar_lista(Lista *lista) {
    lista->inicio = NULL;
}

// Insere um novo herói no final da lista.
void adicionar_heroi(Lista *lista, Heroi h) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo) {
        novo->heroi = h;
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
    } else {
        printf("Erro de alocacao de memoria!\n");
    }
}

void mostrar_guilda(Lista *lista) {
    printf("\n--- Roster da Guilda ---\n");
    if (lista->inicio == NULL) {
        printf("A guilda esta vazia.\n");
    } else {
        No *aux = lista->inicio;
        while (aux != NULL) {
            printf("ID: %d, Nome: %s\n", aux->heroi.id, aux->heroi.nome);
            aux = aux->prox;
        }
    }
    printf("------------------------\n");
}

void menu() {
    printf("\nGerenciador de Guilda:\n");
    printf("1. Adicionar Heroi\n");
    printf("2. Mostrar Guilda\n");
    printf("3. Dispensar Heroi por ID\n");
    printf("4. Sair\n");
    printf("Escolha uma opcao: ");
}

// Função para deletar um nó baseado no ID do herói.
void dispensar_heroi(Lista *lista, int id) {
    // Caso 1: A lista está vazia
    if (lista == NULL || lista->inicio == NULL) {
        printf("\nA guilda esta vazia. Nao ha herois para dispensar.\n");
        return;
    }

    No *atual = lista->inicio;
    No *anterior = NULL;

    // Caso 2: O herói a ser removido é o primeiro da lista
    if (atual->heroi.id == id) {
        lista->inicio = atual->prox; 
        free(atual);                
        printf("\nHeroi com ID %d dispensado com sucesso.\n", id);
        return;
    }

    // Caso 3: O herói está no meio ou no final da lista
    while (atual != NULL && atual->heroi.id != id) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL) {
        anterior->prox = atual->prox; 
        free(atual);                  
        printf("\nHeroi com ID %d dispensado com sucesso.\n", id);
    } 
    // Caso 4: O herói com o ID fornecido não existe na lista
    else {
        printf("\nErro: Heroi com ID %d nao foi encontrado na guilda.\n", id);
    }
}