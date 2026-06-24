#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bestiario.h"

void inicializar_lista(Lista *lista) {
    lista->inicio = NULL;
}

void menu() {
    printf("\n========= BESTIARIO DE MONSTROS =========\n");
    printf("1. Adicionar Monstro\n");
    printf("2. Ordenar Bestiario por Nivel de Ameaca\n");
    printf("3. Mostrar Bestiario\n");
    printf("4. Sair\n");
    printf("=========================================\n");
    printf("Escolha uma opcao: ");
}

// Insere um monstro sempre no final da lista encadeada
void adicionarMonstro(Lista *lista, Monstro m) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return;
    }
    novo->dado = m;
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
    printf("Monstro '%s' registrado com sucesso!\n", m.nome);
}

// Exibe todos os monstros na lista
void mostrarBestiario(Lista *lista) {
    printf("\n--- Registros no Bestiario ---\n");
    if (lista->inicio == NULL) {
        printf("O bestiario esta vazio.\n");
        return;
    }
    
    No *aux = lista->inicio;
    while (aux != NULL) {
        printf("[Nivel Ameaça (ID): %d | Nome: %s]\n", aux->dado.id, aux->dado.nome);
        aux = aux->prox;
    }
    printf("------------------------------\n");
}

// Ordenação Bubble Sort adaptada para listas encadeadas simples
void ordenarBestiario(Lista *lista) {
    // Se a lista estiver vazia ou tiver apenas um elemento, já está ordenada
    if (lista == NULL || lista->inicio == NULL || lista->inicio->prox == NULL) {
        printf("\nBestiario ja se encontra ordenado (ou não possui elementos suficientes).\n");
        return;
    }

    int trocou;
    No *atual;
    No *ultimo_verificado = NULL;

    do {
        trocou = 0;
        atual = lista->inicio;

        // Percorre a lista até o último nó não verificado da iteração anterior
        while (atual->prox != ultimo_verificado) {
            // Se o nível de ameaça do atual for MAIOR que o do próximo, troca os DADOS
            if (atual->dado.id > atual->prox->dado.id) {
                // Variável temporária para efetuar a troca dos monstros
                Monstro temp = atual->dado;
                atual->dado = atual->prox->dado;
                atual->prox->dado = temp;
                
                trocou = 1; // Marca que houve alteração nesta passagem
            }
            atual = atual->prox;
        }
        // O último nó verificado nessa rodada já está no seu lugar definitivo
        ultimo_verificado = atual; 
        
    } while (trocou); // Continua passando enquanto houver trocas

    printf("\n[Sucesso]: Bestiario ordenado com base no nivel de ameaça crescente!\n");
}