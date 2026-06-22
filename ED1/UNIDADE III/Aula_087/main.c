#include <stdio.h>
#include "partida.h"

int main() {
    Lista fila_matchmaking;
    inicializa_lista(&fila_matchmaking);

    int opcao = 0;
    int id_aux;
    char nome_aux[50];

    do {
        printf("\n========= LOBBY DE JOGOS =========\n");
        printf("1: Adicionar jogador ao fim da fila\n");
        printf("2: Iniciar partida\n");
        printf("3: Mostrar fila de espera\n");
        printf("4: Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Digite apenas numeros.\n");
            while (getchar() != '\n'); // Limpa buffer de caracteres inesperados
            continue;
        }

        switch (opcao) {
            case 1:
                printf("\nDigite o ID do jogador: ");
                scanf("%d", &id_aux);
                printf("Digite o nome do jogador: ");
                scanf(" %49[^\n]", nome_aux); // Leitura segura com espaços

                insere_fim(&fila_matchmaking, id_aux, nome_aux);
                break;

            case 2:
                inicia_partida(&fila_matchmaking);
                break;

            case 3:
                mostra_fila(&fila_matchmaking);
                break;

            case 4:
                printf("\nFechando o lobby e desconectando servidores...\n");
                break;

            default:
                printf("\nOpção invalida! Escolha uma opção de 1 a 4.\n");
                break;
        }

    } while (opcao != 4);

    // Garante a liberação de memória de quem sobrou na fila antes do encerramento
    libera_lista(&fila_matchmaking);

    return 0;
}