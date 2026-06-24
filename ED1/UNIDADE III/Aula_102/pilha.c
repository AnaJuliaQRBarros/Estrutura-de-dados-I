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
    printf("2: Lancar Proximo Feitico\n");
    printf("3: Mostrar Pilha de Comandos\n");
    printf("4: Finalizar a sequencia de comandos e sair\n");
    printf("=====================================\n");
    printf("Escolha uma opcao: ");
}

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

Feitico pop(Pilha *p) {
    // Verifica se a pilha está vazia
    if (p == NULL || p->topo == NULL) {
        printf("A pilha de comandos esta vazia!\n");
        
        // Cria e retorna uma struct indicando falha
        Feitico falha;
        strcpy(falha.nome, "Vazio");
        falha.custo_mana = -1;
        return falha;
    }

    // Se não estiver vazia, isola o nó do topo
    No *no_removido = p->topo;
    Feitico dado_retorno = no_removido->dado; // Guarda os dados do feitiço

    p->topo = no_removido->prox; // O topo avança para o próximo nó
    free(no_removido);           // Libera a memória do nó extraído

    return dado_retorno; // Retorna a struct salva
}

void mostrar_pilha(Pilha *p) {
    printf("\n--- Sequencia de Comandos ---\n");
    if (p == NULL || p->topo == NULL) {
        printf("A pilha de comandos esta vazia.\n");
        printf("---------------------------------------------------\n");
        return;
    }

    No *aux = p->topo;
    while (aux != NULL) {
        printf("[Feitico: %s | Custo de Mana: %d]\n", aux->dado.nome, aux->dado.custo_mana);
        aux = aux->prox;
    }
    printf("---------------------------------------------------\n");
}

// Utiliza laços de repetição e a função pop() para esvaziar a pilha por completo
void liberar_pilha(Pilha *p) {
    if (p == NULL || p->topo == NULL) return;

    printf("\n[Limpeza]: Desalocando feiticos restantes via comandos POP...\n");
    while (p->topo != NULL) {
        pop(p); // O próprio pop já faz o free() em cada nó interno
    }
    printf("[Sucesso]: Toda a memoria foi limpa.\n");
}