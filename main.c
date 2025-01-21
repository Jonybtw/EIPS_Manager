#include <stdio.h>
#include <stdlib.h>
#include "visitas.h"
#include "embaixadores.h"
#include "dados.h"

void mostrarMenu();

int main() {
    int opcao;

    do {
        mostrarMenu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // consumir o \n deixado pelo scanf
        system("cls"); // limpar o ecra

        switch (opcao) {
            // visitas
            case 1: listarVisitas(); break;
            case 2: consultarVisitaPorID(); break;
            case 3: adicionarVisita(); break;
            case 4: autorizarVisita(); break;
            case 5: adicionarEmbaixadoresAVisita(); break;
            case 6: editarVisita(); break;
            case 7: removerVisita(); break;
            case 8: cancelarVisita(); break;
            case 9: confirmarRealizacaoVisita(); break;

            // embaixadores
            case 10: listarEmbaixadores(); break;
            case 11: consultarEmbaixadorPorNumero(); break;
            case 12: adicionarEmbaixador(); break;
            case 13: editarEmbaixador(); break;
            case 14: removerEmbaixador(); break;

            // exit
            case 15: gravarDados(); printf("A terminar a aplicação...\n"); break;

            default: printf("Opção inválida!\n");
        }
    } while (opcao != 15);

    return 0;
}


void mostrarMenu() {
    printf("\n");
    printf("=============================================\n");
    printf("                 Menu Principal               \n");
    printf("=============================================\n");
    printf("\n--- Visitas ---\n");
    printf("  1  - Listar visitas\n");
    printf("  2  - Consultar visita por ID\n");
    printf("  3  - Adicionar visita\n");
    printf("  4  - Autorizar visita\n");
    printf("  5  - Adicionar embaixadores a uma visita\n");
    printf("  6  - Editar visita\n");
    printf("  7  - Remover visita\n");
    printf("  8  - Cancelar visita\n");
    printf("  9  - Confirmar realização de visita\n");
    printf("\n--- Embaixadores ---\n");
    printf(" 10  - Listar embaixadores\n");
    printf(" 11  - Consultar embaixador por número\n");
    printf(" 12  - Adicionar embaixador\n");
    printf(" 13  - Editar embaixador\n");
    printf(" 14  - Remover embaixador\n");
    printf("\n 15  - Sair\n");
    printf("\n=============================================\n");
}

