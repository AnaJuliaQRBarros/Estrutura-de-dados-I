#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[50];
    int vida;
    int ataque;
} Campeao;

int main()
{

    Campeao esquadrao[3];

    strcpy(esquadrao[0].nome, "Garen");
    esquadrao[0].vida = 620;
    esquadrao[0].ataque = 69;

    strcpy(esquadrao[1].nome, "Lux");
    esquadrao[1].vida = 530;
    esquadrao[1].ataque = 55;

    strcpy(esquadrao[2].nome, "Ashe");
    esquadrao[2].vida = 590;
    esquadrao[2].ataque = 61;

    FILE *arquivo = fopen("squad.dat", "wb");

    if (arquivo == NULL)
    {
        printf("Erro ao criar arquivo.\n");
        return 1;
    }

    fwrite(esquadrao, sizeof(Campeao), 3, arquivo);

    fclose(arquivo);

    printf("Arquivo criado com sucesso.\n");

    return 0;
}