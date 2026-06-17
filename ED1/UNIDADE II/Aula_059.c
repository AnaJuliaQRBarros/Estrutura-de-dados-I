#include <stdio.h>
typedef struct
{
    int id;
    char nome[50];
    int hp;
    int ataque;
} Monstro;
int buscaBinaria(Monstro monstros[], int idProcurado, int inicio, int fim)
{
    int meio;
    if (inicio > fim)
    {
        return -1;
    }
    meio = inicio + (fim - inicio) / 2;
    if (monstros[meio].id == idProcurado)
    {
        return meio;
    }
    if (monstros[meio].id > idProcurado)
    {
        return buscaBinaria(monstros, idProcurado, inicio, meio - 1);
    }
    return buscaBinaria(monstros, idProcurado, meio + 1, fim);
}
int main()
{
    int n, i, idBusca;
    printf("Informe a quantidade de monstros a serem catalogados: \n");
    scanf("%d", &n);
    Monstro catalogo[n];
    for (i = 0; i < n; i++)
    {
        printf("Dados do monstro %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &catalogo[i].id);
        printf("Nome: ");
        scanf(" %[^\n]", catalogo[i].nome);
        printf("HP: ");
        scanf("%d", &catalogo[i].hp);
        printf("Ataque: ");
        scanf("%d", &catalogo[i].ataque);
    }
    printf("\n--- Sistema de Busca ---\n");
    while (1)
    {
        printf("\nInforme o ID para buscar: ");
        scanf("%d", &idBusca);
        if (idBusca == 0)
        {
            break;
        }
        int resultado = buscaBinaria(catalogo, idBusca, 0, n - 1);
        if (resultado != -1)
        {
            Monstro m = catalogo[resultado];
            printf("Monstro Encontrado: %s (ID: %d) - HP: %d - Ataque: %d\n", catalogo[resultado].nome, catalogo[resultado].id, catalogo[resultado].hp, catalogo[resultado].ataque);
        }
        else
        {
            printf("Monstro com ID %d nao encontrado.\n", idBusca);
        }
    }
    printf("Programa Encerrado");
    return 0;
}