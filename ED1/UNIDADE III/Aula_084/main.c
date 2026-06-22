#include <stdio.h>
#include "missao.h"

int main() {
    DiarioMissoes meu_diario;
    inicializa_diario(&meu_diario);

    int opcao = 0;
    int id_aux;
    char titulo_aux[50];
    char status_aux[30];

    do {
        printf("\n========= MENU DO DIARIO =========\n");
        printf("1 - Adicionar Missao\n");
        printf("2 - Mostrar Missoes\n");
        printf("3 - Buscar Missao por ID\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Digite apenas numeros.\n");
            while (getchar() != '\n'); // Limpa buffer
            continue;
        }

        switch (opcao) {
            case 1:
                printf("\nDigite o ID da missao: ");
                scanf("%d", &id_aux);
                printf("Digite o titulo da missao: ");
                scanf(" %49[^\n]", titulo_aux);
                printf("Digite o status da missao (Ex: Pendente, Concluida): ");
                scanf(" %29[^\n]", status_aux);

                adicionar_missao(&meu_diario, id_aux, titulo_aux, status_aux);
                break;

            case 2:
                mostrar_missoes(&meu_diario);
                break;

            case 3:
                printf("\nDigite o ID da missao que deseja buscar: ");
                scanf("%d", &id_aux);

                // Chama a função de pesquisa que retorna o ponteiro para o Nó
                No* resultado = pesquisar_missao(&meu_diario, id_aux);

                if (resultado != NULL) {
                    printf("\n[Missao Encontrada!]\n");
                    printf("ID: %d\n", resultado->dado.id);
                    printf("Titulo: %s\n", resultado->dado.titulo);
                    printf("Status: %s\n", resultado->dado.status);
                } else {
                    printf("\nMissao nao encontrada!\n");
                }
                break;

            case 4:
                printf("\nFechando o diario de aventuras...\n");
                break;

            default:
                printf("\nOpcao invalida! Escolha uma opcao entre 1 e 4.\n");
                break;
        }

    } while (opcao != 4);

    // Evita o vazamento de memória antes de encerrar o programa
    libera_diario(&meu_diario);

    return 0;
}