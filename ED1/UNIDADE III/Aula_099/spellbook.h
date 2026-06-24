#ifndef SPELLBOOK_H
#define SPELLBOOK_H

// 1. Struct que armazena os dados brutos do feitiço
typedef struct {
    int id;
    char name[50];
    int mana_cost;
} Spell;

// Estrutura do nó da lista encadeada
typedef struct Node {
    Spell spell;
    struct Node *next;
} Node;

// 2. Struct de controle do grimório para simplificar os ponteiros
typedef struct {
    Node *head;
} Spellbook;

//Protótipos das Funções
Spellbook* create_spellbook();
void add_spell(Spellbook* book, int id, const char* name, int mana_cost);
void display_spellbook(Spellbook* book);
void destroy_spellbook(Spellbook* book);

#endif // SPELLBOOK_H