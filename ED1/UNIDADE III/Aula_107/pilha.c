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
    printf("2: Lancar Proximo Feitico Pop\n");
    printf("3: Mostrar Pilha de Comandos\n");
    printf("4: Consultar Proximo Feitico Top\n");
    printf("5: Salvar Sequencia no Grimorio\n");
    printf("6: Verificar Status da Pilha\n");
    printf("7: Inverter Ordem dos Feiticos\n");
    printf("8: Finalizar a sequencia de comandos e sair\n");
    printf("=====================================\n");
    printf("Escolha uma opcao: ");
}

int vazia(Pilha *p) {
    if (p == NULL || p->topo == NULL) {
        return 1;
    }
    return 0;
}

void push(Pilha *p, Feitico f) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria\n");
        return;
    }
    
    novo->dado = f;
    novo->prox = p->topo; 
    p->topo = novo;
}

Feitico pop(Pilha *p) {
    if (vazia(p)) {
        printf("A pilha de comandos esta vazia\n");
        
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

Feitico top(Pilha *p) {
    if (vazia(p)) {
        printf("A pilha de comandos esta vazia\n");
        
        Feitico falha;
        strcpy(falha.nome, "Vazio");
        falha.custo_mana = -1;
        return falha;
    }

    return p->topo->dado;
}

void inverter_pilha(Pilha *p) {
    if (vazia(p)) {
        return;
    }

    Pilha auxiliar;
    inicializar_pilha(&auxiliar);

    while (!vazia(p)) {
        Feitico f = pop(p);
        push(&auxiliar, f);
    }

    p->topo = auxiliar.topo;
}

void salvar_pilha_em_arquivo(Pilha *p, const char* nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "wb");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s para escrita\n", nome_arquivo);
        return;
    }

    No *aux = p->topo;
    int contador = 0;

    while (aux != NULL) {
        fwrite(&(aux->dado), sizeof(Feitico), 1, arquivo);
        contador++;
        aux = aux->prox;
    }

    fclose(arquivo);
    printf("Sucesso %d feiticos salvos no arquivo %s\n", contador, nome_arquivo);
}

void carregar_pilha_de_arquivo(Pilha *p, const char* nome_arquivo) {
    // Abre o arquivo no modo de leitura binaria
    FILE *arquivo = fopen(nome_arquivo, "rb");
    
    // Se o arquivo nao existir retorna graciosamente avisando o usuario
    if (arquivo == NULL) {
        printf("Nenhum grimorio encontrado iniciando com uma pilha vazia\n");
        return;
    }

    Feitico buffer_leitura;
    int contador = 0;

    // Le uma struct Feitico por vez do arquivo usando fread
    while (fread(&buffer_leitura, sizeof(Feitico), 1, arquivo) == 1) {
        push(p, buffer_leitura);
        contador++;
    }

    fclose(arquivo);
    
    // Ponto Critico: Inverte de volta para restaurar a ordem original de topo e base
    inverter_pilha(p);
    
    printf("Sucesso %d feiticos restaurados do arquivo %s\n", contador, nome_arquivo);
}

void mostrar_pilha(Pilha *p) {
    printf("\n--- Sequencia de Comandos Do Topo para a Base ---\n");
    if (vazia(p)) {
        printf("A pilha de comandos esta vazia\n");
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
    while (!vazia(p)) {
        pop(p);
    }
}