#include <stdio.h>
#include <stdlib.h>
#include "guilda.h"

int main() {
    Lista guilda;
    inicializar_lista(&guilda);
    int opcao, id_heroi;
    Heroi novo_heroi;

    do {
        menu();
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("\nDigite o ID do novo heroi: ");
                scanf("%d", &novo_heroi.id);
                printf("Digite o nome do novo heroi: ");
                scanf("%49s", novo_heroi.nome);
                adicionar_heroi(&guilda, novo_heroi);
                break;
            case 2:
                mostrar_guilda(&guilda);
                break;
            case 3:
                printf("\nDigite o ID do heroi a ser dispensado: ");
                scanf("%d", &id_heroi);
                dispensar_heroi(&guilda, id_heroi);
                printf("\n--- Roster da Guilda Atualizado ---\n");
                mostrar_guilda(&guilda);
                break;
            case 4:
                printf("\nSaindo do gerenciador da guilda...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while(opcao != 4);

    while(guilda.inicio != NULL) {
        No *temp = guilda.inicio;
        guilda.inicio = guilda.inicio->prox;
        free(temp);
    }

    return 0;
}