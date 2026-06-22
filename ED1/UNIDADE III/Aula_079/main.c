#include <stdio.h>
#include <stdlib.h>
#include "heroi/heroi.h" //Incluir o cabeçalho heroi/heroi.h

int main() {
    int qtd;
    Heroi* meus_herois = NULL;
    //Conter apenas a lógica principal

    // ler a quantidade de heróis
    printf("Quantos herois você deseja cadastrar? ");
    scanf("%d", &qtd);

    if (qtd <= 0) {
        printf("Quantidade invalida!\n");
        return 0;
    }

    // chamar as funções do módulo heroi para criar o vetor
    meus_herois = alocar_herois(qtd);

    //preenchê-lo com dados
    ler_herois(meus_herois, qtd);

    //e imprimi-lo na tela
    imprimir_herois(meus_herois, qtd);

    free(meus_herois);

    return 0;
}