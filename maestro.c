#include "MAESTRO.h"
#include "MENU.h"
#include "JUEGO.h"

void contructor_maestro(MAESTRO* m, GRAFICADOR* graficador_ajeno, int filas, int columnas){
    m->puntos = 0;
    m->estado_juego = 1; //0 = MENU | 1 = JUEGO | 2 = GAMEOVER
    m->graficador = graficador_ajeno;
    constructor_juego(&m->juego, graficador_ajeno, filas, columnas, 0.5);
    constructor_menu(&m->menu, graficador_ajeno, m->velocidad);
}

void maestro_dibujar(MAESTRO* m){
    switch(m->estado_juego){
        case 0:
            dibujar_menu(&m->menu);
            break;
        case 1:
            juego_dibujar(&m->juego);
            break;
        case 2:

            break;
    }
}

void maestro_actualizar(MAESTRO* m){
    switch(m->estado_juego){
        case 0:

            break;
        case 1:
            juego_entrada(&m->juego);
            juego_actualizar(&m->juego);
            break;
        case 2:

            break;
    }
}
