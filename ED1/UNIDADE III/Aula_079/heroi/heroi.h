#ifndef HEROI_H
#define HEROI_H

//Definir um tipo Heroi usando typedef e uma declaração de struct incompleta
typedef struct heroi Heroi;

//Declarar os protótipos de três funções que operarão sobre os heróis
//uma para alocar dinamicamente um vetor de heróis
Heroi* alocar_herois(int quantidade);

//uma para ler os dados dos heróis
void ler_herois(Heroi* vetor, int quantidade);

//uma para imprimir os dados
void imprimir_herois(Heroi* vetor, int quantidade);

#endif // HEROI_H