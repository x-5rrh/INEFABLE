#include "MAESTRO.h"
#include "MENU.h"
#define TAMANIO_BLOQUE 20

void contructor_juego(MAESTRO* m, int max_ancho, int max_alto, int filas, int columnas){
    m->tamanio_bloque = TAMANIO_BLOQUE; //CONSTANTE
    m->offset_x = max_ancho;
    m->offset_y = max_alto;
    m->puntos = 0;
    m->estado_juego = 0; //0 = MENU
    constructor_tablero(&m->tablero, filas, columnas, juego->tamanio_bloque);
}

void alternar_estados(MAESTRO* j){
    switch(j->estado_juego){
        case 0:
            dibujar_menu(&j->menu, j->offset_x, j->offset_y);
            break;
        case 1:
            dibujar_tablero(&j->tablero);
            break;
        case 2:

            break;
    }
}

/*
    m->ancla_x = (juego->offset_x - (columnas * juego->tamanio_bloque)) / 2;
    m->ancla_y = (juego->offset_y - (filas * juego->tamanio_bloque)) / 2;
*/
