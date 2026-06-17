#include <stdio.h>

typedef struct
{
    char nome[50];
    int vida;
    int ataque;
} Inimigo;
int main()
{
    Inimigo atual;
    Inimigo maisforte;
    FILE *arquivo = fopen("wave_data.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }
    fscanf(arquivo, "%s %d %d", maisforte.nome, &maisforte.vida, &maisforte.ataque);
    while (fscanf(arquivo, "%s %d %d", atual.nome, &atual.vida, &atual.ataque) != EOF)
    {
        if (atual.ataque > maisforte.ataque)
        {
            maisforte = atual;
        }
    }
    printf("Maior ameaca: %s,Vida: %d,Ataque: %d\n", maisforte.nome, maisforte.vida, maisforte.ataque);
    fclose(arquivo);
    return 0;
}