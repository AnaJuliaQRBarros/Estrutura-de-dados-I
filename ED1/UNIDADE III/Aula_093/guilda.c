#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "guilda.h"

void inicializar_lista(Lista *lista) {
    lista->inicio = NULL;
}

void menu() {
    printf("\n========= REGISTRO DA GUILDA =========\n");
    printf("1. Adicionar Membro\n");
    printf("2. Mostrar Lista de Membros\n");
    printf("3. Alterar Nome de um Membro\n");
    printf("4. Sair\n");
    printf("======================================\n");
    printf("Escolha uma opcao: ");
}

// Insere um novo membro no final da lista
void inserir_fim(Lista *lista, Membro m) {
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
    printf("Membro '%s' registrado com sucesso!\n", m.nome);
}

// Exibe todos os membros ativos na tela
void mostrar_lista(Lista *lista) {
    printf("\n--- Lista de Membros Ativos ---\n");
    if (lista->inicio == NULL) {
        printf("Nenhum membro registrado na guilda.\n");
        return;
    }
    
    No *aux = lista->inicio;
    while (aux != NULL) {
        printf("[ID: %d | Nome: %s]\n", aux->dado.id, aux->dado.nome);
        aux = aux->prox;
    }
    printf("-------------------------------\n");
}

// Função de busca: Retorna o ponteiro para o nó encontrado ou NULL
No* pesquisar(Lista *lista, int id) {
    if (lista == NULL) return NULL;
    
    No *aux = lista->inicio;
    while (aux != NULL) {
        if (aux->dado.id == id) {
            return aux; // Retorna o nó onde o ID coincide
        }
        aux = aux->prox;
    }
    return NULL; // Se percorrer tudo e não achar
}

// Função principal do problema: Altera o nome usando a função pesquisar()
void alterar_nome(Lista *lista, int id, char novo_nome[]) {
    // Chama a função de busca
    No *membro_encontrado = pesquisar(lista, id);

    // Se o membro foi encontrado
    if (membro_encontrado != NULL) {
        // Copia o novo nome sobre o antigo
        strcpy(membro_encontrado->dado.nome, novo_nome);
        printf("\n[Sucesso]: Nome do membro com ID %d atualizado para '%s'.\n", id, novo_nome);
    } 
    // Se o membro não foi encontrado (retornou NULL)
    else {
        printf("\n[Erro]: Membro com o ID %d nao foi encontrado na guilda.\n", id);
    }
}