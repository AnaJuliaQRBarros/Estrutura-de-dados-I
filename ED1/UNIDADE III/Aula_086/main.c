#include <stdio.h>
#include "batalha.h"

int main() {
    Formacao minha_equipe;
    inicializa_formacao(&minha_equipe);

    int opcao = 0;
    int id_aux, id_vip_aux;
    char nome_aux[50];

    do {
        printf("\n========= MENU DE FORMACAO DE HEROIS =========\n");
        printf("1 - Adicionar Heroi no Fim da Formacao\n");
        printf("2 - Adicionar Guarda-Costas\n");
        printf("3 - Mostrar Formacao\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Digite apenas numeros.\n");
            while (getchar() != '\n'); // Limpa buffer
            continue;
        }

        switch (opcao) {
            case 1:
                printf("\nDigite o ID do heroi: ");
                scanf("%d", &id_aux);
                printf("Digite o nome do heroi: ");
                scanf(" %49[^\n]", nome_aux);
                insere_fim(&minha_equipe, id_aux, nome_aux);
                break;

            case 2:
                // Solicita os dados do guarda-costas primeiro
                printf("\nDigite o ID do novo guarda-costas: ");
                scanf("%d", &id_aux);
                printf("Digite o nome do novo guarda-costas: ");
                scanf(" %49[^\n]", nome_aux);

                // Em seguida, solicita o ID do VIP
                printf("Digite o ID do heroi VIP: ");
                scanf("%d", &id_vip_aux);

                inserir_antes(&minha_equipe, id_vip_aux, id_aux, nome_aux);
                break;

            case 3:
                mostra_formacao(&minha_equipe);
                break;

            case 4:
                printf("\nDissolvendo formacao e guardando equipamentos...\n");
                break;

            default:
                printf("\nOpcao invalida! Escolha uma opcao entre 1 e 4.\n");
                break;
        }

    } while (opcao != 4);

    // Evita vazamento de memória ao encerrar o programa
    libera_formacao(&minha_equipe);

    return 0;
}