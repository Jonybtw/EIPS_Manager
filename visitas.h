#ifndef VISITAS_H
#define VISITAS_H

#include "embaixadores.h"

#define MAX_VISITAS 1000

typedef struct {
    int idVisita;
    Embaixador embaixadores[9]; // até 9 embaixadores por visita
    int numeroEmbaixadores;
    char estado[15]; // "em planeamento", "autorizada", etc.
    char local[100];
    char data[11]; // formato "dd/mm/aaaa"
} Visita;

extern Visita visitas[MAX_VISITAS];
extern int totalVisitas;

void listarVisitas();
void adicionarVisita();
void consultarVisitaPorID();
void autorizarVisita();
void adicionarEmbaixadoresAVisita();
void editarVisita();
void removerVisita();
void cancelarVisita();
void confirmarRealizacaoVisita();

#endif