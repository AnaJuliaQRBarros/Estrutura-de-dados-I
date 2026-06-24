#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bestiario.h"

int main() {
    Lista meu_bestiario;
    inicializar_lista(&meu_bestiario);
    int opcao;
    Monstro novo_m;

    do {
        menu();
        scanf("%d", &opcao);
        getchar();

        switch(opcao) {
            case 1:
                printf("\nDigite o nivel de ameaca do monstro: ");
                scanf("%d", &novo_m.id);
                getchar();
                printf("Digite o nome do monstro: ");
                fgets(novo_m.nome, 100, stdin);
                novo_m.nome[strcspn(novo_m.nome, "\n")] = 0;
                
                adicionarMonstro(&meu_bestiario, novo_m);
                break;
                
            case 2:
                ordenarBestiario(&meu_bestiario);
                mostrarBestiario(&meu_bestiario); // Exibe o resultado ordenado
                break;
                
            case 3:
                mostrarBestiario(&meu_bestiario);
                break;
                
            case 4:
                printf("\nFechando bestiario...\n");
                break;
                
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while(opcao != 4);

    No *atual = meu_bestiario.inicio;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }

    return 0;
}