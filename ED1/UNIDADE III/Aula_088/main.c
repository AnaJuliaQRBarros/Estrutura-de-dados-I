#include <stdio.h>
#include "lista.h"

int main() {
    Lista lista;
    lista.inicio = NULL;
    int op;

    do {
        menu();
        scanf("%d", &op);

        switch(op) {
            case 1: {
                Estudante e;
                ler(&e);
                inserir_inicio(&lista, e);
                break;
            }
            case 2: {
                Estudante e;
                ler(&e);
                inserir_fim(&lista, e);
                break;
            }
            case 5:
                mostrar(lista);
                break;
            case 7:
                deletar_inicio(&lista);
                break;
            case 8:
                deletar_fim(&lista);
                break;
            case 9:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (op != 9);

    return 0;
}