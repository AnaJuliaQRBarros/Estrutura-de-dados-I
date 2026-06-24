#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main() {
    Pilha pilha_comandos;
    inicializar_pilha(&pilha_comandos);
    int opcao;
    Feitico novo_f, espia;

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
                espia = pop(&pilha_comandos);
                if (espia.custo_mana != -1) {
                    printf("Feitico %s lancado com sucesso\n", espia.nome);
                }
                break;
                
            case 3:
                mostrar_pilha(&pilha_comandos);
                break;
                
            case 4:
                espia = top(&pilha_comandos);
                if (espia.custo_mana != -1) {
                    printf("\nProximo feitico na agulha %s Custo de Mana %d\n", 
                           espia.nome, espia.custo_mana);
                }
                break;
                
            case 5:
                // Chamada da nova funcionalidade de salvar em arquivo
                salvar_pilha_em_arquivo(&pilha_comandos, "grimorio.bin");
                break;
                
            case 6:
                if (vazia(&pilha_comandos)) {
                    printf("\nA pilha de comandos esta vazia\n");
                } else {
                    printf("\nA pilha de comandos possui feiticos pendentes\n");
                }
                break;
                
            case 7:
                inverter_pilha(&pilha_comandos);
                break;
                
            case 8:
                printf("\nEncerrando o grimorio eletronico\n");
                break;
                
            default:
                printf("\nOpcao invalida Tente novamente\n");
        }
    } while(opcao != 8);

    liberar_pilha(&pilha_comandos);

    return 0;
}