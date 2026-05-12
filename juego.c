#include <stdio.h>
#include <stdlib.h>
#include "GBT/gbt.h"
#include "JUEGO.h"
#include "MATRIZ.h"

void dibujar_cuadrado(JUEGO*, int, int, int);

void constructor_tablero(JUEGO* tablero ,int x, int y, int size_f){
    tablero->size_f = size_f;

    crear_matriz(&tablero->matriz, x, y);
}

void dibujar_tablero(JUEGO* j){
    int i, j,
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
    }
}

void dibujar_cuadrado(JUEGO* t, int pixel_x_inicial, int pixel_y_inicial, int color){
     for(int i = 0; i < t->size_f; i++) {
        for(int j = 0; j < t->size_f; j++) {
            gbt_dibujar_pixel(pixel_x_inicial + i, pixel_y_inicial + j, color);
        }
    }
}
