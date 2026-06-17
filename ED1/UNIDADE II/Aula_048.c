#include <stdio.h>
typedef struct
{
    char nome[50];
    int vida;
    int ataque;
} Campeao;
int main()
{
    int maior = 0;
    int i;
    Campeao esquadrao[3];
    FILE *arquivo = fopen("squad.dat", "rb");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    fread(esquadrao, sizeof(Campeao), 3, arquivo);
    fclose(arquivo);
    for (i = 1; i < 3; i++)
    {
        if (esquadrao[i].vida > esquadrao[maior].vida)
        {
            maior = i;
        }
    }
    printf("%s: Tanque do esquadrao.\n", esquadrao[maior].nome);
    return 0;
}