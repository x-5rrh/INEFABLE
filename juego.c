#include <stdio.h>
#include <stdlib.h>
#include "GBT/gbt.h"
#include "JUEGO.h"
#include "MATRIZ.h"

void constructor_juego(JUEGO* j, GRAFICADOR* graficador_ajeno ,int x, int y){
    j->graficador = graficador_ajeno;
    crear_matriz_vacia(&j->matriz, x, y);
}

void dibujar_juego(JUEGO* j){
    /*int i, j,
    pixel_x_inicial ,
    pixel_y_inicial;

    for(int fil = 0; fil < t->filas; fil++){
        for(int col = 0; col < t->columnas; col++){
            pixel_x_inicial = ancla_x + (col * t->size_f);
            pixel_y_inicial = ancla_y + (fil * t->size_f);
            if (t->tablero[fil][col] == 1) {
                dibujar_cuadrado(t, pixel_x_inicial, pixel_y_inicial, 10);
            }else{
                dibujar_cuadrado(t, pixel_x_inicial, pixel_y_inicial, 7);
            }
        }
    } */
}
