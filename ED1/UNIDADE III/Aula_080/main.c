//O main.c deve incluir apenas stdio.h e "personagem.h"
#include <stdio.h>
#include "personagem.h"

int main() {
    int num_membros;
    // Perguntar ao usuário quantos membros a equipe terá
    printf("Quantos membros a sua equipe tera? ");
    if (scanf("%d", &num_membros) != 1 || num_membros <= 0) {
        printf("Quantidade invalida!\n");
        return 1;
    }
    //Chamar cria_party() para alocar a equipe
    Personagem* minha_party = cria_party(num_membros);
    //Chamar registra_membros() para preencher os dados dos heróis
    registra_membros(minha_party, num_membros);
    //Chamar exibe_relatorio() para mostrar as informações da equipe na tela
    exibe_relatorio(minha_party, num_membros);
    //Chamar libera_party() para liberar a memória antes de encerrar
    libera_party(minha_party);
    minha_party = NULL;
    return 0;
}