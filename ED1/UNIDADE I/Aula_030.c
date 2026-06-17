#include <stdio.h>
#include <string.h>

struct jogador
{
    char nome[50];
    int vidas;
    int pontuacao;
};
int main()
{
    struct jogador player1;
    player1.vidas = 3;
    player1.pontuacao = 0;
    char nome_digitado[50];
    printf("Digite o nome do seu personagem: \n");
    scanf(" %[^\n]s", nome_digitado);
    strcpy(player1.nome, nome_digitado);
    printf("Personagem criado!Bem vindo(a), %s! Vidas: %d, Pontuacao: %d", player1.nome, player1.vidas, player1.pontuacao);
    return 0;
}