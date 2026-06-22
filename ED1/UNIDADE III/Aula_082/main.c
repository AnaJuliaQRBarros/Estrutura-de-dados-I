#include <stdio.h>
#include "aventureiro.h"

int main() {
    ListaAventureiros grupo;
    inicializa_lista(&grupo);

    int opcao = 0;
    int id_aux;
    char nome_aux[50];

    do {
        printf("\n========= GERENCIADOR DE GUILDA =========\n");
        printf("1: Adicionar Aventureiro\n");
        printf("2: Mostrar Grupo\n");
        printf("3: Sair\n");
        printf("Escolha uma opçao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Digite apenas numeros.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (opcao) {
            //Adicionar Aventureiro: Solicita o ID (um número inteiro) e o nome do novo aventureiro
            case 1:
                printf("\nDigite o ID do aventureiro: ");
                scanf("%d", &id_aux);

                printf("Digite o nome do aventureiro: ");
                scanf(" %49[^\n]", nome_aux);

                adicionar_aventureiro(&grupo, id_aux, nome_aux);
                break;

            //Exibe a lista de todos os aventureiros atualmente no grupo
            case 2:
                mostrar_grupo(&grupo);
                break;

            //Encerra o programa
            case 3:
                printf("\nDesfazendo o grupo e encerrando a jornada...\n");
                break;

            default:
                printf("\nOpçao invalida! Tente novamente.\n");
                break;
        }

    } while (opcao != 3);

    libera_lista(&grupo);

    return 0;
}