#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movimento.h"

void inicializa_lista(Lista* l) {
    l->inicio = NULL;
}

void insere_inicio(Lista* l, int id, const char* nome) {
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
    
    printf("Movimento \"%s\" inserido com sucesso no inicio do combo!\n", nome);
}
void libera_lista(Lista* l) {
    No* atual = l->inicio;
    while (atual != NULL) {
        No* aux = atual->proximo;
        free(atual);
        atual = aux;
    }
    l->inicio = NULL;
}
