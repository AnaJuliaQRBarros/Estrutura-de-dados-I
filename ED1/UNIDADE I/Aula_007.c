#include <stdio.h>

void ler_cenario(int tamanho_fileira, int *cenario)
{
    int i;
    for (i = 0; i < tamanho_fileira; i++)
    {
        printf("Digite o valor da posicao %d (0 ou 1):\n", i);
        scanf("%d", (cenario + i));
    }
}
int main()
{
    int tamanho_fileira;
    int i;

    printf("Digite o numero de blocos do cenario:\n");
    scanf("%d", &tamanho_fileira);
    int cenario[tamanho_fileira];
    ler_cenario(tamanho_fileira, cenario);
    for (i = 0; i < tamanho_fileira; i++)
    {
        if (*(cenario + i) == 1)
        {
            *(cenario + i) = 2;
            break;
        }
    }
    printf("Cenario modificado:\n");
    for (i = 0; i < tamanho_fileira; i++)
    {
        printf("%d", *(cenario + i));
    }
    return 0;
}