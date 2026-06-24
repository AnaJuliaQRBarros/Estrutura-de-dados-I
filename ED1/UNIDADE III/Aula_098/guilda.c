#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "guilda.h"

void inicializar_lista(Lista *lista) {
    lista->inicio = NULL;
}

// Insere um membro sempre no final da lista encadeada
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
}

// Imprime os dados de todos os membros carregados
void mostrar_guilda(Lista lista) {
    printf("\n======= ROSTER DA GUILDA CARREGADO =======\n");
    if (lista.inicio == NULL) {
        printf("A guilda esta vazia ou o arquivo nao continha registros.\n");
        return;
    }
    
    No *aux = lista.inicio;
    while (aux != NULL) {
        printf("ID: %-4d | Nome: %-20s | Nivel: %d\n", 
               aux->dado.id, aux->dado.nome, aux->dado.nivel);
        aux = aux->prox;
    }
    printf("==========================================\n");
}

//FUNÇÃO CARREGAR DADOS
Lista carregar_guilda() {
    Lista nova_lista;
    inicializar_lista(&nova_lista);
    
    // a. Abrir o arquivo em modo de leitura binária
    FILE *arquivo = fopen("guild_roster.b", "rb");
    
    if (arquivo == NULL) {
        printf("\n[Aviso]: Arquivo 'guild_roster.b' nao encontrado. Retornando lista vazia.\n");
        return nova_lista;
    }

    Membro buffer_leitura;

    // c. Usar um laço com fread() para ler cada Membro do arquivo, um por um
    // fread retorna a quantidade de elementos lidos com sucesso (deve ser 1)
    while (fread(&buffer_leitura, sizeof(Membro), 1, arquivo) == 1) {
        // d. Para cada membro lido, insere no final da nova lista encadeada
        inserir_fim(&nova_lista, buffer_leitura);
    }

    // e. Fechar o arquivo e retornar a lista preenchida
    fclose(arquivo);
    printf("\n[Sucesso]: Dados da guilda carregados com sucesso a partir do arquivo!\n");
    
    return nova_lista;
}

// --- FUNÇÃO AUXILIAR PARA GERAR O ARQUIVO DE TESTE ---
void salvar_guilda_teste() {
    FILE *arquivo = fopen("guild_roster.b", "wb");
    if (arquivo == NULL) {
        printf("Erro ao criar arquivo de teste.\n");
        return;
    }

    // Criando 3 membros fixos para o ambiente de teste
    Membro m1 = {101, "Aragorn", 50};
    Membro m2 = {102, "Legolas", 48};
    Membro m3 = {103, "Gimli", 47};

    // Gravando os dados diretamente no arquivo binário
    fwrite(&m1, sizeof(Membro), 1, arquivo);
    fwrite(&m2, sizeof(Membro), 1, arquivo);
    fwrite(&m3, sizeof(Membro), 1, arquivo);

    fclose(arquivo);
    printf("[Setup]: Arquivo 'guild_roster.b' de teste gerado com 3 herois fixos.\n");
}