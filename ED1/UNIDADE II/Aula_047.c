#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char nome[50];
    int vida;
    int ataque;
} Unidade;

int main()
{
    int n, i;
    int maior = 0;
    printf("Informe a quantidade de jogadores no seu esquadrao!\n");
    scanf("%d", &n);
    Unidade *esquadrao;
    esquadrao = (Unidade *)malloc(n * sizeof(Unidade));
    if (esquadrao == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }
    for (i = 0; i < n; i++)
    {
        printf("Nome: ");
        scanf(" %[^\n]", esquadrao[i].nome);
        printf("Vida: ");
        scanf("%d", &esquadrao[i].vida);
        printf("Ataque: ");
        scanf("%d", &esquadrao[i].ataque);
    }
    FILE *arquivo = fopen("squad.dat", "wb");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }
    fwrite(esquadrao, sizeof(Unidade), n, arquivo);
    fclose(arquivo);
    for (i = 0; i < n; i++)
    {
        if (esquadrao[i].ataque > esquadrao[maior].ataque)
        {
            maior = i;
        }
    }
    printf("Unidade com maior valor de ataque: %s\n", esquadrao[maior].nome);
    free(esquadrao);
    return 0;
}