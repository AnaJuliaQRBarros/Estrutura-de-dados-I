#ifndef MISSAO_H
#define MISSAO_H

//Defina uma struct para representar uma Missao, contendo um id (inteiro), um titulo (string) e um status (string)
typedef struct {
    int id;
    char titulo[50];
    char status[30];
} Missao;

//Utilize uma lista encadeada para armazenar as missões
typedef struct no {
    Missao dado;
    struct no* proximo;
} No;

typedef struct {
    No* inicio;
} DiarioMissoes;

void inicializa_diario(DiarioMissoes* d);
void adicionar_missao(DiarioMissoes* d, int id, const char* titulo, const char* status);
void mostrar_missoes(const DiarioMissoes* d);
No* pesquisar_missao(const DiarioMissoes* d, int id);
void libera_diario(DiarioMissoes* d);

#endif // MISSAO_H