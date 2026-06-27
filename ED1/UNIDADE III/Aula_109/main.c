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
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return;
    }
    
    novoNo->jogador = j;
    novoNo->proximo = NULL;
    
    if (f->inicio == NULL) {
        f->inicio = novoNo;
        f->fim = novoNo;
    } else {
        f->fim->proximo = novoNo;
        f->fim = novoNo;
    }
    printf("Jogador '%s' inserido com sucesso!\n", j.nickname);
}

// Nova funcao para mostrar os jogadores da fila
void mostrar(Fila *f) {
    // Se a fila nao tiver nenhum jogador
    if (f->inicio == NULL) {
        printf("A fila de matchmaking esta vazia.\n");
        return;
    }
    
    // Ponteiro auxiliar comecando pelo inicio da fila
    No *aux = f->inicio;
    
    printf("\n--- Jogadores na Fila ---\n");
    // Itera por todos os nos ate que o ponteiro auxiliar se torne NULL
    while (aux != NULL) {
        printf("ID: %d | Nickname: %s\n", aux->jogador.id, aux->jogador.nickname);
        aux = aux->proximo; // Avanca para o proximo no
    }
    printf("-------------------------\n");
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
        printf("1. Adicionar Jogador na Fila\n");
        printf("2. Mostrar Fila\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();
        
        // Estrutura switch atualizada para gerenciar o menu
        switch (opcao) {
            case 1: {
                Jogador novoJogador;
                
                printf("Digite o ID do jogador: ");
                scanf("%d", &novoJogador.id);
                getchar();
                
                printf("Digite o Nickname do jogador: ");
                fgets(novoJogador.nickname, sizeof(novoJogador.nickname), stdin);
                novoJogador.nickname[strcspn(novoJogador.nickname, "\n")] = '\0';
                
                inserir(&filaJogadores, novoJogador);
                break;
            }
            case 2:
                mostrar(&filaJogadores);
                break;
                
            case 3:
                printf("Encerrando o programa e liberando memoria...\n");
                limparFila(&filaJogadores);
                break;
                
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
    }
    
    return 0;
}