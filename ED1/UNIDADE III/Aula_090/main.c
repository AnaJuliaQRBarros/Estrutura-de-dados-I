#include <stdio.h>
#include <stdlib.h>
#include "wards.h"

int main() {
    Lista sistema_wards;
    inicializar_lista(&sistema_wards);
    int opcao, id_ref;
    Ward novo_ward;

    do {
        menu();
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("\nDigite o ID do Ward: ");
                scanf("%d", &novo_ward.id);
                printf("Digite o nome/tipo do Ward (ex: Control, Stealth): ");
                scanf(" %[^\n]s", novo_ward.nome);
                
                adicionar_ward(&sistema_wards, novo_ward);
                break;
                
            case 2:
                printf("\nDigite o ID do Ward de referencia para o Ward Shatter: ");
                scanf("%d", &id_ref);
                
                deletar_apos(&sistema_wards, id_ref);
                // Exibe os wards logo após a tentativa de remoção
                mostrar_wards(&sistema_wards);
                break;
                
            case 3:
                mostrar_wards(&sistema_wards);
                break;
                
            case 4:
                printf("\nDesligando sistema de monitoramento de Wards...\n");
                break;
                
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while(opcao != 4);

    // Limpeza de memória ao encerrar o programa
    No *atual = sistema_wards.inicio;
    while(atual != NULL) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }

    return 0;
}