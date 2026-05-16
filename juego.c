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

}
