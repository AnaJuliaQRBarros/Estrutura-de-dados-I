#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *mochila;
    mochila = (int *)malloc(3 * sizeof(int));
    if (mochila == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }
    printf("Informe o valor dos 3 primeiros itens encontrados:\n");
    int i;
    for (i = 0; i < 3; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d", &mochila[i]);
    }
    printf("\nItens na mochila:\n");
    for (i = 0; i < 3; i++)
    {
        printf("%d ", mochila[i]);
    }
    printf("\n");
    int *temporaria;
    temporaria = (int *)realloc(mochila, 6 * sizeof(int));
    if (temporaria == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        free(mochila);
        return 1;
    }
    mochila = temporaria;
    printf("\nDigite mais 3 itens:\n");
    for (i = 0; i < 6; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d", &mochila[i]);
    }
    printf("\nMochila completa:\n");
    for (i = 0; i < 6; i++)
    {
        printf("%d ", mochila[i]);
    }
    printf("\n");
    free(mochila);
    return 0;
}