#include <stdio.h>
#include <stdlib.h>
#include "GBT/gbt.h"
#include "TABLERO.h"
#include "JUEGO.h"

void dibujar_cuadrado(TABLERO*, int, int, int);

void iniciar_tablero(TABLERO* tablero ,int x, int y, int size_f){
    tablero->filas = x;
    tablero->columnas = y;
    tablero->size_f = size_f;

    tablero->tablero = malloc(x * sizeof(int*));

    for(int i = 0; i < x; i++){
        tablero->tablero[i] = calloc(y, sizeof(int));
    }
}

void dibujar_tablero(TABLERO* t, int offset_x, int offset_y){
    int i, j,
    total_tablero_x = t->columnas * t->size_f,
    total_tablero_y = t->filas * t->size_f,
    init_x = (offset_x - total_tablero_x) / 2,
    init_y = (offset_y - total_tablero_y) / 2;

    for(int fil = 0; fil < t->filas; fil++){
        for(int col = 0; col < t->columnas; col++){
            int pixel_x_inicial = init_x + (col * t->size_f);
            int pixel_y_inicial = init_y + (fil * t->size_f);
            if (t->tablero[fil][col] == 1) {
                dibujar_cuadrado(t, pixel_x_inicial, pixel_y_inicial, 10);
            }else{
                dibujar_cuadrado(t, pixel_x_inicial, pixel_y_inicial, 9);
            }
        }
    }

    gbt_volcar_backbuffer();
}

void dibujar_cuadrado(TABLERO* t, int pixel_x_inicial, int pixel_y_inicial, int color){
     for(int i = 0; i < t->size_f; i++) {
        for(int j = 0; j < t->size_f; j++) {
            gbt_dibujar_pixel(pixel_x_inicial + i, pixel_y_inicial + j, color);
        }
    }
}
