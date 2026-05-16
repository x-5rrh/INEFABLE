#include <stdio.h>
#include <stdlib.h>
#include "GBT/gbt.h"
#include "JUEGO.h"
#include "MATRIZ.h"

void constructor_juego(JUEGO* j, GRAFICADOR* graficador_ajeno ,int x, int y, int *dificultad){
    j->graficador = graficador_ajeno;
    j->dificultad = dificultad;
    crear_matriz_vacia(&j->matriz, x, y);
}

void dibujar_juego(JUEGO* j){
    int tamanio_bloque = (j->graficador->screen_y - 20) / j->matriz.filas;

    graficar_matriz(j->graficador, &j->matriz, (j->graficador->mid_screen_x - (j->matriz.columnas * tamanio_bloque / 2)), 10 , tamanio_bloque);
}
