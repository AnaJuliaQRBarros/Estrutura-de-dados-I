#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char tipo[50];
    int HP;
} Inimigo;
int main()
{
    int n, i;
    printf("Informe a quantidade de inimigos: ");
    scanf("%d", &n);
    Inimigo *unidades;
    unidades = (Inimigo *)malloc(n * sizeof(Inimigo));

    for (i = 0; i < n; i++)
    {
        printf("\n----- Inimigos -----\n");
        printf("Tipo: \n");
        scanf("%s", unidades[i].tipo);
        printf("HP: \n");
        scanf("%d", &unidades[i].HP);
        printf("Inimigos: %s, HP: %d", unidades[i].tipo, unidades[i].HP);
    }
    free(unidades);
    return 0;
}