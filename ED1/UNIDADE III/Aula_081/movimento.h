#ifndef MOVIMENTO_H
#define MOVIMENTO_H

//Crie uma struct, usando typedef, chamada Movimento para armazenar o ID (int) e o nome (char nome[50]) de um golpe.
typedef struct {
    int id;
    char nome[50];
} Movimento;
//Crie as structs necessárias para implementar uma lista encadeada (No e Lista).
typedef struct no {
    Movimento dado;
    struct no* proximo;
} No;
//Crie as structs necessárias para implementar uma lista encadeada (No e Lista).
typedef struct {
    No* inicio;
} Lista;
// Função auxiliar para inicializar a lista
void inicializa_lista(Lista* l);
void insere_inicio(Lista* l, int id, const char* nome);
void libera_lista(Lista* l);

#endif // MOVIMENTO_H