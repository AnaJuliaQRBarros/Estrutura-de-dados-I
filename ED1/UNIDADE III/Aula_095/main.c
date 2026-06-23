#include <stdio.h>
#include <stdlib.h>
#include "inimigos.h"

int main() {
    Lista lista_principal;
    inicializar_lista(&lista_principal);
    int opcao, qtd_inimigos;

    do {
        menu();
        scanf("%d", &opcao);
        getchar();

        switch(opcao) {
            case 1:
                printf("\nQuantos inimigos a nova onda tera? ");
                scanf("%d", &qtd_inimigos);
                getchar();
                
                if (qtd_inimigos <= 0) {
                    printf("Quantidade invalida! A onda precisa ter pelo menos 1 inimigo.\n");
                    break;
                }

                //Limpa a memória ocupada pela onda anterior antes de substituí-la
                limpar_lista(&lista_principal);

                // Atribui o retorno da função criando a nova sequência
                lista_principal = criar_lista(qtd_inimigos);
                printf("\nNova onda gerada com sucesso e carregada no mapa!\n");
                
                mostrar_onda(&lista_principal);
                break;
                
            case 2:
                mostrar_onda(&lista_principal);
                break;
                
            case 3:
                printf("\nFechando arena e limpando dados de jogo...\n");
                limpar_lista(&lista_principal);
                break;
                
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while(opcao != 3);

    return 0;
}