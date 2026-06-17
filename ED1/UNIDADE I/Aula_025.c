#include <stdio.h>
#include <stdlib.h>

int main()
{
    int quantidade_inimigos;
    int *status_inimigos;
    printf("Informe a quantidade de inimigos:\n");
    scanf("%d", &quantidade_inimigos);
    status_inimigos = (int *)calloc(quantidade_inimigos, sizeof(int));
    if (status_inimigos == NULL)
    {
        printf("Erro ao alocar memória!");
        return 1;
    }
    int i;
    for (i = 0; i < quantidade_inimigos; i++)
    {
        printf("Inimigos %d: Inativo (%d)\n", i + 1, status_inimigos[i]);
    }
    for (i = 0; i < quantidade_inimigos; i++)
    {
        status_inimigos[i] = 1;
    }
    printf("\n Status apos ativacao:\n");
    for (i = 0; i < quantidade_inimigos; i++)
    {
        printf("Inimigos %d: Ativo (%d)\n", i + 1, status_inimigos[i]);
    }
    free(status_inimigos);
    return 0;
}