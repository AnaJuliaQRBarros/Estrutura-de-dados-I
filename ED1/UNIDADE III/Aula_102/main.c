#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main() {
    Pilha pilha_comandos;
    inicializar_lista: inicializar_pilha(&pilha_comandos);
    int opcao;
    Feitico novo_f, lançado;

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
                // Chama a função pop para extrair e "lançar" a magia do topo
                lançado = pop(&pilha_comandos);
                
                // Se o custo de mana for diferente de -1, a operação funcionou
                if (lançado.custo_mana != -1) {
                    printf("Feitico '%s' lancado com sucesso!\n", lançado.nome);
                }
                break;
                
            case 3:
                mostrar_pilha(&pilha_comandos);
                break;
                
            case 4:
                printf("\nEncerrando o conjurador de magias...\n");
                break;
                
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while(opcao != 4);

    // Esvazia os nós remanescentes de forma segura antes de fechar o app
    liberar_pilha(&pilha_comandos);

    return 0;
}