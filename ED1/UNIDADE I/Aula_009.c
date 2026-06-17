#include <stdio.h>

int main()
{
    int moedas_coletadas[5] = {10, 50, 20, 5, 100};
    int pontuacao_total = 0;
    int *ponteiro_moedas = moedas_coletadas;
    int *fim_vetor = moedas_coletadas + 5;

    for (ponteiro_moedas = moedas_coletadas; ponteiro_moedas < fim_vetor; ponteiro_moedas++)
    {
        pontuacao_total = *ponteiro_moedas + pontuacao_total;
    }
    printf("Pontuacao total do nivel: %d\n", pontuacao_total);
    return 0;
}