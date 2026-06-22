#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventario.h"

// Inicializa o inventário com a lista vazia
void inicializa_inventario(Inventario* inv) {
    if (inv != NULL) {
        inv->inicio = NULL;
    }
}

// Função auxiliar interna para alocar e configurar um novo nó
No* cria_no_item(int id, const char* nome) {
    No* novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro de alocacao de memoria!\n");
        exit(1);
    }
    novo_no->dado.id = id;
    strncpy(novo_no->dado.nome, nome, 49);
    novo_no->dado.nome[49] = '\0';
    novo_no->proximo = NULL;
    return novo_no;
}

// Opção 1: Inserir item no início
void insere_inicio(Inventario* inv, int id, const char* nome) {
    if (inv == NULL) return;

    No* novo_no = cria_no_item(id, nome);
    novo_no->proximo = inv->inicio;
    inv->inicio = novo_no;

    printf("Item \"%s\" inserido no inicio do inventario!\n", nome);
}

// Opção 2: Inserir item no fim
void insere_fim(Inventario* inv, int id, const char* nome) {
    if (inv == NULL) return;

    No* novo_no = cria_no_item(id, nome);

    if (inv->inicio == NULL) {
        inv->inicio = novo_no;
    } else {
        No* atual = inv->inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo_no;
    }

    printf("Item \"%s\" inserido no fim do inventario!\n", nome);
}

// Opção 3: Inserir item após um ID específico
void insere_depois_de(Inventario* inv, int id_alvo, int novo_id, const char* novo_nome) {
    if (inv == NULL) return;

    // Procurando o fragmento (ID alvo) na lista encadeada
    No* atual = inv->inicio;
    while (atual != NULL && atual->dado.id != id_alvo) {
        atual = atual->proximo;
    }

    // Se saiu do laço e o ponteiro ficou NULL, significa que o ID não existe
    if (atual == NULL) {
        printf("\n[ERRO] Insercao nao foi possivel: Fragmento com ID %d nao encontrado!\n", id_alvo);
        return;
    }

    // Se encontrou, aloca o novo nó e faz o rearranjo dos ponteiros
    No* novo_no = cria_no_item(novo_id, novo_nome);
    
    novo_no->proximo = atual->proximo; // O novo nó aponta para o que vinha depois do alvo
    atual->proximo = novo_no;          // O nó alvo agora aponta para o novo nó

    printf("Catalisador \"%s\" inserido com sucesso apos o fragmento ID %d!\n", novo_nome, id_alvo);
}

// Opção 4: Mostrar inventário
void mostra_inventario(const Inventario* inv) {
    if (inv == NULL || inv->inicio == NULL) {
        printf("\nO inventario esta completamente vazio.\n");
        return;
    }

    printf("\n=========================================\n");
    printf("          INVENTARIO DE ITENS            \n");
    printf("=========================================\n");

    No* atual = inv->inicio;
    while (atual != NULL) {
        printf("ID: %d | Item: %s\n", atual->dado.id, atual->dado.nome);
        atual = atual->proximo;
    }
    printf("=========================================\n");
}

// Liberação de memória
void libera_inventario(Inventario* inv) {
    if (inv == NULL) return;

    No* atual = inv->inicio;
    while (atual != NULL) {
        No* aux = atual->proximo;
        free(atual);
        atual = aux;
    }
    inv->inicio = NULL;
}