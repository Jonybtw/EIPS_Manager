#include "visitas.h"
#include "embaixadores.h"
#include "dados.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

Visita visitas[MAX_VISITAS];
int totalVisitas = 0;

void listarVisitas() {
    printf("--- Lista de Visitas ---\n");
    if (totalVisitas == 0) {
        printf("Nenhuma visita registada.\n");
        return;
    }
    for (int i = 0; i < totalVisitas; i++) {
        printf("ID: %d, Estado: %s, Local: %s, Data: %s\n",
               visitas[i].idVisita, visitas[i].estado, visitas[i].local, visitas[i].data);
    }
}

void adicionarVisita() {
    if (totalVisitas >= MAX_VISITAS) {
        printf("Limite máximo de visitas atingido.\n");
        return;
    }
    Visita novaVisita;
    novaVisita.idVisita = totalVisitas + 1;
    strcpy(novaVisita.estado, "em planeamento");
    novaVisita.numeroEmbaixadores = 0;

    printf("--- Adicionar Visita ---\n");
    printf("Local da visita: ");
    fgets(novaVisita.local, sizeof(novaVisita.local), stdin);
    novaVisita.local[strcspn(novaVisita.local, "\n")] = 0;

    printf("Data da visita (dd/mm/aaaa): ");
    fgets(novaVisita.data, sizeof(novaVisita.data), stdin);
    novaVisita.data[strcspn(novaVisita.data, "\n")] = 0;

    visitas[totalVisitas++] = novaVisita;
    printf("Visita adicionada com sucesso!\n");
}

void consultarVisitaPorID() {
    if (totalVisitas == 0) {
        printf("--- Consultar Visita por ID ---\n");
        printf("Nenhuma visita registada para consultar.\n");
        return;
    }

    listarVisitas();
    printf("\n");

    int idConsulta;
    printf("--- Consultar Visita por ID ---\n");
    printf("Digite o ID da visita: ");
    scanf("%d", &idConsulta);

    for (int i = 0; i < totalVisitas; i++) {
        if (visitas[i].idVisita == idConsulta) {
            printf("\n--- Detalhes da Visita ---\n");
            printf("ID: %d\n", visitas[i].idVisita);
            printf("Estado: %s\n", visitas[i].estado);
            printf("Local: %s\n", visitas[i].local);
            printf("Data: %s\n", visitas[i].data);
            printf("Número de Embaixadores: %d\n", visitas[i].numeroEmbaixadores);
            return;
        }
    }
    printf("Visita com ID %d não encontrada.\n", idConsulta);
}

void autorizarVisita() {
    if (totalVisitas == 0) {
        printf("--- Autorizar Visita ---\n");
        printf("Nenhuma visita registada para autorizar.\n");
        return;
    }

    listarVisitas();
    printf("\n");

    int idConsulta;
    printf("--- Autorizar Visita ---\n");
    printf("Digite o ID da visita a autorizar: ");
    scanf("%d", &idConsulta);

    for (int i = 0; i < totalVisitas; i++) {
        if (visitas[i].idVisita == idConsulta) {
            if (strcmp(visitas[i].estado, "em planeamento") != 0) {
                printf("A visita com ID %d não esta em planeamento. Não pode ser autorizada.\n", idConsulta);
                return;
            }

            if (visitas[i].numeroEmbaixadores < 2) {
                printf("A visita com ID %d não tem o mínimo de 2 embaixadores. Não pode ser autorizada.\n", idConsulta);
                return;
            }

            strcpy(visitas[i].estado, "autorizada");
            printf("A visita com ID %d foi autorizada com sucesso!\n", idConsulta);
            return;
        }
    }
    printf("Visita com ID %d não encontrada.\n", idConsulta);
}

void adicionarEmbaixadoresAVisita() {
    if (totalVisitas == 0) {
        printf("--- Adicionar Embaixador a Visita ---\n");
        printf("Nenhuma visita registada para adicionar embaixadores.\n");
        return;
    }

    listarVisitas();
    printf("\n");

    if (totalEmbaixadores == 0) {
        printf("--- Adicionar Embaixador a Visita ---\n");
        printf("Nenhum embaixador registado para associar a uma visita.\n");
        return;
    }

    int idVisita;
    printf("--- Adicionar Embaixador a Visita ---\n");
    printf("Digite o ID da visita para adicionar embaixadores: ");
    scanf("%d", &idVisita);

    for (int i = 0; i < totalVisitas; i++) {
        if (visitas[i].idVisita == idVisita) {
            if (visitas[i].numeroEmbaixadores >= 9) {
                printf("A visita já atingiu o limite de 9 embaixadores.\n");
                return;
            }

            printf("\n--- Lista de Embaixadores Disponíveis ---\n");
            for (int j = 0; j < totalEmbaixadores; j++) {
                printf("%d. %s (Número: %d)\n", j + 1, embaixadores[j].nomeCompleto, embaixadores[j].numeroEstudante);
            }

            int escolha;
            printf("Escolha o número do embaixador para adicionar (ou 0 para sair): ");
            scanf("%d", &escolha);

            if (escolha == 0) {
                printf("Operação cancelada.\n");
                return;
            }

            if (escolha < 1 || escolha > totalEmbaixadores) {
                printf("Opção inválida.\n");
                return;
            }

            visitas[i].embaixadores[visitas[i].numeroEmbaixadores] = embaixadores[escolha - 1];
            visitas[i].numeroEmbaixadores++;

            printf("Embaixador '%s' adicionado a visita com sucesso!\n", embaixadores[escolha - 1].nomeCompleto);
            return;
        }
    }
    printf("Visita com ID %d não encontrada.\n", idVisita);
}

void editarVisita() {
    if (totalVisitas == 0) {
        printf("--- Editar Visita ---\n");
        printf("Nenhuma visita cadastrada para editar.\n");
        return;
    }

    listarVisitas();
    printf("\n");

    int idVisita;
    printf("--- Editar Visita ---\n");
    printf("Digite o ID da visita que deseja editar: ");
    scanf("%d", &idVisita);
    getchar(); // limpa o buffer

    for (int i = 0; i < totalVisitas; i++) {
        if (visitas[i].idVisita == idVisita) {
            printf("\n--- Editar Visita ---\n");
            printf("1. Local atual: %s\n", visitas[i].local);
            printf("2. Data atual: %s\n", visitas[i].data);
            printf("3. Estado atual: %s\n", visitas[i].estado);

            printf("\nDigite o novo local (ou pressione Enter para manter o atual): ");
            char novoLocal[100];
            fgets(novoLocal, sizeof(novoLocal), stdin);
            if (strcmp(novoLocal, "\n") != 0) {
                novoLocal[strcspn(novoLocal, "\n")] = '\0'; // remove \n
                strcpy(visitas[i].local, novoLocal);
            }

            printf("Digite a nova data (ou pressione Enter para manter a atual): ");
            char novaData[11];
            fgets(novaData, sizeof(novaData), stdin);
            if (strcmp(novaData, "\n") != 0) {
                novaData[strcspn(novaData, "\n")] = '\0'; // remove \n
                strcpy(visitas[i].data, novaData);
            }

            printf("Digite o novo estado (ou pressione Enter para manter o atual): ");
            char novoEstado[15];
            fgets(novoEstado, sizeof(novoEstado), stdin);
            if (strcmp(novoEstado, "\n") != 0) {
                novoEstado[strcspn(novoEstado, "\n")] = '\0'; // remove \n
                strcpy(visitas[i].estado, novoEstado);
            }

            printf("Visita atualizada com sucesso!\n");
            return;
        }
    }
    printf("Visita com ID %d não encontrada.\n", idVisita);
}

void removerVisita() {
    if (totalVisitas == 0) {
        printf("--- Remover Visita ---\n");
        printf("Nenhuma visita registada para remover.\n");
        return;
    }

    listarVisitas();
    printf("\n");

    int idVisita;
    printf("--- Remover Visita ---\n");
    printf("Digite o ID da visita que deseja remover: ");
    scanf("%d", &idVisita);

    for (int i = 0; i < totalVisitas; i++) {
        if (visitas[i].idVisita == idVisita) {
            if (strcmp(visitas[i].estado, "realizada") == 0) {
                printf("A visita não pode ser removida porque ja foi realizada.\n");
                return;
            }

            for (int j = i; j < totalVisitas - 1; j++) {
                visitas[j] = visitas[j + 1];
            }
            totalVisitas--;
            gravarDados(); // guardar os dados após a remoção
            printf("Visita removida com sucesso!\n");
            return;
        }
    }
    printf("Visita com ID %d não encontrada.\n", idVisita);
}

void cancelarVisita() {
    if (totalVisitas == 0) {
        printf("--- Cancelar Visita ---\n");
        printf("Nenhuma visita registada para cancelar.\n");
        return;
    }

    listarVisitas();
    printf("\n");

    int idVisita;
    printf("--- Cancelar Visita ---\n");
    printf("Digite o ID da visita que deseja cancelar: ");
    scanf("%d", &idVisita);

    for (int i = 0; i < totalVisitas; i++) {
        if (visitas[i].idVisita == idVisita) {
            if (strcmp(visitas[i].estado, "realizada") == 0) {
                printf("A visita ja foi realizada e nao pode ser cancelada.\n");
                return;
            }

            strcpy(visitas[i].estado, "cancelada");
            gravarDados();
            printf("Visita cancelada com sucesso!\n");
            return;
        }
    }
    printf("Visita com ID %d não encontrada.\n", idVisita);
}

void confirmarRealizacaoVisita() {
    if (totalVisitas == 0) {
        printf("--- Confirmar Realização de Visita ---\n");
        printf("Nenhuma visita registada para confirmar.\n");
        return;
    }

    listarVisitas();
    printf("\n");

    int idVisita;
    printf("--- Confirmar Realização de Visita ---\n");
    printf("Digite o ID da visita para confirmar: ");
    scanf("%d", &idVisita);

    for (int i = 0; i < totalVisitas; i++) {
        if (visitas[i].idVisita == idVisita) {
            if (strcmp(visitas[i].estado, "autorizada") != 0) {
                printf("A visita não está autorizada e não pode ser confirmada.\n");
                return;
            }

            // obter a data atual
            time_t t = time(NULL);
            struct tm *hoje = localtime(&t);

            int dia, mes, ano;
            sscanf(visitas[i].data, "%d/%d/%d", &dia, &mes, &ano);

            if (ano > hoje->tm_year + 1900 || 
               (ano == hoje->tm_year + 1900 && mes > hoje->tm_mon + 1) ||
               (ano == hoje->tm_year + 1900 && mes == hoje->tm_mon + 1 && dia > hoje->tm_mday)) {
                printf("A visita ainda não pode ser confirmada. A data da visita deve ser anterior à data atual.\n");
                return;
            }

            strcpy(visitas[i].estado, "realizada");
            gravarDados();
            printf("Visita confirmada como realizada com sucesso!\n");
            return;
        }
    }
    printf("Visita com ID %d não encontrada.\n", idVisita);
}