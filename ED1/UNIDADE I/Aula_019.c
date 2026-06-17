#include <stdio.h>
#include <stdlib.h>

int main()
{
    float *ponteiro_altura_salto_duplo = NULL;
    printf("Jogador ainda nao possui o Salto Duplo.\n");
    ponteiro_altura_salto_duplo = (float *)malloc(sizeof(float));
    printf("\n");
    if (ponteiro_altura_salto_duplo == NULL)
    {
        printf("Erro ao adquirir a habilidade!\n");
        return 1;
    }
    else
    {
        printf("Habilidade salto duplo adquirida com sucesso!\n");
    }
    *ponteiro_altura_salto_duplo = 15.5;
    printf("\n");
    printf("Pena Dourada coletada! Altura do Salto Duplo: %.2f", *ponteiro_altura_salto_duplo);
    free(ponteiro_altura_salto_duplo); // Utilizado para liberar memória quando o power-up não fosse mais necessário.
    return 0;
}