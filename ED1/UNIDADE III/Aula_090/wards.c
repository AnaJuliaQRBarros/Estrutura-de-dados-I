#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wards.h"

void inicializar_lista(Lista *lista) {
    lista->inicio = NULL;
}

void menu() {
    printf("\n========= SISTEMA DE WARDS =========\n");
    printf("1. Adicionar Ward\n");
    printf("2. Lancar 'Ward Shatter' (Deletar apos ID)\n");
    printf("3. Mostrar Wards Ativos\n");
    printf("4. Sair\n");
    printf("====================================\n");
    printf("Escolha uma opcao: ");
}

// Insere um Ward sempre no final da lista
void adicionar_ward(Lista *lista, Ward w) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return;
    }
    novo->dado = w;
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
    printf("Ward '%s' (ID: %d) adicionado com sucesso.\n", w.nome, w.id);
}

// Implementação da função 'Ward Shatter' com tratamento de todos os casos
void deletar_apos(Lista *lista, int id_referencia) {
    // Caso Especial 1: Lista Vazia
    if (lista == NULL || lista->inicio == NULL) {
        printf("\n[Shatter Falhou]: A lista esta vazia. Nao ha Wards para deletar.\n");
        return;
    }

    No *atual = lista->inicio;

    // Busca o nó de referência pelo ID
    while (atual != NULL && atual->dado.id != id_referencia) {
        atual = atual->prox;
    }

    // Caso Especial 2: Ward de referência não foi encontrado
    if (atual == NULL) {
        printf("\n[Shatter Falhou]: Ward com ID %d nao foi encontrado na lista.\n", id_referencia);
        return;
    }

    // Caso Especial 3: Ward de referência é o último da lista
    if (atual->prox == NULL) {
        printf("\n[Shatter Falhou]: O Ward com ID %d e o ultimo da lista. Nao ha nenhum Ward apos ele para ser deletado.\n", id_referencia);
        return;
    }

    // Caso de Sucesso: Remove o nó subsequente ao 'atual'
    No *alvo = atual->prox;       // O nó que será destruído
    atual->prox = alvo->prox;     // O atual pula o alvo e aponta para o próximo dele
    
    printf("\n[Ward Shatter]: O Ward '%s' (ID: %d) que estava apos o ID %d foi destruido!\n", 
           alvo->dado.nome, alvo->dado.id, id_referencia);
           
    free(alvo);
}

void mostrar_wards(Lista *lista) {
    printf("\n--- Wards Ativos ---\n");
    if (lista->inicio == NULL) {
        printf("Nenhum Ward ativo no mapa.\n");
    } else {
        No *aux = lista->inicio;
        while (aux != NULL) {
            printf("[ID: %d | Tipo: %s] ", aux->dado.id, aux->dado.nome);
            if (aux->prox != NULL) printf("-> ");
            aux = aux->prox;
        }
        printf("\n");
    }
    printf("--------------------\n");
}