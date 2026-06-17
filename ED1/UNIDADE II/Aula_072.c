#include <stdio.h>
#include <string.h>

typedef struct
{
    int posicao;
    char nome[50];
} Piloto;
void intercala(Piloto vetor[], int inicio, int meio, int fim)
{
    int i, j, k;
    int tam1 = meio - inicio + 1;
    int tam2 = fim - meio;
    Piloto esquerda[tam1];
    Piloto direita[tam2];
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
        if (esquerda[i].posicao <= direita[j].posicao)
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
void mergeSort(Piloto vetor[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = (inicio + fim) / 2;

        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);

        intercala(vetor, inicio, meio, fim);
    }
}

int main()
{
    int n, i;

    printf("Informe a quantidade de pilotos: ");
    scanf("%d", &n);

    Piloto pilotos[n];
    for (i = 0; i < n; i++)
    {
        printf("\nPiloto %d\n", i + 1);
        printf("Posicao: ");
        scanf("%d", &pilotos[i].posicao);
        printf("Nome: ");
        scanf("%s", pilotos[i].nome);
    }
    mergeSort(pilotos, 0, n - 1);
    printf("\nClassificacao final:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d %s\n",
               pilotos[i].posicao,
               pilotos[i].nome);
    }
    return 0;
}