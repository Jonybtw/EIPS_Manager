#include "dados.h"
#include "embaixadores.h"
#include "visitas.h"
#include <stdio.h>

void gravarDados() {
    // gravar embaixadores no arquivo
    FILE *arquivoEmbaixadores = fopen("embaixadores.txt", "w");
    if (arquivoEmbaixadores == NULL) {
        printf("Erro ao abrir o arquivo para gravar embaixadores.\n");
        return;
    }

    for (int i = 0; i < totalEmbaixadores; i++) {
        fprintf(arquivoEmbaixadores, "%d;%s;%s;%s\n",
                embaixadores[i].numeroEstudante,
                embaixadores[i].nomeCompleto,
                embaixadores[i].escola,
                embaixadores[i].nif);
    }
    fclose(arquivoEmbaixadores);

    // gravar visitas no arquivo
    FILE *arquivoVisitas = fopen("visitas.txt", "w");
    if (arquivoVisitas == NULL) {
        printf("Erro ao abrir o arquivo para gravar visitas.\n");
        return;
    }

    for (int i = 0; i < totalVisitas; i++) {
        fprintf(arquivoVisitas, "%d;%s;%s;%s;%d;",
                visitas[i].idVisita,
                visitas[i].estado,
                visitas[i].local,
                visitas[i].data,
                visitas[i].numeroEmbaixadores);

        for (int j = 0; j < visitas[i].numeroEmbaixadores; j++) {
            fprintf(arquivoVisitas, "%d,", visitas[i].embaixadores[j].numeroEstudante);
        }
        fprintf(arquivoVisitas, "\n");
    }
    fclose(arquivoVisitas);

    printf("Dados salvos com sucesso!\n");
}

void carregarDados() {
    // carregar embaixadores
    FILE *arquivoEmbaixadores = fopen("embaixadores.txt", "r");
    if (arquivoEmbaixadores != NULL) {
        while (!feof(arquivoEmbaixadores)) {
            Embaixador novoEmbaixador;
            if (fscanf(arquivoEmbaixadores, "%d;%99[^;];%9[^;];%9[^\n]\n",
                       &novoEmbaixador.numeroEstudante,
                       novoEmbaixador.nomeCompleto,
                       novoEmbaixador.escola,
                       novoEmbaixador.nif) == 4) {
                embaixadores[totalEmbaixadores++] = novoEmbaixador;
            }
        }
        fclose(arquivoEmbaixadores);
    }

    // carregar visitas
    FILE *arquivoVisitas = fopen("visitas.txt", "r");
    if (arquivoVisitas != NULL) {
        while (!feof(arquivoVisitas)) {
            Visita novaVisita;
            if (fscanf(arquivoVisitas, "%d;%14[^;];%99[^;];%10[^;];%d;",
                       &novaVisita.idVisita,
                       novaVisita.estado,
                       novaVisita.local,
                       novaVisita.data,
                       &novaVisita.numeroEmbaixadores) == 5) {
                for (int j = 0; j < novaVisita.numeroEmbaixadores; j++) {
                    int numeroEstudante;
                    fscanf(arquivoVisitas, "%d,", &numeroEstudante);

                    for (int k = 0; k < totalEmbaixadores; k++) {
                        if (embaixadores[k].numeroEstudante == numeroEstudante) {
                            novaVisita.embaixadores[j] = embaixadores[k];
                            break;
                        }
                    }
                }
                visitas[totalVisitas++] = novaVisita;
            }
        }
        fclose(arquivoVisitas);
    }

    printf("Dados carregados com sucesso!\n");
}