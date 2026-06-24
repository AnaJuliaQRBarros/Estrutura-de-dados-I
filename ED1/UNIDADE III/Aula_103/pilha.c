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
    printf("4: Verificar Status da Pilha\n");
    printf("5: Finalizar a sequencia de comandos e sair\n");
    printf("=====================================\n");
    printf("Escolha uma opcao: ");
}

// Função nova
int vazia(Pilha *p) {
    if (p == NULL || p->topo == NULL) {
        return 1; // Verdadeiro: está vazia
    }
    return 0; // Falso: possui elementos
}

void push(Pilha *p, Feitico f) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return;
    }
    
    novo->dado = f;
    novo->prox = p->topo; 
    p->topo =novo;       

    printf("Feitico '%s' adicionado ao topo da sequencia.\n", f.nome);
}

// Refatoração: Usando a função vazia() interna
Feitico pop(Pilha *p) {
    if (vazia(p)) { // <- Substituída a checagem manual
        printf("A pilha de comandos esta vazia!\n");
        
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

// Refatoração: Usando a função vazia() interna
void mostrar_pilha(Pilha *p) {
    printf("\n--- Sequencia de Comandos ---\n");
    if (vazia(p)) { // <- Substituída a checagem manual
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

void liberar_pilha(Pilha *p) {
    if (p == NULL) return;
    
    while (!vazia(p)) { // <- Usa a lógica centralizada para o laço também
        pop(p);
    }
}