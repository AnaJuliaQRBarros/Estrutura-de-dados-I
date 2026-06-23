#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "missao.h"

void menu() {
    printf("\n--- Gerenciador de Etapas de Missao ---\n");
    printf("1 - Inserir etapa no fim\n");
    printf("2 - Mostrar etapas\n");
    printf("3 - Deletar etapa ANTES de um ID\n");
    printf("4 - Sair\n");
    printf("Escolha uma opcao: ");
}

void inserir_fim(Lista *lista, Etapa e) {
    No *novo = (No*) malloc(sizeof(No));
    if (!novo) {
        printf("Erro de alocacao de memoria!\n");
        return;
    }
    novo->etapa = e;
    novo->prox = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novo;
    } else {
        No *pi = lista->inicio;
        while (pi->prox != NULL) {
            pi = pi->prox;
        }
        pi->prox = novo;
    }
    printf("Etapa '%s' inserida com sucesso!\n", e.descricao);
}

void mostrar(Lista lista) {
    printf("\n--- Diário de Missao ---\n");
    if (lista.inicio == NULL) {
        printf("Nenhuma etapa registrada.\n");
        return;
    }
    No *pi = lista.inicio;
    while (pi != NULL) {
        printf("ID: %d - Descricao: %s\n", pi->etapa.id, pi->etapa.descricao);
        pi = pi->prox;
    }
    printf("------------------------\n");
}

void deletar_antes(Lista *lista, int id_ref) {
    // Caso 1: A lista está vazia
    if (lista == NULL || lista->inicio == NULL) {
        printf("\nA lista esta vazia. Nao ha o que deletar.\n");
        return;
    }

    // Caso 2: A etapa de referência é a primeira da lista
    if (lista->inicio->etapa.id == id_ref) {
        printf("\nA etapa com ID %d eh a primeira. Nao existe etapa anterior para deletar.\n", id_ref);
        return;
    }

    // Caso 3: A etapa a ser deletada é a primeira da lista
    if (lista->inicio->prox != NULL && lista->inicio->prox->etapa.id == id_ref) {
        No *alvo = lista->inicio;
        lista->inicio = lista->inicio->prox;
        
        printf("\nEtapa anterior ('%s') deletada com sucesso.\n", alvo->etapa.descricao);
        free(alvo);
        return;
    }

    // Caso 4: A etapa a ser deletada está no meio da lista
    No *anterior_do_alvo = lista->inicio;
    No *alvo = lista->inicio->prox;
    No *atual = alvo->prox;

    while (atual != NULL && atual->etapa.id != id_ref) {
        anterior_do_alvo = alvo;
        alvo = atual;
        atual = atual->prox;
    }

    if (atual != NULL) {
        anterior_do_alvo->prox = atual;
        printf("\nEtapa anterior ('%s') deletada com sucesso.\n", alvo->etapa.descricao);
        free(alvo);
    } 
    // Caso 5: A etapa de referência não existe
    else {
        printf("\nErro: Etapa de referencia com ID %d nao foi encontrada.\n", id_ref);
    }
}