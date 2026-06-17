#include <stdio.h>

typedef struct
{
    char nome[50];
    int valor_pontos;
} ItemColetavel;
int main()
{
    ItemColetavel inventario[3];
    int i;
    for (i = 0; i < 3; i++)
    {
        printf("Item %d\n", i + 1);
        printf("Digite o nome do item: \n");
        scanf(" %[^\n]s", inventario[i].nome);
        printf("Digite o valor em pontos: \n");
        scanf("%d", &inventario[i].valor_pontos);
        printf("\n");
    }
    ItemColetavel mais_valioso;
    mais_valioso = inventario[0];
    for (i = 1; i < 3; i++)
    {
        if (inventario[i].valor_pontos > mais_valioso.valor_pontos)
        {
            mais_valioso = inventario[i];
        }
    }
    printf("O item mais valioso coletado foi: %s!\n", mais_valioso.nome);
    return 0;
}