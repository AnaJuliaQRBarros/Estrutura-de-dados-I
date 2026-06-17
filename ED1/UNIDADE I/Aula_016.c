#include <stdio.h>
#include <string.h>

int main()
{
    char inventario[5][20];
    char item_necessario[20];
    int encontrado = 0;
    int i;
    printf("Informe os 5 itens presentes em seu inventario:\n");
    for (i = 0; i < 5; i++)
    {
        printf("ITEM: %d:", i + 1);
        scanf(" %[^\n]s", inventario[i]);
    }
    printf("Informe o nome do item necessario para abrir a porta:\n");
    scanf(" %[^\n]s", item_necessario);
    for (i = 0; i < 5; i++)
    {
        if (strcmp(inventario[i], item_necessario) == 0)
        {
            encontrado = 1;
            break;
        }
    }
    if (encontrado)
    {
        printf("Porta aberta!\n");
    }
    else
    {
        printf("Voce não tem o item necessario.");
    }
    return 0;
}