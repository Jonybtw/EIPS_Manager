#include <stdio.h>
#include <stdlib.h> // Include this header for the system function
#include "visitas.h"
#include "embaixadores.h"
#include "dados.h"

void mostrarMenu();

int main() {
    carregarDados();
    int opcao;

    do {
        mostrarMenu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // consumir o \n deixado pelo scanf
        system("cls"); // limpar o ecra

        switch (opcao) {
            case 1: listarVisitas(); break;
            case 2: listarEmbaixadores(); break;
            case 3: consultarVisitaPorID(); break;
            case 4: consultarEmbaixadorPorNumero(); break;
            case 5: adicionarVisita(); break;
            case 6: adicionarEmbaixador(); break;
            case 7: autorizarVisita(); break;
            case 8: adicionarEmbaixadoresAVisita(); break;
            case 9: editarEmbaixador(); break;
            case 10: editarVisita(); break;
            case 11: removerEmbaixador(); break;
            case 12: removerVisita(); break;
            case 13: cancelarVisita(); break;
            case 14: confirmarRealizacaoVisita(); break;
            case 15: salvarDados(); printf("Saindo da aplicacao...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 15);

    return 0;
}

void mostrarMenu() {
    printf("\n--- Menu Principal ---\n");

    printf("\n--- Visitas ---\n");
    printf("1 - Listar visitas\n");
    printf("2 - Consultar visita por ID\n");
    printf("3 - Adicionar visita\n");
    printf("4 - Autorizar visita\n");
    printf("5 - Adicionar embaixadores a uma visita\n");
    printf("6 - Editar visita\n");
    printf("7 - Remover visita\n");
    printf("8 - Cancelar visita\n");
    printf("9 - Confirmar realizacao de visita\n");
    
    printf("\n--- Embaixadores ---\n");
    printf("10 - Listar embaixadores\n");
    printf("11 - Consultar embaixador por numero\n");
    printf("12 - Adicionar embaixador\n");
    printf("13 - Editar embaixador\n");
    printf("14 - Remover embaixador\n");

    printf("\n15 - Sair\n");
}

