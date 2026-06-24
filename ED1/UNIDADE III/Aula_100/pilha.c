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
    printf("2: Finalizar a sequencia de comandos e sair\n");
    printf("================================================\n");
    printf("Escolha uma opcao: ");
}

// Insere sempre no TOPO da pilha (início da lista)
void push(Pilha *p, Feitico f) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return;
    }
    
    novo->dado = f;
    novo->prox = p->topo; // O novo nó aponta para o antigo topo
    p->topo = novo;       // O topo da pilha passa a ser o novo nó

    printf("Feitico '%s' adicionado ao topo da sequencia com sucesso.\n", f.nome);
}

// Função auxiliar para visualizar o estado atual da sequência de comandos
void mostrar_pilha(Pilha *p) {
    printf("\n--- Sequencia de Comandos Atual ---\n");
    if (p->topo == NULL) {
        printf("Nenhum feitico na pilha.\n");
        return;
    }

    No *aux = p->topo;
    while (aux != NULL) {
        printf("[Feitico: %s | Mana: %d]\n", aux->dado.nome, aux->dado.custo_mana);
        aux = aux->prox;
    }
    printf("---------------------------------------------------------\n");
}

// Remove todos os elementos da pilha limpando a memória
void liberar_pilha(Pilha *p) {
    No *atual = p->topo;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    p->topo = NULL;
}