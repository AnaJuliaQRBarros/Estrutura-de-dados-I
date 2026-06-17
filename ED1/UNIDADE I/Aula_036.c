#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int posicao_x;
    int posicao_y;
    int valor;
} Moeda;
int main()
{
    int quantidade_moeda;
    printf("Quantas moedas serao cadastradas?");
    scanf("%d", &quantidade_moeda);
    Moeda *moedas;
    moedas = (Moeda *)malloc(quantidade_moeda * sizeof(Moeda));
    if (moedas == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }
    int i;
    for (i = 0; i < quantidade_moeda; i++)
    {
        printf("\nMoeda %d\n", i + 1);
        printf("Digite a posicao X:\n");
        scanf("%d", &moedas[i].posicao_x);
        printf("Digite a posicao Y:\n");
        scanf("%d", &moedas[i].posicao_y);
        printf("Digite o valor:\n");
        scanf("%d", &moedas[i].valor);
    }
    int total_pontos = 0;
    for (i = 0; i < quantidade_moeda; i++)
    {
        total_pontos = total_pontos + moedas[i].valor;
    }
    printf("Pontuacao maxima do nivel: %d", total_pontos);
    free(moedas);
    return 0;
}