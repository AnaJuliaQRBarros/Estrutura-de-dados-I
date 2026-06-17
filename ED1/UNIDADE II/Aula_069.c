#include <stdio.h>

int main()
{
    int n, m, i, j, k;
    printf("Quantidade de inimigos do Portal Alfa: ");
    scanf("%d", &n);
    int alfa[n];
    printf("Informe os niveis de ameaca:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &alfa[i]);
    }
    printf("\nQuantidade de inimigos do Portal Beta: ");
    scanf("%d", &m);
    int beta[m];
    printf("Informe os niveis de ameaca:\n");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &beta[i]);
    }
    int resultado[n + m];
    i = 0;
    j = 0;
    k = 0;
    while (i < n && j < m)
    {
        if (alfa[i] < beta[j])
        {
            resultado[k] = alfa[i];
            i++;
        }
        else
        {
            resultado[k] = beta[j];
            j++;
        }
        k++;
    }
    while (i < n)
    {
        resultado[k] = alfa[i];
        i++;
        k++;
    }
    while (j < m)
    {
        resultado[k] = beta[j];
        j++;
        k++;
    }
    printf("\nLista final ordenada:\n");
    for (i = 0; i < n + m; i++)
    {
        printf("%d ", resultado[i]);
    }
    printf("\n");
    return 0;
}