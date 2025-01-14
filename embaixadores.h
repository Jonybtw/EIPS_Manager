#ifndef EMBAIXADORES_H
#define EMBAIXADORES_H

#define MAX_EMBAIXADORES 100

typedef struct {
    int numeroEstudante;
    char escola[10];
    char nomeCompleto[100];
    char nif[10];
} Embaixador;

extern Embaixador embaixadores[MAX_EMBAIXADORES];
extern int totalEmbaixadores;

void listarEmbaixadores();
void adicionarEmbaixador();
void consultarEmbaixadorPorNumero();
void editarEmbaixador();
void removerEmbaixador();

#endif