#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n_inimigos;
    int *ponteiro_onda;
    printf("Informe a quantidade de inimigos: \n");
    scanf("%d", &n_inimigos);
    ponteiro_onda = (int *)malloc(n_inimigos * sizeof(int));
    if (ponteiro_onda == NULL)
    {
        printf("Erro na alocacao de memoria!\n");
        return 1;
    }
    int i;
    for (i = 0; i < n_inimigos; i++)
    {
        printf("Digite o ID dos inimigos:\n");
        scanf("%d", &ponteiro_onda[i]);
    }
    printf("Onda de inimigos criada com sucesso! IDs: ");
    for (i = 0; i < n_inimigos; i++)
    {
        printf("%d ", ponteiro_onda[i]);
    }
    printf("\n");
    free(ponteiro_onda);
    return 0;
}