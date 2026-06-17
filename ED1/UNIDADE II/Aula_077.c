#include <stdio.h>

typedef struct
{
    int id;
    int pontuacao;
} Jogador;
int particao(Jogador v[], int inicio, int fim)
{
    Jogador pivo = v[fim];
    int i = inicio - 1;
    for (int j = inicio; j < fim; j++)
    {
        if (v[j].pontuacao >= pivo.pontuacao)
        {
            i++;
            Jogador auxiliar = v[i];
            v[i] = v[j];
            v[j] = auxiliar;
        }
    }
    Jogador auxiliar = v[i + 1];
    v[i + 1] = v[fim];
    v[fim] = auxiliar;
    return i + 1;
}
void quickSort(Jogador v[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int p = particao(v, inicio, fim);
        quickSort(v, inicio, p - 1);
        quickSort(v, p + 1, fim);
    }
}
int main()
{
    int n;
    printf("Informe a quantidade de jogadores: ");
    scanf("%d", &n);
    Jogador jogadores[n];
    for (int i = 0; i < n; i++)
    {
        printf("\nJogador %d\n", i + 1);
        printf("ID: ");
        scanf("%d", &jogadores[i].id);
        printf("Pontuacao: ");
        scanf("%d", &jogadores[i].pontuacao);
    }
    quickSort(jogadores, 0, n - 1);
    printf("\nRanking final:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n",
               jogadores[i].id,
               jogadores[i].pontuacao);
    }
    return 0;
}