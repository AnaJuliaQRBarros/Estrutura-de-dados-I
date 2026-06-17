#include <stdio.h>

typedef struct
{
    char nome[50];
    int HP;
} Monstro;

int main()
{
    int n, i;
    printf("Informe a quantidade de monstros: ");
    scanf("%d", &n);
    Monstro Alvo[n];
    for (i = 0; i < n; i++)
    {
        printf("\nMonstro %d\n", i + 1);
        printf("Nome: ");
        scanf("%s", Alvo[i].nome);
        printf("HP: ");
        scanf("%d", &Alvo[i].HP);
    }
    int menor = 0;
    for (i = 1; i < n; i++)
    {
        if (Alvo[i].HP < Alvo[menor].HP)
        {
            menor = i;
        }
    }
    printf("Alvo prioritario: %s (%d HP)\n", Alvo[menor].nome, Alvo[menor].HP);
    return 0;
}