#ifndef TABLERO_H_INCLUDED
#define TABLERO_H_INCLUDED
#include "GRAFICADOR.h"
#include "MATRIZ.h"
#include "PIEZA.h"

typedef struct{
    MATRIZ matriz;
    GRAFICADOR* graficador;
    PIEZA pieza_actual;
    PIEZA pieza_siguiente;
    int *puntos;
    tGBT_Temporizador* reloj_gravedad;
}JUEGO;

void constructor_juego(JUEGO* j, GRAFICADOR* g, int x, int y, double velocidad);
void juego_dibujar(JUEGO* j);
void juego_insertar_pieza(JUEGO* j);
void juego_actualizar(JUEGO* j);
void juego_eliminar(JUEGO* j);
void juego_actualizar_pieza(JUEGO* j);
void juego_entrada(JUEGO* j);


#endif // TABLERO_H_INCLUDED
