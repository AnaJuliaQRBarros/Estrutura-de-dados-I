#include <stdio.h>

typedef struct
{
    int id;
    int nivel_ameaca;
} Nave;
void merge(Nave vetor[], int inicio, int meio, int fim)
{
    int i, j, k;
    int tam1 = meio - inicio + 1;
    int tam2 = fim - meio;
    Nave esquerda[tam1];
    Nave direita[tam2];
    for (i = 0; i < tam1; i++)
    {
        esquerda[i] = vetor[inicio + i];
    }

    for (j = 0; j < tam2; j++)
    {
        direita[j] = vetor[meio + 1 + j];
    }
    i = 0;
    j = 0;
    k = inicio;
    while (i < tam1 && j < tam2)
    {
        if (esquerda[i].nivel_ameaca <=
            direita[j].nivel_ameaca)
        {
            vetor[k] = esquerda[i];
            i++;
        }
        else
        {
            vetor[k] = direita[j];
            j++;
        }

        k++;
    }
    while (i < tam1)
    {
        vetor[k] = esquerda[i];
        i++;
        k++;
    }

    while (j < tam2)
    {
        vetor[k] = direita[j];
        j++;
        k++;
    }
}
void mergeSort(Nave vetor[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = (inicio + fim) / 2;

        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);

        merge(vetor, inicio, meio, fim);
    }
}

int main()
{
    int n, i;
    printf("Informe a quantidade de naves: ");
    scanf("%d", &n);
    Nave naves[n];
    for (i = 0; i < n; i++)
    {
        printf("\nNave %d\n", i + 1);
        printf("ID: ");
        scanf("%d", &naves[i].id);
        printf("Nivel de ameaca: ");
        scanf("%d", &naves[i].nivel_ameaca);
    }
    mergeSort(naves, 0, n - 1);
    printf("\nIDs ordenados por ameaca:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", naves[i].id);
    }
    printf("\n");
    return 0;
}