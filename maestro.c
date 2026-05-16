#include "MAESTRO.h"
#include "MENU.h"

void contructor_maestro(MAESTRO* m, GRAFICADOR* graficador_ajeno, int filas, int columnas){
    m->puntos = 0;
    m->estado_juego = 1; //0 = MENU 1 = JUEGO 2 = GAMEOVER
    m->graficador = graficador_ajeno;
    constructor_juego(&m->juego, graficador_ajeno, filas, columnas, m->dificultad);
    constructor_menu(&m->menu, graficador_ajeno, m->dificultad);
}

void alternar_estados(MAESTRO* m){
    switch(m->estado_juego){
        case 0:
            dibujar_menu(&m->menu);
            break;
        case 1:
            dibujar_juego(&m->juego);
            break;
        case 2:

            break;
    }
}

/*
    m->ancla_x = (juego->offset_x - (columnas * juego->tamanio_bloque)) / 2;
    m->ancla_y = (juego->offset_y - (filas * juego->tamanio_bloque)) / 2;
*/
