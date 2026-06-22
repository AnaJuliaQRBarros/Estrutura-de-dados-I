#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "missao.h"

// Inicializa o diário com a lista vazia
void inicializa_diario(DiarioMissoes* d) {
    if (d != NULL) {
        d->inicio = NULL;
    }
}

// Adiciona uma nova missão sempre ao FINAL do diário
void adicionar_missao(DiarioMissoes* d, int id, const char* titulo, const char* status) {
    if (d == NULL) return;

    // Aloca memória para o novo nó
    No* novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro de alocacao de memoria!\n");
        exit(1);
    }

    // Copia os dados para dentro do nó
    novo_no->dado.id = id;
    strncpy(novo_no->dado.titulo, titulo, 49);
    novo_no->dado.titulo[49] = '\0';
    strncpy(novo_no->dado.status, status, 29);
    novo_no->dado.status[29] = '\0';
    novo_no->proximo = NULL;

    // Caso 1: Se a lista estiver vazia
    if (d->inicio == NULL) {
        d->inicio = novo_no;
    } 
    // Caso 2: Se a lista já possuir missões, caminha até o fim
    else {
        No* atual = d->inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo_no;
    }

    printf("Missao \"%s\" adicionada ao final do diario com sucesso!\n", titulo);
}

// Exibe todas as missões presentes no diário
void mostrar_missoes(const DiarioMissoes* d) {
    if (d == NULL || d->inicio == NULL) {
        printf("\nNenhuma missao registrada no diario ate o momento.\n");
        return;
    }

    printf("\n=========================================\n");
    printf("            DIARIO DE MISSOES            \n");
    printf("=========================================\n");

    No* atual = d->inicio;
    while (atual != NULL) {
        printf("ID: %d | TItulo: %s | Status: [%s]\n", 
               atual->dado.id, atual->dado.titulo, atual->dado.status);
        atual = atual->proximo;
    }
    printf("=========================================\n");
}

//Busca a missão pelo ID e retorna o ponteiro para o nó correspondente
No* pesquisar_missao(const DiarioMissoes* d, int id) {
    if (d == NULL) return NULL;

    No* atual = d->inicio;
    while (atual != NULL) {
        if (atual->dado.id == id) {
            return atual; // Retorna o nó onde encontrou a missão
        }
        atual = atual->proximo;
    }

    return NULL; // Retorna NULL se correu toda a lista e não achou
}

// Libera toda a memória dinâmica alocada
void libera_diario(DiarioMissoes* d) {
    if (d == NULL) return;

    No* atual = d->inicio;
    while (atual != NULL) {
        No* aux = atual->proximo;
        free(atual);
        atual = aux;
    }
    d->inicio = NULL;
}