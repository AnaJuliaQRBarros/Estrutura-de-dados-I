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
                break;
                
            case 2:
                // Nova opção adicionada para rastrear o estado da pilha
                mostrar_pilha(&pilha_comandos);
                break;
                
            case 3:
                printf("\nEncerrando e limpando historico de comandos...\n");
                break;
                
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while(opcao != 3); // O loop continua rodando até que a opção 3 seja escolhida

    liberar_pilha(&pilha_comandos);

    return 0;
}