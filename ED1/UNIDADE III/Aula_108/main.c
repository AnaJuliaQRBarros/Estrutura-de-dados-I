#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct para representar o Jogador
typedef struct {
    int id;
    char nickname[50];
} Jogador;

// Struct para o No da lista encadeada
typedef struct No {
    Jogador jogador;
    struct No *proximo;
} No;

// Struct para a Fila
typedef struct {
    No *inicio;
    No *fim;
} Fila;

// Funcao para inicializar a fila como vazia
void inicializarFila(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

// Funcao para inserir um jogador no fim da fila
void inserir(Fila *f, Jogador j) {
    // Aloca memoria para o novo no
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return;
    }
    
    // Atribui os dados e define o proximo como NULL (sera o ultimo)
    novoNo->jogador = j;
    novoNo->proximo = NULL;
    
    // Se a fila estiver vazia, o novo no sera o inicio e o fim
    if (f->inicio == NULL) {
        f->inicio = novoNo;
        f->fim = novoNo;
    } else {
        // Se ja houver elementos, conecta o antigo fim ao novo no
        f->fim->proximo = novoNo;
        // Atualiza o ponteiro de fim da fila
        f->fim = novoNo;
    }
    printf("Jogador '%s' inserido com sucesso!\n", j.nickname);
}

// Funcao auxiliar para exibir a fila
void exibirFila(Fila *f) {
    if (f->inicio == NULL) {
        printf("A fila esta vazia.\n");
        return;
    }
    
    No *atual = f->inicio;
    printf("\n--- Status Atual da Fila ---\n");
    while (atual != NULL) {
        printf("[ID: %d | Nick: %s] -> ", atual->jogador.id, atual->jogador.nickname);
        atual = atual->proximo;
    }
    printf("NULL\n----------------------------\n");
}

// Funcao para liberar a memoria antes de sair do programa
void limparFila(Fila *f) {
    No *atual = f->inicio;
    while (atual != NULL) {
        No *aux = atual;
        atual = atual->proximo;
        free(aux);
    }
    f->inicio = NULL;
    f->fim = NULL;
}

int main() {
    Fila filaJogadores;
    inicializarFila(&filaJogadores);
    
    int opcao = 0;
    
    while (opcao != 3) {
        printf("\n=== MENU FILA DE JOGADORES ===\n");
        printf("1. Inserir Jogador\n");
        printf("2. Exibir Fila\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();
        
        if (opcao == 1) {
            Jogador novoJogador;
            
            printf("Digite o ID do jogador: ");
            scanf("%d", &novoJogador.id);
            getchar();
            
            printf("Digite o Nickname do jogador: ");
            // Le a string tratando espacos e remove o '\n' no final
            fgets(novoJogador.nickname, sizeof(novoJogador.nickname), stdin);
            novoJogador.nickname[strcspn(novoJogador.nickname, "\n")] = '\0';
            
            inserir(&filaJogadores, novoJogador);
            
        } else if (opcao == 2) {
            exibirFila(&filaJogadores);
        } else if (opcao == 3) {
            printf("Encerrando o programa e liberando memoria...\n");
            limparFila(&filaJogadores);
        } else {
            printf("Opcao invalida! Tente novamente.\n");
        }
    }
    
    return 0;
}