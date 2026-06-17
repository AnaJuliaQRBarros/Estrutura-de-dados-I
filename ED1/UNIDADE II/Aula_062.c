#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    int eliminacoes;
} Jogador;

int main()
{

    int n, i, j, maior;
    printf("Informe a quantidade de jogadores: ");
    scanf("%d", &n);
    Jogador *players = (Jogador *)malloc(n * sizeof(Jogador));
    if (players == NULL)
    {
        printf("Erro de alocacao de memoria.\n");
        return 1;
    }
    for (i = 0; i < n; i++)
    {
        printf("\nJogador %d\n", i + 1);
        printf("Nome: ");
        scanf("%s", players[i].nome);
        printf("Eliminacoes: ");
        scanf("%d", &players[i].eliminacoes);
    }
    for (i = 0; i < n - 1; i++)
    {
        maior = i;
        for (j = i + 1; j < n; j++)
        {
            if (players[j].eliminacoes > players[maior].eliminacoes)
            {
                maior = j;
            }
        }
        Jogador auxiliar = players[i];
        players[i] = players[maior];
        players[maior] = auxiliar;
    }
    for (i = 0; i < n; i++)
    {
        printf("%s - %d eliminacao\n", players[i].nome, players[i].eliminacoes);
    }
    free(players);
    return 0;
}