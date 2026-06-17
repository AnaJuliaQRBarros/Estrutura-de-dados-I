#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opcao;
    char evento[100];

    FILE *arquivo = fopen("game_log.txt", "a");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return 1;
    }
    do
    {
        printf("\n -------- MENU --------\n");
        printf("1 - Registrar evento\n");
        printf("2- Sair\n");
        printf("Escolha uma das opcoes: ");
        scanf("%d", &opcao);
        fflush(stdin);
        switch (opcao)
        {
        case 1:
            printf("Digite o evento: ");
            scanf(" %s", evento);
            fflush(stdin);
            fprintf(arquivo, "%s\n", evento);
            fflush(arquivo);
            break;
        case 2:
            printf("Encerrado.\n");
            break;
        default:
            printf("Opcao invalida!");
        }
    } while (opcao != 2);
    fclose(arquivo);
    return 0;
}