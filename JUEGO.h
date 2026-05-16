#ifndef TABLERO_H_INCLUDED
#define TABLERO_H_INCLUDED
#include "GRAFICADOR.h"
#include "MATRIZ.h"
#include "PIEZA.h"

typedef struct{
    MATRIZ matriz;
    GRAFICADOR* graficador;
    FIGURA figura;
    int *puntos;
    int *dificultad;

}JUEGO;

void constructor_juego(JUEGO* j, GRAFICADOR* g, int x, int y, int* dificultad);
void dibujar_juego(JUEGO* j);

#endif // TABLERO_H_INCLUDED
