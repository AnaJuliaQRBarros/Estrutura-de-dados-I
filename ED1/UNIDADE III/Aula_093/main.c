#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "guilda.h"

int main() {
    Lista guilda;
    inicializar_lista(&guilda);
    int opcao, id_busca;
    char novo_nome[100];
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
                mostrar_lista(&guilda);
                break;
                
            case 3:
                printf("\nInforme o ID do membro que deseja alterar: ");
                scanf("%d", &id_busca);
                getchar();
                printf("Digite o novo nome para este membro: ");
                fgets(novo_nome, 100, stdin);
                novo_nome[strcspn(novo_nome, "\n")] = 0;
                
                alterar_nome(&guilda, id_busca, novo_nome);
                mostrar_lista(&guilda); // Mostra a lista modificada para conferência
                break;
                
            case 4:
                printf("\nEncerrando sistema de registros...\n");
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