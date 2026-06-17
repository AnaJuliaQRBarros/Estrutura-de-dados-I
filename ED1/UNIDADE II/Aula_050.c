#include <stdio.h>
int main()
{
    float forca = 3;
    float bonus_arma = 2;
    float bonus_feitico = 4;
    float dano_total = 0;
    dano_total = forca + bonus_arma + bonus_feitico;
    printf("%.2f\n", dano_total);
    return 0;
}