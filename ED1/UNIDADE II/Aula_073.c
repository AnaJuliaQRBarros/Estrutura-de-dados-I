#include <stdio.h>
void particao(int n, int v[])
{
    int s[n];
    int pivo = v[n - 1];
    int inicio = 0;
    int fim = n - 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] <= pivo)
        {
            s[inicio] = v[i];
            inicio++;
        }
        else
        {
            s[fim] = v[i];
            fim--;
        }
    }
    s[inicio] = pivo;
    for (int i = 0; i < n; i++)
    {
        v[i] = s[i];
    }
}
int main()
{
    int n;
    printf("Informe a quantidade de itens: ");
    scanf("%d", &n);
    int v[n];
    printf("Informe os niveis de poder:\n");
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