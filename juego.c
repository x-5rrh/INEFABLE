#include "JUEGO.h"
#define TAMANIO_BLOQUE 20

void contructor_juego(JUEGO* juego, int max_ancho, int max_alto, int filas, int columnas){
    juego->tamanio_bloque = TAMANIO_BLOQUE; //CONSTANTE
    juego->offset_x = max_ancho;
    juego->offset_y = max_alto;
    juego->puntos = 0;
    juego->estado_juego = 0; //0 = MENU
    juego->ancla_x = (juego->offset_x - (columnas * juego->tamanio_bloque)) / 2;
    juego->ancla_y = (juego->offset_y - (filas * juego->tamanio_bloque)) / 2;
    iniciar_tablero(&juego->tablero, filas, columnas, juego->tamanio_bloque);
}
