#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *duracao_fumaca;
    duracao_fumaca = malloc(sizeof(int));
    if (duracao_fumaca == NULL)
    {
        printf("Erro ao alocar memória");
        return 1;
    }
    *duracao_fumaca = 5;
    printf("Bomba de fumaca ativada! Duracao: %d segundos.\n", *duracao_fumaca);
    free(duracao_fumaca);
    *duracao_fumaca = NULL;
    printf("\n");
    printf("A fumaca dissipou.");
    return 0;
}