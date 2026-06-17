#include <stdio.h>
void particao(int n, int v[])
{
    int pivo = v[n - 1];
    int i = -1;
    int auxiliar;
    for (int j = 0; j < n - 1; j++)
    {
        if (v[j] < pivo)
        {
            i++;
            auxiliar = v[i];
            v[i] = v[j];
            v[j] = auxiliar;
        }
    }
    auxiliar = v[i + 1];
    v[i + 1] = v[n - 1];
    v[n - 1] = auxiliar;
}
int main()
{
    int n;
    printf("Informe a quantidade de mechas: ");
    scanf("%d", &n);
    int v[n];
    printf("Informe os pontos de vida:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    particao(n, v);
    printf("\nVetor resultante:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}