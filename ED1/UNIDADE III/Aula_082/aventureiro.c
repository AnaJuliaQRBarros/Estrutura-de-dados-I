#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aventureiro.h"

void inicializa_lista(ListaAventureiros* l) {
    if (l != NULL) {
        l->inicio = NULL;
    }
}

//A inserção de um novo aventureiro deve ser sempre no início da lista
void adicionar_aventureiro(ListaAventureiros* l, int id, const char* nome) {
    if (l == NULL) return;

    No* novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro de alocação de memoria!\n");
        exit(1);
    }

    novo_no->dado.id = id;
    strncpy(novo_no->dado.nome, nome, 49);
    novo_no->dado.nome[49] = '\0';

    novo_no->proximo = l->inicio;

    l->inicio = novo_no;

    printf("Aventureiro \"%s\" adicionado ao grupo com sucesso!\n", nome);
}

//A função para mostrar o grupo deve percorrer a lista do início ao fim, imprimindo a ID e o nome de cada membro.
void mostrar_grupo(const ListaAventureiros* l) {
    if (l == NULL || l->inicio == NULL) {
        printf("\nO grupo de aventureiros esta vazio atualmente.\n");
        return;
    }

    printf("\n=========================================\n");
    printf("          GRUPO DE AVENTUREIROS          \n");
    printf("=========================================\n");

    No* atual = l->inicio;
    while (atual != NULL) {
        printf("ID: %d | Nome: %s\n", atual->dado.id, atual->dado.nome);
        atual = atual->proximo;
    }
    printf("=========================================\n");
}

void libera_lista(ListaAventureiros* l) {
    if (l == NULL) return;

    No* atual = l->inicio;
    while (atual != NULL) {
        No* aux = atual->proximo;
        free(atual);
        atual = aux;
    }
    l->inicio = NULL;
}