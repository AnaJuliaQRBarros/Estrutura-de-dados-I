#include <stdio.h>
int particao(int v[], int inicio, int fim)
{
    int pivo = v[fim];
    int i = inicio - 1;
    int auxiliar;
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
    printf("Informe a quantidade de jogadores: ");
    scanf("%d", &n);
    int mmr[n];
    printf("Informe os MMRs:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &mmr[i]);
    }
    quickSort(mmr, 0, n - 1);
    printf("\nMMRs ordenados:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", mmr[i]);
    }
    printf("\n");
    return 0;
}