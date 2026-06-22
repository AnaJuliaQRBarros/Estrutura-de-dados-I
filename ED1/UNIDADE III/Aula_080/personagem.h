#ifndef PERSONAGEM_H
#define PERSONAGEM_H

//Use typedef struct personagem Personagem; para criar um tipo opaco
typedef struct personagem Personagem;

//Declare os protótipos das seguintes funções:
//Aloca dinamicamente memória para a equipe
Personagem* cria_party(int num_membros);
//Lê os dados de cada membro da equipe
void registra_membros(Personagem* party, int num_membros);
//Exibe os dados de todos os membros da equipe
void exibe_relatorio(const Personagem* party, int num_membros);
//Libera a memória alocada para a equipe
void libera_party(Personagem* party);

#endif // PERSONAGEM_H