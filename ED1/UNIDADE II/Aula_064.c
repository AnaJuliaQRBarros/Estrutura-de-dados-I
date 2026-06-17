#include <stdio.h>

int main()
{
    int n, i, j, chave;
    printf("Informe a quantidade de fragmentos: ");
    scanf("%d", &n);
    int fragmentos[n];
    printf("Informe os poderes dos fragmentos:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &fragmentos[i]);
    }
    for (i = 1; i < n; i++)
    {
        chave = fragmentos[i];
        j = i - 1;
        while (j >= 0 && fragmentos[j] > chave)
        {
            fragmentos[j + 1] = fragmentos[j];
            j--;
        }
        fragmentos[j + 1] = chave;
    }
    printf("\nFragmentos ordenados:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", fragmentos[i]);
    }
    printf("\n");
    return 0;
}