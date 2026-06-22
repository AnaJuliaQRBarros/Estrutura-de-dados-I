// Inclua as bibliotecas necessárias (stdio.h, stdlib.h)
#include <stdio.h>
#include <stdlib.h>
// e o seu próprio cabeçalho ("personagem.h")
#include "personagem.h"
// Defina a estrutura struct personagem com os seguintes membros: nome (string), classe (string), nivel (int) e hp (int)
struct personagem
{
    char nome[50];
    char classe[50];
    int nivel;
    int hp;
};
//Implemente as quatro funções declaradas no arquivo .h
Personagem *cria_party(int num_membros)
{
    if (num_membros <= 0)
        return NULL;

    Personagem *party = (Personagem *)malloc(num_membros * sizeof(Personagem));
    if (party == NULL)
    {
        printf("Erro de alocaçao de memoria para a equipe!\n");
        exit(1);
    }
    return party;
}

void registra_membros(Personagem *party, int num_membros)
{
    if (party == NULL)
        return;

    for (int i = 0; i < num_membros; i++)
    {
        printf("\n--- Cadastrando Membro %d ---\n", i + 1);

        printf("Nome: ");
        scanf(" %49[^\n]", party[i].nome);

        printf("Classe: ");
        scanf(" %49[^\n]", party[i].classe);

        printf("Nivel: ");
        scanf("%d", &party[i].nivel);

        printf("HP: ");
        scanf("%d", &party[i].hp);
    }
}

void exibe_relatorio(const Personagem *party, int num_membros)
{
    if (party == NULL)
        return;

    printf("\n=========================================\n");
    printf("          RELATORIO DA EQUIPE            \n");
    printf("=========================================\n");

    for (int i = 0; i < num_membros; i++)
    {
        printf("Membro %d: %s | Classe: %s | Nivel: %d | HP: %d\n",
               i + 1, party[i].nome, party[i].classe, party[i].nivel, party[i].hp);
    }
    printf("=========================================\n");
}

void libera_party(Personagem *party)
{
    if (party != NULL)
    {
        free(party);
    }
}