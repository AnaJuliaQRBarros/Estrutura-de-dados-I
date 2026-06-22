//Deve incluir o arquivo combate.h
#include "combate.h"
//Deve conter a implementação (o corpo) das duas funções declaradas em combate.h.
int calcular_ataque_total(int ataque_base,int bonus_arma){
    //calcular_ataque_total simplesmente soma o ataque base e o bônus.
    return ataque_base+bonus_arma;
}
int aplicar_dano(int vida_atual,int dano_sofrido){
    int vida_restante=vida_atual-dano_sofrido;
    //Se a vida ficar negativa, deve retornar 0.
    if(vida_restante<0){
        return 0;
    }
    //aplicar_dano subtrai o dano da vida atual.
    return vida_restante;
}