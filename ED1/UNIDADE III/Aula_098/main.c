#include <stdio.h>
#include <stdlib.h>
#include "guilda.h"

int main() {
    // 1. Executa o salvamento do arquivo de teste com os dados fixos
    salvar_guilda_teste();

    // 2. Declara a lista principal e recebe o retorno da função de carregamento
    Lista minha_guilda;
    minha_guilda = carregar_guilda();

    // 3. Exibe a lista para atestar o sucesso da operação de leitura binária
    mostrar_guilda(minha_guilda);

    // 4. Libera a memória alocada dinamicamente antes de fechar o programa
    No *atual = minha_guilda.inicio;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }

    return 0;
}