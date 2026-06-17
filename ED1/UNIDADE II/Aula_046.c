#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char nome[50];
    int nivel;
    int highScore;
} PlayerProfile;
int main()
{
    FILE *arquivo = fopen("profiles.dat", "rb");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }
    PlayerProfile rank;
    while (fread(&rank, sizeof(PlayerProfile), 1, arquivo) == 1)
    {
        printf("Jogador: %s\n", rank.nome);
        if (rank.highScore > 10000)
        {
            printf("Rank: Mestre do jogo!\n");
        }
        else if (rank.highScore > 5000)
        {
            printf("Rank: Veterano!\n");
        }
        else
        {
            printf("Rank: Aspirante!\n");
        }
        printf("\n");
    }
    fclose(arquivo);
    return 0;
}