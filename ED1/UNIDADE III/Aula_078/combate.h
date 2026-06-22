#ifndef COMBATE_H
#define COMBATE_H

//Uma função calcular_ataque_total que recebe o ataque base de um personagem (inteiro) e um bônus de arma (inteiro), e retorna o ataque final.
int calcular_ataque_total(int ataque_base,int bonus_arma);
//Uma função aplicar_dano que recebe a vida atual de um alvo (inteiro) e o dano sofrido (inteiro), e retorna a vida restante.
int aplicar_dano(int vida_atual, int dano_sofrido);

#endif //COMBATE_H