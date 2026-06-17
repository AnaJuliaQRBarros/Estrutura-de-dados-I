#include <stdio.h>
#include <stdlib.h>

int main()
{
    int linhas, colunas;
    int **mapa;
    int i, j;
    int contador = 0;
    printf("Digite o numero de linhas: ");
    scanf("%d", &linhas);
    printf("Digite o numero de colunas: ");
    scanf("%d", &colunas);
    mapa = (int **)malloc(linhas * sizeof(int *));
    if (mapa == NULL)
    {
        printf("Erro ao alocar a memoria!\n");
        return 1;
    }
    for (i = 0; i < linhas; i++)
    {
        mapa[i] = (int *)malloc(colunas * sizeof(int));
        if (mapa[i] == NULL)
        {
            printf("Erro ao alocar memoria!\n");
            return 1;
        }
    }
    printf("Digite os valores do mapa (0,1 ou 2):\n");
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            printf("Posicao [%d][%d]: ", i, j);
            scanf("%d", &mapa[i][j]);
        }
    }
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            if (mapa[i][j] == 1)
            {
                contador++;
            }
        }
    }
    printf("O mapa possui %d blocos de tijolo.\n", contador);
    for (i = 0; i < linhas; i++)
    {
        free(mapa[i]);
    }
    free(mapa);
    return 0;
}