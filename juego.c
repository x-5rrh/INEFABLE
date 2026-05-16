#include <stdio.h>
#include <stdlib.h>
#include "GBT/gbt.h"
#include "JUEGO.h"
#include "MATRIZ.h"

static int generador_aleatorio();

void constructor_juego(JUEGO* j, GRAFICADOR* graficador_ajeno ,int x, int y, int *dificultad){
    j->graficador = graficador_ajeno;
    j->dificultad = dificultad;
    crear_pieza(&j->pieza_actual, generador_aleatorio(), 3, 0);
    crear_pieza(&j->pieza_siguiente, generador_aleatorio(), 3, 0);
    crear_matriz_vacia(&j->matriz, x, y);

    graficar_matriz_consola(&j->pieza_actual.pieza);
}

void dibujar_juego(JUEGO* j){
    int tamanio_bloque = (j->graficador->screen_y - 20) / j->matriz.filas;
    //grafico de tablero
    graficar_matriz(j->graficador, &j->matriz, (j->graficador->mid_screen_x - (j->matriz.columnas * tamanio_bloque / 2)), 10 , tamanio_bloque);
    //grafico de pieza
    graficar_matriz(j->graficador, &j->pieza_actual.pieza, j->graficador->mid_screen_x, j->graficador->mid_screen_y, tamanio_bloque);
}

static int generador_aleatorio(){
    return rand() % 7 + 1;
}
