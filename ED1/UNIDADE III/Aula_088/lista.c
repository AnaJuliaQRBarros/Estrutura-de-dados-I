#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

// Função para exibir o menu de opções
void menu() {
    printf("\n======== Gerenciador de Party =========\n");
    printf("1 - Adicionar jogador no inicio da party\n");
    printf("2 - Adicionar jogador no fim da party\n");
    printf("5 - Mostrar membros da party\n");
    printf("7 - Remover primeiro jogador da party\n");
    printf("8 - Remover ultimo jogador da party\n");
    printf("9 - Sair\n");
    printf("=======================================\n");
}

// Função para ler os dados de um novo jogador
void ler(Estudante *e) {
    printf("Digite a matricula: ");
    scanf("%d", &e->mat);
    printf("Digite o nome: ");
    scanf(" %[^\n]s", e->nome);
}

// Insere um nó no início da lista
void inserir_inicio(Lista *plista, Estudante dado) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) return; // Proteção caso falte memória
    novo->dado = dado;
    novo->prox = plista->inicio;
    plista->inicio = novo;
}

// Insere um nó no fim da lista
void inserir_fim(Lista *plista, Estudante dado) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) return;
    novo->dado = dado;
    novo->prox = NULL;
    
    if (plista->inicio == NULL) { // Lista vazia
        plista->inicio = novo;
    } else {
        No *pi;
        for (pi = plista->inicio; pi->prox != NULL; pi = pi->prox);
        pi->prox = novo;
    }
}

// Mostra todos os elementos da lista
void mostrar(Lista lista) {
    if (lista.inicio == NULL) {
        printf("A party esta vazia!\n");
        return;
    }
    No *pi;
    printf("\n--- Membros da Party ---\n");
    for (pi = lista.inicio; pi != NULL; pi = pi->prox) {
        printf("Matricula: %d | Nome: %s\n", pi->dado.mat, pi->dado.nome);
    }
    printf("------------------------\n");
}

// Deleta o primeiro nó da lista
void deletar_inicio(Lista *plista) {
    if (plista->inicio == NULL) {
        printf("A lista ja esta vazia!\n");
    } else {
        No *pi = plista->inicio;
        plista->inicio = pi->prox;
        free(pi);
    }
}

// Função para deletar o último nó da lista
void deletar_fim(Lista *plista) {
    // Caso 1: Lista Vazia
    if (plista == NULL || plista->inicio == NULL) {
        printf("A lista esta vazia. Nao eh possivel remover jogadores.\n");
        return;
    }

    // Caso 2: Apenas um Jogador
    if (plista->inicio->prox == NULL) {
        free(plista->inicio);  
        plista->inicio = NULL; 
        printf("Jogador removido com sucesso. A lista agora esta vazia.\n");
        return;
    }

    // Caso 3: Vários Jogadores
    No *penultimo = plista->inicio;
    
    while (penultimo->prox->prox != NULL) {
        penultimo = penultimo->prox;
    }

    No *ultimo = penultimo->prox;
    penultimo->prox = NULL;
    free(ultimo);
    
    printf("Ultimo jogador removido com sucesso.\n");
}