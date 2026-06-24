#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "spellbook.h"

// Aloca e retorna um novo grimório estruturado vazio
Spellbook* create_spellbook() {
    Spellbook* book = (Spellbook*) malloc(sizeof(Spellbook));
    if (book != NULL) {
        book->head = NULL; // Inicializa a cabeça da lista com NULL
    }
    return book;
}

// Adiciona um novo feitiço criando um nó e inserindo-o sempre ao final
void add_spell(Spellbook* book, int id, const char* name, int mana_cost) {
    if (book == NULL) return;

    // Aloca o novo nó da lista
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Erro de alocacao de memoria ao adicionar feitico!\n");
        return;
    }

    // Atribui os dados passados por parâmetro
    new_node->spell.id = id;
    strncpy(new_node->spell.name, name, 49);
    new_node->spell.name[49] = '\0';
    new_node->spell.mana_cost = mana_cost;
    new_node->next = NULL;

    // Caso de inserção em lista vazia
    if (book->head == NULL) {
        book->head = new_node;
    } else {
        // Percorre até encontrar o último nó atual
        Node* current = book->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node; // Conecta o novo nó ao fim
    }
}

// Percorre a lista e exibe os detalhes de cada feitiço no formato solicitado
void display_spellbook(Spellbook* book) {
    printf("\n========= GRIMORIO =========\n");
    if (book == NULL || book->head == NULL) {
        printf("O grimorio esta vazio. Nenhum feitico aprendido.\n");
        printf("========================================\n");
        return;
    }

    Node* current = book->head;
    while (current != NULL) {
        printf("ID: [%d], Feitico: [%s], Custo de Mana: [%d]\n", 
               current->spell.id, 
               current->spell.name, 
               current->spell.mana_cost);
        current = current->next;
    }
    printf("========================================\n");
}

void destroy_spellbook(Spellbook* book) {
    if (book == NULL) return;

    Node* current = book->head;
    Node* next_node = NULL;

    printf("\n[Destruindo Grimorio]: Liberando memoria alocada...\n");
    while (current != NULL) {
        next_node = current->next; // Guarda a referência do próximo nó
        free(current);             // Deleta o nó atual
        current = next_node;       // Avança
    }

    free(book); // Libera o ponteiro da struct de controle principal
    printf("[Sucesso]: Toda a memoria foi limpa com seguranca.\n");
}