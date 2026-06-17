#include <stdio.h>

typedef struct
{
    int saude;
    int pontuacao;
    int posX;
    int posY;
} Heroi;
int main()
{
    Heroi meuHeroi;
    meuHeroi.saude = 100;
    meuHeroi.pontuacao = 0;
    meuHeroi.posX = 0;
    meuHeroi.posY = 0;

    printf("Estado Inicial do Heroi:\n");
    printf("Saude: %d\n", meuHeroi.saude);
    printf("Pontuacao: %d\n", meuHeroi.pontuacao);
    printf("Posicao X: %d\n", meuHeroi.posX);
    printf("Posicao Y: %d\n", meuHeroi.posY);

    printf("\n");

    Heroi *ptrHeroi;
    ptrHeroi = &meuHeroi;
    ptrHeroi->saude = ptrHeroi->saude - 25;

    printf("Voce sofreu dano: -25 de saude!\n");
    printf("Saude: %d\n", ptrHeroi->saude);

    printf("\n");

    ptrHeroi->pontuacao = ptrHeroi->pontuacao + 50;

    printf("Voce coletou 50 moedas!\n");
    printf("Pontuacao: %d\n", ptrHeroi->pontuacao);

    printf("\n");

    ptrHeroi->posX = ptrHeroi->posX + 10;
    ptrHeroi->posY = ptrHeroi->posY - 5;

    printf("Heroi em movimento!\n");
    printf("Posicao X: %d\n", ptrHeroi->posX);
    printf("Posicao Y: %d\n", ptrHeroi->posY);

    printf("\n");

    printf("Estado Final do Heroi:\n");
    printf("Saude: %d\n", ptrHeroi->saude);
    printf("Pontuacao: %d\n", ptrHeroi->pontuacao);
    printf("Posicao X: %d\n", ptrHeroi->posX);
    printf("Posicao Y: %d\n", ptrHeroi->posY);
    return 0;
}