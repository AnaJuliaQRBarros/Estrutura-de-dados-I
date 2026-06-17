#include <stdio.h>
int main()
{
    int balas[2] = {30, 30};
    int granadas[2] = {5, 5};
    int foguetes[2] = {2, 2};
    int *inventario[3];
    inventario[0] = balas;
    inventario[1] = granadas;
    inventario[2] = foguetes;
    printf("INVENTARIO INICIAL:\n");
    printf("BALAS: %d\n", inventario[0][0]);
    printf("GRANADAS: %d\n", inventario[1][0]);
    printf("FOGUETES: %d\n", inventario[2][0]);
    int i;
    for (i = 0; i < 3; i++)
    {
        (*(inventario[i]))--;
    }
    printf("\n");
    printf("APOS O USO: \n");
    printf("BALAS: %d\n", inventario[0][0]);
    printf("GRANADAS: %d\n", inventario[1][0]);
    printf("FOGUETES: %d\n", inventario[2][0]);
    return 0;
}