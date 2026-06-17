#include <stdio.h>
int calcularDanoEco(int n)
{
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }
    return calcularDanoEco(n - 1) + calcularDanoEco(n - 2);
}
int main()
{
    int numerogolpe;
    int danobonus;
    printf("Informe o numero do golpe: ");
    scanf("%d", &numerogolpe);
    if (numerogolpe <= 0)
    {
        printf("Insira um numero inteiro positivo.\n");
        return 1;
    }
    danobonus = calcularDanoEco(numerogolpe);
    printf("O dano bonus para o golpe %d e: %d\n", numerogolpe, danobonus);
    return 0;
}