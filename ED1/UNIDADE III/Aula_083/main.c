#include <stdio.h>
#include "jogador.h"

int main() {
    FilaJogadores fila;
    inicializa_fila(&fila);

    int opcao = 0;
    int mat_aux;
    char nome_aux[50];

    do {
        printf("\n========= GERENCIADOR DE MATCHMAKING =========\n");
        printf("1 - Adicionar jogador no inicio da fila\n");
        printf("2 - Adicionar jogador no fim da fila\n");
        printf("3 - Mostrar fila\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Digite apenas numeros.\n");
            while (getchar() != '\n'); // Limpa buffer
            continue;
        }

        switch (opcao) {
            case 1:
                printf("\nDigite a matrícula do jogador: ");
                scanf("%d", &mat_aux);
                printf("Digite o nome do jogador: ");
                scanf(" %49[^\n]", nome_aux);
                insere_inicio(&fila, mat_aux, nome_aux);
                break;

            case 2:
                printf("\nDigite a matricula do jogador: ");
                scanf("%d", &mat_aux);
                printf("Digite o nome do jogador: ");
                scanf(" %49[^\n]", nome_aux);
                insere_fim(&fila, mat_aux, nome_aux);
                break;

            case 3:
                mostra_fila(&fila);
                break;

            case 4:
                printf("\nFechando o servidor e limpando a fila...\n");
                break;

            default:
                printf("\nOpcao invalida! Escolha entre 1 e 4.\n");
                break;
        }

    } while (opcao != 4);

    // Evita vazamento de memória antes de fechar o programa
    libera_fila(&fila);

    return 0;
}