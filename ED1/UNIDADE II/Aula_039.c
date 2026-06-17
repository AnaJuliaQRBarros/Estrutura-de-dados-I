#include <stdio.h>

typedef struct
{
    char nome[50];
    float HP;
    float ATK;
} Inimigo;

int main()
{
    int i = 0;
    int j;
    float Nivel_Ameaca;
    FILE *arquivo = fopen("inimigos.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }
    Inimigo lista[10];
    while (fscanf(arquivo, "%s %f %f", lista[i].nome, &lista[i].HP, &lista[i].ATK) != EOF)
    {
        i++;
    }
    printf("-------------- INIMIGOS ELITE --------------\n");
    for (j = 0; j < i; j++)
    {
        Nivel_Ameaca = lista[j].HP + lista[j].ATK;
        if (Nivel_Ameaca >= 200.0)
        {
            printf("Nome: %s / Nivel de Ameaca: %.2f\n", lista[j].nome, Nivel_Ameaca);
        }
    }
    fclose(arquivo);
    return 0;
}