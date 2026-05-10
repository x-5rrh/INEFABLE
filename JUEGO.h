#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
#include "TABLERO.h"
#include "FIGURA.h"


typedef struct{
    TABLERO tablero;
    FIGURA figura;
    int estado_juego;
    int dificultad;
    int velocidad;
    int puntos;
    int modo_juego;
    int tamanio_bloque;
    int tamanio_ancho_ventana;
    int tamanio_alto_ventana;
}JUEGO;

void cambiar_estado(JUEGO* juego, int estado);
void iniciar_juego(JUEGO* juego);

#endif // JUEGO_H_INCLUDED
