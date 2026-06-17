#include <stdio.h>
#include <string.h>
typedef struct
{
    int ID;
    char nome[50];
    int forca;
    int agilidade;
    int inteligencia;
} Personagem;

int buscarPersonagem(Personagem lista[], int n, int IDBusca)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (lista[i].ID == IDBusca)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int n, i, opcao, IDBusca, busca;
    float media;
    printf("--- Campanha ---\n");
    printf("Informe o numero total de personagens: ");
    scanf("%d", &n);
    Personagem dados[n];
    for (i = 0; i < n; i++)
    {
        printf("\nPersonagem %d:\n", i + 1);
        printf("\nID: ");
        scanf("%d", &dados[i].ID);
        printf("\nNome: ");
        scanf(" %s", dados[i].nome);
        printf("--- Atributos ---");
        printf("\nForca: ");
        scanf("%d", &dados[i].forca);
        printf("\nAgilidade: ");
        scanf("%d", &dados[i].agilidade);
        printf("\nInteligencia: ");
        scanf("%d", &dados[i].inteligencia);
    }
    do
    {
        printf("\n --- Menu do Mestre ---\n");
        printf("1- Buscar Personagem\n");
        printf("2- Sair\n");
        scanf("%d", &opcao);
        if (opcao == 1)
        {
            printf("Informe o ID do personagem: ");
            scanf("%d", &IDBusca);
            busca = buscarPersonagem(dados, n, IDBusca);
            if (busca != -1)
            {
                media = (dados[busca].forca + dados[busca].agilidade + dados[busca].inteligencia) / 3;
                printf("Resultado:\n");
                printf("Nome: %s\n", dados[busca].nome);
                printf("Media atributos: %.2f\n", media);
            }
            else
            {
                printf("Erro: Personagem nao encontrado.\n");
            }
        }
        else if (opcao != 2)
        {
            printf("Opcao inválida.");
        }
    } while (opcao != 2);
    printf("Encerrando programa.");
    return 0;
}