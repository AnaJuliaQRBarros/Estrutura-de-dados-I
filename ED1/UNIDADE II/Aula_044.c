#include <stdio.h>
typedef struct
{
    int id;
    int pontos;
} Conquista;
int main()
{
    int n, i;
    int total = 0;
    FILE *arquivo = fopen("player_log.txt", "r+");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }
    Conquista player;
    fscanf(arquivo, "%d", &n);
    for (i = 0; i < n; i++)
    {
        fscanf(arquivo, "%d %d", &player.id, &player.pontos);
        total = total + player.pontos;
    }
    printf("Total de pontos de experiencia ganho: %d\n", total);
    fseek(arquivo, 0, SEEK_END);
    fprintf(arquivo, "\n--- SESSION CONCLUDED ---");
    fclose(arquivo);
    return 0;
}