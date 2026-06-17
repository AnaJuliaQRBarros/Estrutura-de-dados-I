#include <stdio.h>

int main()
{
    int n;
    printf("Informe a energia inicial do Golem: ");
    scanf("%d", &n);
    while (n > 1)
    {
        printf("%d\n", n);
        n = n / 2;
    }
    printf("Energia esgotada: %d\n", n);
    return 0;
}