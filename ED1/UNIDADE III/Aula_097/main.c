#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "guilda.h"

int main() {
    Lista guilda;
    inicializar_lista(&guilda);
    int opcao;
    Membro novo_m;

    do {
        menu();
        scanf("%d", &opcao);
        getchar();

        switch(opcao) {
            case 1:
                printf("\nDigite o ID do novo membro: ");
                scanf("%d", &novo_m.id);
                getchar();
                printf("Digite o nome do novo membro: ");
                fgets(novo_m.nome, 100, stdin);
                novo_m.nome[strcspn(novo_m.nome, "\n")] = 0;
                
                inserir_fim(&guilda, novo_m);
                break;
                
            case 2:
                mostrar_lista(guilda);
                break;
                
            case 3:
                salvar_guild_arquivo(guilda);
                break;
                
            case 4:
                printf("\nEncerrando o sistema da guilda...\n");
                break;
                
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while(opcao != 4);

    No *atual = guilda.inicio;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }

    return 0;
}