#include <stdio.h>

typedef struct
{
    int X;
    int Y;
} Posicao;
void mover_personagem(Posicao *p, int movimento_X, int movimento_Y)
{
    p->X = p->X + movimento_X;
    p->Y = p->Y + movimento_Y;
}
int main()
{
    Posicao posicao_jogador;
    posicao_jogador.X = 0;
    posicao_jogador.Y = 0;
    Posicao *ponteiro_posicao;
    ponteiro_posicao = &posicao_jogador;
    printf("Posicao inicial do jogador: X = %d, Y = %d\n", posicao_jogador.X, posicao_jogador.Y);
    mover_personagem(ponteiro_posicao, 10, 5);
    printf("Posicao final do jogador: X = %d, Y = %d", posicao_jogador.X, posicao_jogador.Y);
    return 0;
}