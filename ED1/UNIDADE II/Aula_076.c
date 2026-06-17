#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int particao(int v[], int inicio, int fim)
{
    int indicePivo = inicio + rand() % (fim - inicio + 1);
    int auxiliar = v[indicePivo];
    v[indicePivo] = v[fim];
    v[fim] = auxiliar;
    int pivo = v[fim];
    int i = inicio - 1;
    for (int j = inicio; j < fim; j++)
    {
        if (v[j] <= pivo)
        {
            i++;
            auxiliar = v[i];
            v[i] = v[j];
            v[j] = auxiliar;
        }
    }
    auxiliar = v[i + 1];
    v[i + 1] = v[fim];
    v[fim] = auxiliar;
    return i + 1;
}
void quickSort(int v[], int inicio, int fim)
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
    srand(time(NULL));
    printf("Informe o numero de jogadores: ");
    scanf("%d", &n);
    int pontuacoes[n];
    printf("Informe as pontuacoes:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pontuacoes[i]);
    }
    quickSort(pontuacoes, 0, n - 1);
    printf("\nPontuacoes ordenadas:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", pontuacoes[i]);
    }
    printf("\n");
    return 0;
}