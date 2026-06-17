#include <stdio.h>
int danocasquata(int nivel)
{
    if (nivel <= 1)
    {
        return 1;
    }
    return nivel + danocasquata(nivel - 1);
}
int main()
{
    int nivelmago, danototal;
    printf("\n--- Feiticos ---\n");
    printf("Informe o nivel do mago para o Ataque em Cascata: ");
    scanf("%d", &nivelmago);
    if (nivelmago <= 0)
    {
        printf("Nivel invalido!\n");
        return 1;
    }
    danototal = danocasquata(nivelmago);
    printf("Dano total do feitico: %d\n", danototal);
    return 0;
}