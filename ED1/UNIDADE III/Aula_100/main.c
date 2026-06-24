#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main() {
    Pilha pilha_comandos;
    inicializar_pilha(&pilha_comandos);
    int opcao;
    Feitico novo_f;

    do {
        menu();
        scanf("%d", &opcao);
        getchar();

        switch(opcao) {
            case 1:
                printf("\nDigite o nome do feitico: ");
                fgets(novo_f.nome, 100, stdin);
                novo_f.nome[strcspn(novo_f.nome, "\n")] = 0;

                printf("Digite o custo de mana: ");
                scanf("%d", &novo_f.custo_mana);
                getchar();
                
                push(&pilha_comandos, novo_f);
                mostrar_pilha(&pilha_comandos); // Exibe o estado da pilha após a inserção
                break;
                
            case 2:
                printf("\nFinalizando sequencia de comandos...\n");
                mostrar_pilha(&pilha_comandos); // Mostra como ficou a sequência final antes de fechar
                break;
                
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while(opcao != 2);

    liberar_pilha(&pilha_comandos);

    return 0;
}