#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void inicializar_pilha(Pilha *p) {
    p->topo = NULL;
}

void menu() {
    printf("\n========= PILHA DE COMANDOS =========\n");
    printf("1: Adicionar um novo feitico a pilha de comandos\n");
    printf("2: Mostrar Pilha de Comandos\n");
    printf("3: Finalizar a sequencia de comandos e sair\n");
    printf("=====================================\n");
    printf("Escolha uma opcao: ");
}

//Insere no topo (início da lista encadeada)
void push(Pilha *p, Feitico f) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return;
    }
    
    novo->dado = f;
    novo->prox = p->topo; 
    p->topo = novo;       

    printf("Feitico '%s' adicionado ao topo da sequencia.\n", f.nome);
}

// NOVA FUNÇÃO
void mostrar_pilha(Pilha *p) {
    printf("\n--- Sequencia de Comandos ---\n");
    
    // Se a pilha estiver vazia, exibe a mensagem de aviso exigida
    if (p == NULL || p->topo == NULL) {
        printf("A pilha de comandos esta vazia.\n");
        printf("---------------------------------------------------\n");
        return;
    }

    // Percorre do topo até a base da pilha
    No *aux = p->topo;
    while (aux != NULL) {
        printf("[Feitico: %s | Custo de Mana: %d]\n", aux->dado.nome, aux->dado.custo_mana);
        aux = aux->prox; // Avança em direção à base
    }
    printf("---------------------------------------------------\n");
}

void liberar_pilha(Pilha *p) {
    No *atual = p->topo;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    p->topo = NULL;
}