#include <stdio.h>
int maiorFragmento(int vetor[], int inicio, int fim)
{
    if (inicio == fim)
    {
        return vetor[inicio];
    }
    int meio = (inicio + fim) / 2;
    int maiorEsquerda =
        maiorFragmento(vetor, inicio, meio);
    int maiorDireita =
        maiorFragmento(vetor, meio + 1, fim);
    if (maiorEsquerda > maiorDireita)
    {
        return maiorEsquerda;
    }
    else
    {
        return maiorDireita;
    }
}

int main()
{
    int n, i;
    printf("Informe a quantidade de fragmentos: ");
    scanf("%d", &n);
    int fragmentos[n];
    printf("Informe os poderes dos fragmentos:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &fragmentos[i]);
    }
    int maior = maiorFragmento(fragmentos, 0, n - 1);
    printf("\nMaior poder encontrado: %d\n", maior);

    return 0;
}