#include <stdio.h>

int main()
{
    int tempos[5] = {120, 125, 130, 142, 150};
    int novotemp;
    int i;
    printf("Informe o novo tempo: ");
    scanf("%d", &novotemp);
    if (novotemp < tempos[4])
    {
        for (i = 4; i > 0 && novotemp < tempos[i - 1]; i--)
        {
            tempos[i] = tempos[i - 1];
        }
        tempos[i] = novotemp;
    }
    printf("\nPlacar atualizado:\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", tempos[i]);
    }
    printf("\n");
    return 0;
}