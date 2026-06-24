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
    printf("2: Lancar Proximo Feitico Pop\n");
    printf("3: Mostrar Pilha de Comandos\n");
    printf("4: Consultar Proximo Feitico Top\n");
    printf("5: Verificar Status da Pilha\n");
    printf("6: Inverter Ordem dos Feiticos\n"); // Nova
    printf("7: Finalizar a sequencia de comandos e sair\n");
    printf("=====================================\n");
    printf("Escolha uma opcao: ");
}

int vazia(Pilha *p) {
    if (p == NULL || p->topo == NULL) {
        return 1;
    }
    return 0;
}

void push(Pilha *p, Feitico f) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria\n");
        return;
    }
    
    novo->dado = f;
    novo->prox = p->topo; 
    p->topo = novo;

    printf("Feitico %s adicionado ao topo da sequencia\n", f.nome);
}

Feitico pop(Pilha *p) {
    if (vazia(p)) {
        printf("A pilha de comandos esta vazia\n");
        
        Feitico falha;
        strcpy(falha.nome, "Vazio");
        falha.custo_mana = -1;
        return falha;
    }

    No *no_removido = p->topo;
    Feitico dado_retorno = no_removido->dado;

    p->topo = no_removido->prox;
    free(no_removido);

    return dado_retorno;
}

Feitico top(Pilha *p) {
    if (vazia(p)) {
        printf("A pilha de comandos esta vazia\n");
        
        Feitico falha;
        strcpy(falha.nome, "Vazio");
        falha.custo_mana = -1;
        return falha;
    }

    return p->topo->dado;
}

void inverter_pilha(Pilha *p) {
    if (vazia(p)) {
        printf("Nao ha nada para inverter a pilha esta vazia\n");
        return;
    }

    // Criar e inicializar uma nova pilha local que servira como auxiliar
    Pilha auxiliar;
    inicializar_pilha(&auxiliar);

    // Remove da original e insere na auxiliar ate esvaziar
    while (!vazia(p)) {
        Feitico f = pop(p);
        push(&auxiliar, f);
    }

    // Faz com que o topo da pilha original aponte para o topo da pilha auxiliar
    p->topo = auxiliar.topo;

    printf("Ordem dos feiticos invertida\n");
}

void mostrar_pilha(Pilha *p) {
    printf("\n--- Sequencia de Comandos Do Topo para a Base ---\n");
    if (vazia(p)) {
        printf("A pilha de comandos esta vazia\n");
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

void liberar_pilha(Pilha *p) {
    if (p == NULL) return;
    while (!vazia(p)) {
        pop(p);
    }
}