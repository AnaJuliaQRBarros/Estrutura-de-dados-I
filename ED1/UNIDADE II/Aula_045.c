#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char nome[50];
    int nivel;
    float vida;
    float mana;
} Personagem;
int main()
{
    int opcao;
    FILE *arquivo = fopen("savegame.sav", "wb");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!");
        return 1;
    }
    do
    {
        printf("\n----- MENU -----\n");
        printf("1- Criar Novo Personagem\n");
        printf("2- Sair\n");
        printf("Selecione uma das opcoes: \n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            Personagem informacao;
            printf("Insira as informacoes do personagem!\n");
            printf("Nome: ");
            scanf(" %[^\n]", informacao.nome);
            printf("Nivel: ");
            scanf("%d", &informacao.nivel);
            printf("Vida: ");
            scanf("%f", &informacao.vida);
            printf("Mana: ");
            scanf("%f", &informacao.mana);
            fwrite(&informacao, sizeof(Personagem), 1, arquivo);
            break;
        case 2:
            printf("Encerrado.\n");
            break;
        default:
            printf("Opcao Invalida!");
        }
    } while (opcao != 2);
    fclose(arquivo);
    return 0;
}