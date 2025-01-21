#include "embaixadores.h"
#include "dados.h"
#include "visitas.h"
#include <stdio.h>
#include <string.h>

Embaixador embaixadores[MAX_EMBAIXADORES];
int totalEmbaixadores = 0;

void listarEmbaixadores() {
    printf("--- Lista de Embaixadores ---\n");
    if (totalEmbaixadores == 0) {
        printf("Nenhum embaixador registado.\n");
        return;
    }
    for (int i = 0; i < totalEmbaixadores; i++) {
        printf("Número: %d, Nome: %s, Escola: %s, NIF: %s\n",
               embaixadores[i].numeroEstudante, embaixadores[i].nomeCompleto,
               embaixadores[i].escola, embaixadores[i].nif);
    }
}

void adicionarEmbaixador() {
    if (totalEmbaixadores >= MAX_EMBAIXADORES) {
        printf("Limite máximo de embaixadores atingido.\n");
        return;
    }
    Embaixador novoEmbaixador;

    printf("Número do estudante: ");
    scanf("%d", &novoEmbaixador.numeroEstudante);
    getchar(); // limpa o buffer após scanf

    printf("Nome completo: ");
    fgets(novoEmbaixador.nomeCompleto, sizeof(novoEmbaixador.nomeCompleto), stdin);
    novoEmbaixador.nomeCompleto[strcspn(novoEmbaixador.nomeCompleto, "\n")] = 0; // remove o \n

    printf("Escola (ESTS, ESTB, etc.): ");
    fgets(novoEmbaixador.escola, sizeof(novoEmbaixador.escola), stdin);
    novoEmbaixador.escola[strcspn(novoEmbaixador.escola, "\n")] = 0; // remove o \n

    printf("NIF: ");
    fgets(novoEmbaixador.nif, sizeof(novoEmbaixador.nif), stdin);
    novoEmbaixador.nif[strcspn(novoEmbaixador.nif, "\n")] = 0; // remove o \n

    embaixadores[totalEmbaixadores++] = novoEmbaixador;
    printf("Embaixador adicionado com sucesso!\n");
}

void consultarEmbaixadorPorNumero() {
    if (totalEmbaixadores == 0) {
        printf("--- Consultar Embaixador por Número ---\n");
        printf("Nenhum embaixador registado para consultar.\n");
        return;
    }

    int numeroConsulta;
    printf("--- Consultar Embaixador por Número ---\n");
    printf("Digite o número do estudante: ");
    scanf("%d", &numeroConsulta);

    for (int i = 0; i < totalEmbaixadores; i++) {
        if (embaixadores[i].numeroEstudante == numeroConsulta) {
            printf("\n--- Detalhes do Embaixador ---\n");
            printf("Numero do Estudante: %d\n", embaixadores[i].numeroEstudante);
            printf("Nome: %s\n", embaixadores[i].nomeCompleto);
            printf("Escola: %s\n", embaixadores[i].escola);
            printf("NIF: %s\n", embaixadores[i].nif);
            return;
        }
    }
    printf("--- Consultar Embaixador por Número ---\n");
    printf("Embaixador com número %d não encontrado.\n", numeroConsulta);
}

void editarEmbaixador() {
    if (totalEmbaixadores == 0) {
        printf("--- Editar Embaixador ---\n");
        printf("Nenhum embaixador registado para editar.\n");
        return;
    }

    int numeroEstudante;
    printf("--- Editar Embaixador ---\n");
    printf("Digite o número do estudante do embaixador que deseja editar: ");
    scanf("%d", &numeroEstudante);
    getchar(); // limpa o buffer

    for (int i = 0; i < totalEmbaixadores; i++) {
        if (embaixadores[i].numeroEstudante == numeroEstudante) {
            printf("\n--- Editar Embaixador ---\n");
            printf("1. Nome atual: %s\n", embaixadores[i].nomeCompleto);
            printf("2. Escola atual: %s\n", embaixadores[i].escola);
            printf("3. NIF atual: %s\n", embaixadores[i].nif);

            printf("\nDigite o novo nome completo (ou pressione Enter para manter o atual): ");
            char novoNome[100];
            fgets(novoNome, sizeof(novoNome), stdin);
            if (strcmp(novoNome, "\n") != 0) {
                novoNome[strcspn(novoNome, "\n")] = '\0'; // remove \n
                strcpy(embaixadores[i].nomeCompleto, novoNome);
            }

            printf("Digite a nova escola (ou pressione Enter para manter a atual): ");
            char novaEscola[10];
            fgets(novaEscola, sizeof(novaEscola), stdin);
            if (strcmp(novaEscola, "\n") != 0) {
                novaEscola[strcspn(novaEscola, "\n")] = '\0'; // remove \n
                strcpy(embaixadores[i].escola, novaEscola);
            }

            printf("Digite o novo NIF (ou pressione Enter para manter o atual): ");
            char novoNIF[10];
            fgets(novoNIF, sizeof(novoNIF), stdin);
            if (strcmp(novoNIF, "\n") != 0) {
                novoNIF[strcspn(novoNIF, "\n")] = '\0'; // remove \n
                strcpy(embaixadores[i].nif, novoNIF);
            }

            printf("Embaixador atualizado com sucesso!\n");
            return;
        }
    }
    printf("--- Editar Embaixador ---\n");
    printf("Embaixador com número %d não encontrado.\n", numeroEstudante);
}

void removerEmbaixador() {
    if (totalEmbaixadores == 0) {
        printf("--- Remover Embaixador ---\n");
        printf("Nenhum embaixador registado para remover.\n");
        return;
    }

    int numeroEstudante;
    printf("--- Remover Embaixador ---\n");
    printf("Digite o número do estudante do embaixador que deseja remover: ");
    scanf("%d", &numeroEstudante);

    for (int i = 0; i < totalVisitas; i++) {
        for (int j = 0; j < visitas[i].numeroEmbaixadores; j++) {
            if (visitas[i].embaixadores[j].numeroEstudante == numeroEstudante &&
                strcmp(visitas[i].estado, "autorizada") == 0) {
                printf("O embaixador não pode ser removido porque está associado a uma visita autorizada.\n");
                return;
            }
        }
    }

    for (int i = 0; i < totalEmbaixadores; i++) {
        if (embaixadores[i].numeroEstudante == numeroEstudante) {
            for (int j = i; j < totalEmbaixadores - 1; j++) {
                embaixadores[j] = embaixadores[j + 1];
            }
            totalEmbaixadores--;
            gravarDados(); // gravar os dados após a remoção
            printf("Embaixador removido com sucesso!\n");
            return;
        }
    }
    printf("--- Remover Embaixador ---\n");
    printf("Embaixador com número %d nao encontrado.\n", numeroEstudante);
}