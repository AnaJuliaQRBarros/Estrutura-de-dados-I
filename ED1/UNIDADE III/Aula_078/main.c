//Deve incluir as bibliotecas padrão (stdio.h) e o seu módulo (combate.h).
#include <stdio.h>
#include "combate.h"

int main() {
    int ataque_base, bonus_espada, vida_inimigo;
    int ataque_total, vida_restante;

    //leia do usuário os seguintes dados: ataque base do herói, bônus da sua espada, vida inicial do inimigo.
    printf("Digite o ataque base do heroi: ");
    scanf("%d", &ataque_base);

    printf("Digite o bônus da espada: ");
    scanf("%d", &bonus_espada);


    printf("Digite a vida inicial do inimigo: ");
    scanf("%d", &vida_inimigo);

    //Chame a função calcular_ataque_total para descobrir o dano que o herói irá causar.
    ataque_total = calcular_ataque_total(ataque_base, bonus_espada);
    //Chame a função aplicar_dano para calcular a vida restante do inimigo após o ataque.
    vida_restante = aplicar_dano(vida_inimigo, ataque_total);

    //Exiba o poder de ataque total do herói e a vida restante do inimigo.
    printf("\n--- Exibicao ---\n");
    printf("Poder de ataque total do heroi: %d\n", ataque_total);
    printf("Vida restante do inimigo: %d\n", vida_restante);

    return 0;
}