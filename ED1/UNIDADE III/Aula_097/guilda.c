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
    printf("3. Salvar Guilda em Arquivo Binario\n");
    printf("4. Sair\n");
    printf("======================================\n");
    printf("Escolha uma opcao: ");
}

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
    printf("Membro '%s' cadastrado com sucesso!\n", m.nome);
}

void mostrar_lista(Lista lista) {
    printf("\n--- Lista de Membros Ativos ---\n");
    if (lista.inicio == NULL) {
        printf("Nenhum membro registrado na guilda.\n");
        return;
    }
    
    No *aux = lista.inicio;
    while (aux != NULL) {
        printf("[ID: %d | Nome: %s]\n", aux->dado.id, aux->dado.nome);
        aux = aux->prox;
    }
    printf("-------------------------------\n");
}

// --- FUNÇÃO REQUISITADA ---
void salvar_guild_arquivo(Lista lista) {
    // Abre o arquivo em modo de escrita binária ("wb")
    FILE *arquivo = fopen("guild_roster.bin", "wb");
    
    if (arquivo == NULL) {
        printf("\n[Erro]: Nao foi possível criar ou abrir o arquivo 'guild_roster.bin'.\n");
        return;
    }

    No *aux = lista.inicio;
    int contador = 0;

    // Percorre a lista gravando apenas a struct de dados de cada nó
    while (aux != NULL) {
        // fwrite(ponteiro_dos_dados, tamanho_do_elemento, quantidade, ponteiro_do_arquivo)
        fwrite(&(aux->dado), sizeof(Membro), 1, arquivo);
        contador++;
        aux = aux->prox; // Avança para o próximo nó
    }

    // Fecha o arquivo adequadamente
    fclose(arquivo);

    printf("\n[Sucesso]: %d membro(s) salvo(s) em 'guild_roster.bin'!\n", contador);
}