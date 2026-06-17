#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct
{
    int x;
    int y;
} Unidade;
int main()
{
    int n, i, j;
    float raio;
    int duplas_proximas = 0;
    printf("Informe a quantidade de unidades inimigas: \n");
    scanf("%d", &n);
    if (n < 2)
    {
        printf("Quantidade insuficiente!");
        return 1;
    }
    Unidade *Inimiga;
    Inimiga = (Unidade *)malloc(n * sizeof(Unidade));
    if (Inimiga == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }
    for (i = 0; i < n; i++)
    {
        printf("Coordenadas da unidade %d (x e y): ", i + 1);
        scanf("%d %d", &Inimiga[i].x, &Inimiga[i].y);
    }
    printf("Informe o raio da distancia maxima: \n");
    scanf("%f", &raio);
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            double distancia = sqrt(pow(Inimiga[j].x - Inimiga[i].x, 2) + pow(Inimiga[j].y - Inimiga[i].y, 2));
            if (distancia <= raio)
            {
                duplas_proximas++;
            }
        }
    }
    printf("\nTotal de Duplas proximas: %d\n", duplas_proximas);
    free(Inimiga);
    return 0;
}