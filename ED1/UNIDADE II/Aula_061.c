#include <stdio.h>

int main()
{
    int n, i, j, menor, auxiliar;
    printf("Informe a quantidade de jogadores: ");
    scanf("%d", &n);
    int pontuacoes[n];
    for (i = 0; i < n; i++)
    {
        printf("Informe as pontuacoes: ");
        scanf("%d", &pontuacoes[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        menor = i;
        for (j = i + 1; j < n; j++)
        {
            if (pontuacoes[j] < pontuacoes[menor])
            {
                menor = j;
            }
        }
        auxiliar = pontuacoes[i];
        pontuacoes[i] = pontuacoes[menor];
        pontuacoes[menor] = auxiliar;
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", pontuacoes[i]);
    }
    printf("\n");
    return 0;
}