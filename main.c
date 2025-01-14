#include <stdio.h>
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
    printf("1 - Listar visitas\n");
    printf("2 - Listar embaixadores\n");
    printf("3 - Consultar visita por ID\n");
    printf("4 - Consultar embaixador por numero\n");
    printf("5 - Adicionar visita\n");
    printf("6 - Adicionar embaixador\n");
    printf("7 - Autorizar visita\n");
    printf("8 - Adicionar embaixadores a uma visita\n");
    printf("9 - Editar embaixador\n");
    printf("10 - Editar visita\n");
    printf("11 - Remover embaixador\n");
    printf("12 - Remover visita\n");
    printf("13 - Cancelar visita\n");
    printf("14 - Confirmar realizacao de visita\n");
    printf("15 - Sair\n");
}