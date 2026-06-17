#include <stdio.h>

int main()
{
    int n, i, j, auxiliar;
    int trocou;
    printf("Informe a quantidade de jogadores: ");
    scanf("%d", &n);
    int pontuacoes[n];
    printf("Informe as pontuacoes:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &pontuacoes[i]);
    }
    for(i = 0; i < n - 1; i++)
    {
        trocou = 0;
        for(j = 0; j < n - 1 - i; j++)
        {
            if(pontuacoes[j] < pontuacoes[j + 1])
            {
                auxiliar = pontuacoes[j];
                pontuacoes[j] = pontuacoes[j + 1];
                pontuacoes[j + 1] = auxiliar;
                trocou = 1;
            }
        }
        if(trocou == 0)
        {
            break;
        }
    }
    printf("\nPontuacoes ordenadas:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", pontuacoes[i]);
    }
    printf("\n");
    return 0;
}