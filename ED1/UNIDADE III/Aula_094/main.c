#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mercenarios.h"

int main() {
    Lista companhia;
    inicializar_lista(&companhia);
    int opcao;
    Mercenario novo_m;

    do {
        menu();
        scanf("%d", &opcao);
        getchar();

        switch(opcao) {
            case 1:
                printf("\nDigite o ID do mercenario: ");
                scanf("%d", &novo_m.id);
                getchar();
                printf("Digite o nome do mercenario: ");
                fgets(novo_m.nome, 100, stdin);
                novo_m.nome[strcspn(novo_m.nome, "\n")] = 0;
                
                contratar_mercenario(&companhia, novo_m);
                break;
                
            case 2:
                exibir_companhia(&companhia);
                break;
                
            case 3:
                printf("\nTamanho atual da guilda: %d mercenario(s) ativo(s).\n", tamanho(&companhia));
                break;
                
            case 4:
                demitir_todos_mercenarios(&companhia);
                break;
                
            case 5:
                printf("\nFechando quartel-general...\n");
                demitir_todos_mercenarios(&companhia);
                break;
                
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while(opcao != 5);

    return 0;
}