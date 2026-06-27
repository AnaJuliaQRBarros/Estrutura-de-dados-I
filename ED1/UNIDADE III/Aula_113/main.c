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

// Funcao para verificar se a fila esta vazia
int estaVazia(Fila *f) {
    if (f->inicio == NULL) {
        return 1; // Verdadeiro
    } else {
        return 0; // Falso
    }
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
    
    if (estaVazia(f)) {
        f->inicio = novoNo;
        f->fim = novoNo;
    } else {
        f->fim->proximo = novoNo;
        f->fim = novoNo;
    }
    printf("Jogador '%s' inserido com sucesso!\n", j.nickname);
}

// Funcao para remover o primeiro jogador da fila
Jogador remover(Fila *f) {
    if (estaVazia(f)) {
        printf("Aviso: A fila esta vazia! Nao ha jogadores para remover.\n");
        Jogador jogadorInvalido;
        jogadorInvalido.id = -1;
        strcpy(jogadorInvalido.nickname, "");
        return jogadorInvalido;
    }
    
    No *noRemovido = f->inicio;
    Jogador jogadorRetorno = noRemovido->jogador;
    
    f->inicio = f->inicio->proximo;
    
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    
    free(noRemovido);
    return jogadorRetorno;
}

// Funcao para espiar o inicio da fila sem remover
Jogador verInicio(Fila *f) {
    if (estaVazia(f)) {
        Jogador jogadorInvalido;
        jogadorInvalido.id = -1;
        strcpy(jogadorInvalido.nickname, "");
        return jogadorInvalido;
    }
    
    return f->inicio->jogador;
}

// Funcao para mostrar os jogadores da fila
void mostrar(Fila *f) {
    if (estaVazia(f)) {
        printf("A fila de matchmaking esta vazia.\n");
        return;
    }
    
    No *aux = f->inicio;
    printf("\n--- Jogadores na Fila ---\n");
    while (aux != NULL) {
        printf("ID: %d | Nickname: %s\n", aux->jogador.id, aux->jogador.nickname);
        aux = aux->proximo;
    }
    printf("-------------------------\n");
}

// Nova funcao para salvar a fila em arquivo binario
void salvarFila(Fila *f, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "wb");
    
    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return;
    }
    
    // Ponteiro auxiliar para percorrer a fila do inicio ao fim
    No *aux = f->inicio;
    int contador = 0;
    
    while (aux != NULL) {
        // Grava apenas a estrutura Jogador no arquivo
        fwrite(&(aux->jogador), sizeof(Jogador), 1, arquivo);
        aux = aux->proximo;
        contador++;
    }
    
    // Fecha o arquivo
    fclose(arquivo);
    printf("Fila salva com sucesso! %d jogador(es) gravado(s) em '%s'.\n", contador, nomeArquivo);
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
    
    // O loop agora vai ate a opcao 7 (Sair)
    while (opcao != 7) {
        printf("\n=== MENU FILA DE JOGADORES ===\n");
        printf("1. Adicionar Jogador na Fila\n");
        printf("2. Remover Jogador da Fila (Iniciar Partida)\n");
        printf("3. Mostrar Fila\n");
        printf("4. Ver quem e o proximo da Fila\n");
        printf("5. Verificar se a Fila esta Vazia\n");
        printf("6. Salvar Fila em Arquivo\n");
        printf("7. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();
        
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
            case 2: {
                Jogador removido = remover(&filaJogadores);
                if (removido.id != -1) {
                    printf("O jogador %s (ID: %d) foi removido da fila e entrou em uma partida.\n", 
                           removido.nickname, removido.id);
                }
                break;
            }
            case 3:
                mostrar(&filaJogadores);
                break;
                
            case 4: {
                Jogador proximo = verInicio(&filaJogadores);
                if (proximo.id != -1) {
                    printf("O proximo jogador a entrar na partida e: %s (ID: %d)\n", 
                           proximo.nickname, proximo.id);
                } else {
                    printf("A fila de matchmaking esta vazia. Nao ha proximo jogador.\n");
                }
                break;
            }
            
            case 5:
                if (estaVazia(&filaJogadores)) {
                    printf("SIM, a fila esta vazia.\n");
                } else {
                    printf("NAO, a fila contem jogadores.\n");
                }
                break;
                
            case 6:
                // Chamada da nova funcao com nome de arquivo fixo
                salvarFila(&filaJogadores, "matchmaking_queue.bin");
                break;
                
            case 7:
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