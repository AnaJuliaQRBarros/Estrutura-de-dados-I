#include <stdio.h>

typedef struct
{
    char nome[50];
    int pontuacao;
} Jogador;

int main()
{
    int n, i, j;
    printf("Informe a quantidade de jogadores: ");
    scanf("%d", &n);
    Jogador ranking[n];
    for (i = 0; i < n; i++)
    {
        printf("\nJogador %d\n", i + 1);
        printf("Nome: ");
        scanf("%s", ranking[i].nome);
        printf("Pontuacao: ");
        scanf("%d", &ranking[i].pontuacao);
    }
    for (i = 1; i < n; i++)
    {
        Jogador chave = ranking[i];
        j = i - 1;
        while (j >= 0 && ranking[j].pontuacao < chave.pontuacao)
        {
            ranking[j + 1] = ranking[j];
            j--;
        }
        ranking[j + 1] = chave;
    }
    printf("\n=== RANKING FINAL ===\n");
    for (i = 0; i < n; i++)
    {
        printf("%d %s\n", ranking[i].pontuacao, ranking[i].nome);
    }
    return 0;
}