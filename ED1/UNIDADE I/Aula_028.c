#include <stdio.h>

struct Jogador
{
    float pos_x;
    int pontuacao;
    int tem_pulo_duplo;
};
int main()
{
    struct Jogador heroi;
    heroi.pos_x = 50.0;
    heroi.pontuacao = 0;
    heroi.tem_pulo_duplo = 0;
    printf("Inicio da fase!\n");
    printf("Posicao X: %.2f, Pontos: %d, Pulo Duplo: %d", heroi.pos_x, heroi.pontuacao, heroi.tem_pulo_duplo);
    heroi.pontuacao = 10;
    heroi.tem_pulo_duplo = 1;
    printf("\n");
    printf("Posicao X: %.2f, Pontos: %d, Pulo Duplo: %d", heroi.pos_x, heroi.pontuacao, heroi.tem_pulo_duplo);
    return 0;
}