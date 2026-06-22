#include <stdio.h>
#include "movimento.h"

int main() {
    Lista combo;
    inicializa_lista(&combo);

    int opcao = 0;
    int id_aux;
    char nome_aux[50];

    //Implemente um programa principal (main) que exiba um menu com as seguintes opções:
    do {
        printf("\n========= MENU DO COMBO =========\n");
        //1: Inserir novo movimento no início do combo
        printf("1: Inserir novo movimento no inicio do combo\n");
        //2: Sair
        printf("2: Sair\n");
        printf("Escolha uma opçao: ");
        
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida!\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (opcao) {
            //Ao escolher a opção '1', o programa deve ler o ID e o nome de um novo movimento e inseri-lo no início da lista encadeada.
            case 1:
                printf("\nDigite o ID do movimento: ");
                scanf("%d", &id_aux);
                
                printf("Digite o nome do movimento (golpe): ");
                scanf(" %49[^\n]", nome_aux);
                insere_inicio(&combo, id_aux, nome_aux);
                break;
            //O programa deve continuar executando até que o usuário escolha a opção '2'
            case 2:
                printf("\nEncerrando o programa e limpando o combo...\n");
                break;

            default:
                printf("\nOpçao invalida! Tente novamente.\n");
                break;
        }

    } while (opcao != 2);
    libera_lista(&combo);

    return 0;
}