#include <stdio.h>

typedef struct
{
    int pontos;
    float pos_x;
    float pos_y;
} Coletavel;
int main()
{
    Coletavel gema_rara;
    printf("Digite o valor em pontos da gema rara, a posicao X e a posicao Y!\n");
    scanf("%d %f %f", &gema_rara.pontos, &gema_rara.pos_x, &gema_rara.pos_y);
    printf("Coletavel criado!Valor: %d pontos. Posicao: X= %.2f, Y=%.2f\n", gema_rara.pontos, gema_rara.pos_x, gema_rara.pos_y);
    return 0;
}