#include <stdio.h>
#include "spellbook.h"

int main() {
    // 1. Cria e inicializa o grimório
    Spellbook* my_book = create_spellbook();

    // 2. Adiciona pelo menos três feitiços distintos
    add_spell(my_book, 1, "Bola de Fogo", 45);
    add_spell(my_book, 2, "Seta de Gelo", 25);
    add_spell(my_book, 3, "Meteoro Astrologico", 90);

    // 3. Exibe o grimório completo no terminal
    display_spellbook(my_book);

    // 4. Destrói o grimório limpando toda a memória alocada
    destroy_spellbook(my_book);

    return 0;
}