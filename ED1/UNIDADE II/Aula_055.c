#include <stdio.h>
typedef struct
{
    int ID;
    char nickname[50];
    int pontos_reputacao;
} Jogador;
int buscaBinaria(int idProcurado, Jogador vetor[], int n)
{
    int inicio = 0;
    int fim = n - 1;
    int meio;
    while (inicio <= fim)
    {
        meio = inicio + (fim - inicio) / 2;
        if (vetor[meio].ID == idProcurado)
        {
            return meio;
        }
        if (vetor[meio].ID < idProcurado)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }
    return -1;
}
int main()
{
    int n, i, opcao, idBusca;
    printf("Informe o numero de jogadores a serem cadastrados: ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("Quantidade invalida.\n");
        return 1;
    }
    Jogador GM[n];
    printf("--- CADASTRO ---\n");
    for (i = 0; i < n; i++)
    {
        printf("--- JOGADOR %d ---\n", i + 1);
        printf("ID: ");
        scanf("%d", &GM[i].ID);
        printf("NICKNAME: ");
        scanf(" %s", GM[i].nickname);
        printf("PONTOS DE REPUTACAO: ");
        scanf("%d", &GM[i].pontos_reputacao);
    }
    do
    {
        printf("\n--- MENU ---\n");
        printf("1- ADICIONAR REPUTACAO.\n");
        printf("2- SAIR.\n");
        printf("Digite uma opcao: ");
        scanf("%d", &opcao);
        if (opcao == 1)
        {
            printf("\n--- OPCAO %d SELECIONADA ---\n", opcao);
            printf("ID DO JOGADOR: ");
            scanf("%d", &idBusca);
            int indice = buscaBinaria(idBusca, GM, n);
            if (indice != -1)
            {
                GM[indice].pontos_reputacao += 100;
                printf("NICKNAME: %s, NOVA REPUTACAO: %d\n", GM[indice].nickname, GM[indice].pontos_reputacao);
            }
            else
            {
                printf("JOGADOR COM ID %d NAO ENCONTRADO.\n", idBusca);
            }
        }
        else if (opcao != 2)
        {
            printf("OPCAO INVALIDA.\n");
        }
    } while (opcao != 2);
    printf("ENCERRANDO.\n");
    return 0;
}