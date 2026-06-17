#include <stdio.h>

typedef struct
{
    int posX;
    int posY;
    int moedas;
} Personagem;
// Fiz o desafio opcional.
void atualizarPersonagemComPonteiro(Personagem *p)
{
    p->posX = 10;
    p->posY = 5;
    p->moedas++;
}
int main()
{
    Personagem jogador;
    jogador.posX = 0;
    jogador.posY = 0;
    jogador.moedas = 0;
    printf("Posicao inicial: (%d,%d) - Moedas: %d\n", jogador.posX, jogador.posY, jogador.moedas);
    atualizarPersonagemComPonteiro(&jogador);
    printf("\n");
    printf("Posicao atualizada: (%d,%d) - Moedas: %d", jogador.posX, jogador.posY, jogador.moedas);
    return 0;
}