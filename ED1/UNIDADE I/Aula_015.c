#include <stdio.h>
#include <string.h>

int main()
{
    char nome_jogador[50];
    char titulo_conquistado[50];
    printf("Informe o nome do heroi:\n");
    scanf("%[^\n]s", nome_jogador);
    printf("Informe o tutulo conquistado:\n");
    scanf(" %[^\n]s", titulo_conquistado);
    strcat(nome_jogador, " ");
    strcat(nome_jogador, titulo_conquistado);
    printf("O heroi agora e conhecido como: %s", nome_jogador);
    return 0;
}