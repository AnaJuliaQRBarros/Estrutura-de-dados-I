#include <stdio.h>
#include "inventario.h"

int main() {
    Inventario meu_inventario;
    inicializa_inventario(&meu_inventario);

    int opcao = 0;
    int id_aux, id_alvo_aux;
    char nome_aux[50];

    do {
        printf("\n========= MENU DE INVENTARIO =========\n");
        printf("1 - Inserir item no inicio\n");
        printf("2 - Inserir item no fim\n");
        printf("3 - Inserir catalisador apos um fragmento\n");
        printf("4 - Mostrar inventario\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Digite apenas numeros.\n");
            while (getchar() != '\n'); // Limpa buffer
            continue;
        }

        switch (opcao) {
            case 1:
                printf("\nDigite o ID do item comum: ");
                scanf("%d", &id_aux);
                printf("Digite o nome do item comum: ");
                scanf(" %49[^\n]", nome_aux);
                insere_inicio(&meu_inventario, id_aux, nome_aux);
                break;

            case 2:
                printf("\nDigite o ID do item comum: ");
                scanf("%d", &id_aux);
                printf("Digite o nome do item comum: ");
                scanf(" %49[^\n]", nome_aux);
                insere_fim(&meu_inventario, id_aux, nome_aux);
                break;

            case 3:
                // Requisito: primeiro solicita os dados do novo item (catalisador)
                printf("\nDigite o ID do novo catalisador: ");
                scanf("%d", &id_aux);
                printf("Digite o nome do novo catalisador: ");
                scanf(" %49[^\n]", nome_aux);

                // Em seguida, pede o ID do fragmento alvo
                printf("Digite o ID do fragmento apos o qual deseja inserir: ");
                scanf("%d", &id_alvo_aux);

                insere_depois_de(&meu_inventario, id_alvo_aux, id_aux, nome_aux);
                break;

            case 4:
                mostra_inventario(&meu_inventario);
                break;

            case 5:
                printf("\nFechando inventario e organizando a mochila...\n");
                break;

            default:
                printf("\nOpção invalida! Escolha uma opcao entre 1 e 5.\n");
                break;
        }

    } while (opcao != 5);

    // Garante que não haverá vazamento de memória
    libera_inventario(&meu_inventario);

    return 0;
}