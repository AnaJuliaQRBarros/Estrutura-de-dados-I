#include <stdio.h>
typedef struct
{
    int vida;
    int pontuacao;
} Atributos;
typedef struct
{
    char nome[50];
    Atributos stats;
} Personagem;
int main()
{
    Personagem jogador;
    printf("Digite o nome do personagem:\n");
    scanf("%[^\n]s", jogador.nome);
    jogador.stats.vida = 100;
    jogador.stats.pontuacao = 0;
    printf("Status inical -> Nome: %s | Vida: %d | Pontuacao: %d |\n", jogador.nome, jogador.stats.vida, jogador.stats.pontuacao);
    jogador.stats.pontuacao = jogador.stats.pontuacao + 10;
    jogador.stats.vida = jogador.stats.vida - 25;
    printf("Status final -> Nome: %s | Vida: %d | Pontuacao: %d |", jogador.nome, jogador.stats.vida, jogador.stats.pontuacao);
    return 0;
}