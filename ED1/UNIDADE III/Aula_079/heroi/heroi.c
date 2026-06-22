#include <stdio.h>
#include <stdlib.h>
//Incluir o seu próprio cabeçalho heroi.h.
#include "heroi.h"

//Definir a struct heroi completa com os campos: nome (string), hp (inteiro) e ataque (inteiro)
struct heroi {
    char nome[50];
    int hp;
    int ataque;
};

//Implementar as três funções cujos protótipos foram declarados no arquivo .h
Heroi* alocar_herois(int quantidade) {
    Heroi* vetor = (Heroi*) malloc(quantidade * sizeof(Heroi));
    if (vetor == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    return vetor;
}

void ler_herois(Heroi* vetor, int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        printf("\n--- Cadastrando Heroi %d ---\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", vetor[i].nome);
        
        printf("HP: ");
        scanf("%d", &vetor[i].hp);
        
        printf("Ataque: ");
        scanf("%d", &vetor[i].ataque);
    }
}

void imprimir_herois(Heroi* vetor, int quantidade) {
    printf("\n====== LISTA DE HEROIS ======");
    for (int i = 0; i < quantidade; i++) {
        printf("\nHeroi %d: %s\n", i + 1, vetor[i].nome);
        printf("HP: %d | Ataque: %d\n", vetor[i].hp, vetor[i].ataque);
        printf("-----------------------------");
    }
    printf("\n");
}