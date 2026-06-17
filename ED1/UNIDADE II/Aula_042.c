#include <stdio.h>

typedef struct
{
    int resolucao_x;
    int resolucao_y;
    float volume_som;
} Configuracao;
int main()
{
    Configuracao Dados;
    FILE *arquivo = fopen("config.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro: Arquivo config.txt nao encontrado!\n");
        return 1;
    }
    fscanf(arquivo, "%d %d %f", &Dados.resolucao_x, &Dados.resolucao_y, &Dados.volume_som);
    printf("Configuracoes carregadas:\n");
    printf("Resolucao: %dx%d\n", Dados.resolucao_x, Dados.resolucao_y);
    printf("Volume: %.1f\n", Dados.volume_som);
    fclose(arquivo);
    return 0;
}