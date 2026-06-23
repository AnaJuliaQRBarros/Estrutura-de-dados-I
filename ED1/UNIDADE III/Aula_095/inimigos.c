#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inimigos.h"

void inicializar_lista(Lista *lista) {
    lista->inicio = NULL;
}

void menu() {
    printf("\n========= GERENCIADOR DE ONDAS =========\n");
    printf("1. Gerar nova onda de inimigos\n");
    printf("2. Mostrar inimigos ativos na onda\n");
    printf("3. Sair\n");
    printf("========================================\n");
    printf("Escolha uma opcao: ");
}

// Reutilizada para inserir no fim da lista que está sendo gerada
void inserir_fim(Lista *lista, Inimigo i) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return;
    }
    novo->dado = i;
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
}

void mostrar_onda(Lista *lista) {
    printf("\n--- Inimigos na Onda Atual ---\n");
    if (lista->inicio == NULL) {
        printf("Nenhum inimigo ativo no mapa.\n");
        return;
    }
    
    No *aux = lista->inicio;
    while (aux != NULL) {
        printf("[ID: %d | Tipo: %s]\n", aux->dado.id, aux->dado.tipo);
        aux = aux->prox;
    }
    printf("------------------------------\n");
}

// Função auxiliar para limpar a memória da onda antiga
void limpar_lista(Lista *lista) {
    if (lista == NULL) return;
    No *atual = lista->inicio;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    lista->inicio = NULL;
}

// --- FUNÇÃO REQUISITADA ---
Lista criar_lista(int n) {
    Lista nova_lista;
    inicializar_lista(&nova_lista);
    Inimigo novo_inimigo;

    for (int i = 0; i < n; i++) {
        printf("\n--- Dados do %dº Inimigo ---\n", i + 1);
        printf("Digite o ID: ");
        scanf("%d", &novo_inimigo.id);
        getchar();

        printf("Digite o tipo (ex: Orc, Goblin, Dragao): ");
        fgets(novo_inimigo.tipo, 100, stdin);
        novo_inimigo.tipo[strcspn(novo_inimigo.tipo, "\n")] = 0;

        // Reutiliza a função inserir_fim na lista local temporária
        inserir_fim(&nova_lista, novo_inimigo);
    }

    return nova_lista; // Retorna a lista completamente preenchida
}