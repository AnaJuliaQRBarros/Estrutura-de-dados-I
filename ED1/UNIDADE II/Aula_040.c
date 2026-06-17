#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    int pontuacao;
} Dados;

int main()
{
    int n, i;
    int maior = 0;
    printf("Digite a quantidade de jogadores: ");
    scanf("%d", &n);
    Dados jogadores[n];
    for (i = 0; i < n; i++)
    {
        printf("\nJogador %d\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", jogadores[i].nome);
        printf("Pontuacao: ");
        scanf("%d", &jogadores[i].pontuacao);
    }
    for (i = 1; i < n; i++)
    {
        if (jogadores[i].pontuacao > jogadores[maior].pontuacao)
        {
            maior = i;
        }
    }
    FILE *arquivo = fopen("highscore.txt", "w");
    fprintf(arquivo, "Nome: %s, Pontuacao: %d", jogadores[maior].nome, jogadores[maior].pontuacao);
    fclose(arquivo);
    return 0;
}