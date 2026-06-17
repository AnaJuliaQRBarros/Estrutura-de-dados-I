#include <stdio.h>

typedef struct
{
    int id;
    int pontuacao;
} Jogador;

int main()
{
    int n, i, j;
    printf("Informe a quantidade de jogadores: ");
    scanf("%d", &n);
    Jogador players[n];
    for(i = 0; i < n; i++)
    {
        printf("\nJogador %d\n", i + 1);
        printf("ID: ");
        scanf("%d", &players[i].id);
        printf("Pontuacao: ");
        scanf("%d", &players[i].pontuacao);
    }
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - 1 - i; j++)
        {
            if(players[j].pontuacao <
               players[j + 1].pontuacao)
            {
                Jogador auxiliar = players[j];
                players[j] = players[j + 1];
                players[j + 1] = auxiliar;
            }
        }
    }
    printf("\n=== RANKING ===\n");
    for(i = 0; i < n; i++)
    {
        printf("%d %d\n",
               players[i].id,
               players[i].pontuacao);
    }
    return 0;
}