#include <stdio.h>
#include <stdlib.h>
#include "GBT/gbt.h"
#include "JUEGO.h"
#include "MATRIZ.h"
#include "PIEZA.h"

static int generador_aleatorio();
static int juego_pieza_colision(JUEGO* j);
static int juego_pieza_colision_lateral(JUEGO *juego, int direccion);

void constructor_juego(JUEGO* j, GRAFICADOR* graficador_ajeno ,int x, int y, double velocidad){
    j->graficador = graficador_ajeno;
    crear_pieza(&j->pieza_actual, generador_aleatorio(), 0, 3);
    crear_pieza(&j->pieza_siguiente, generador_aleatorio(), 0, 3);
    crear_matriz_vacia(&j->matriz, x, y);
    j->reloj_gravedad = gbt_temporizador_crear(velocidad);
}

void juego_dibujar(JUEGO* j){
    int tamanio_bloque = (j->graficador->screen_y - 20) / j->matriz.filas,
    pos_tablero_x, pos_tablero_y, pos_x_sig_pieza;

    //grafico de tablero
    pos_tablero_x = (j->graficador->mid_screen_x - (j->matriz.columnas * tamanio_bloque / 2));
    pos_tablero_y = 10;
    graficar_matriz(j->graficador,
                    &j->matriz, pos_tablero_x,
                    pos_tablero_y,
                    tamanio_bloque);
    //grafico de pieza
    graficar_matriz(j->graficador,
                    &j->pieza_actual.pieza,
                    pos_tablero_x + (j->pieza_actual.cord_columna * tamanio_bloque),
                    pos_tablero_y + (j->pieza_actual.cord_fila * tamanio_bloque),
                    tamanio_bloque);
    //grafico pieza siguiente
    pos_x_sig_pieza = (j->graficador->screen_x - (j->pieza_siguiente.pieza.columnas * tamanio_bloque)) - 20;
    graficar_matriz(j->graficador,
                    &j->pieza_siguiente.pieza,
                    pos_x_sig_pieza,
                    20,
                    tamanio_bloque);
}

void juego_actualizar(JUEGO* j){
    if(gbt_temporizador_consumir(j->reloj_gravedad)){
        if(juego_pieza_colision(j)){
            juego_insertar_pieza(j);
            juego_actualizar_pieza(j);
        }else{
            pieza_bajar(&j->pieza_actual, 1);
        }
    }
}

void juego_entrada(JUEGO* j){
    if(gbt_tecla_presionada(GBTK_DERECHA)){
        if(juego_pieza_colision_lateral(j, 1) == 0) j->pieza_actual.cord_columna += 1;
    }
    if(gbt_tecla_presionada(GBTK_IZQUIERDA)){
        if(juego_pieza_colision_lateral(j, -1) == 0) j->pieza_actual.cord_columna -= 1;
    }
    if(gbt_tecla_presionada(GBTK_ABAJO)){
        if(juego_pieza_colision(j) == 0) pieza_bajar(&j->pieza_actual, 1);
    }
}

void juego_insertar_pieza(JUEGO* j){
    int i, k;

    for(i = 0; i < j->pieza_actual.pieza.filas; i++){
        for(k = 0; k < j->pieza_actual.pieza.columnas; k++){
            if(j->pieza_actual.pieza.matriz[i][k] != -1)
            j->matriz.matriz[j->pieza_actual.cord_fila + i][j->pieza_actual.cord_columna + k] = j->pieza_actual.pieza.matriz[i][k];
        }
    }
}

void juego_actualizar_pieza(JUEGO* j){
    //pieza actual
    eliminar_matriz(&j->pieza_actual.pieza);
    crear_pieza(&j->pieza_actual, j->pieza_siguiente.id, 0, 3);
    //pieza siguiente
    eliminar_matriz(&j->pieza_siguiente.pieza);
    crear_pieza(&j->pieza_siguiente, generador_aleatorio(), 0, 0);
}

void juego_eliminar(JUEGO* j){



    gbt_temporizador_destruir(j->reloj_gravedad);
    eliminar_matriz(&j->matriz);
}
static int juego_pieza_colision_lateral(JUEGO *juego, int direccion){
    int i, j, columna_siguiente, fila_actual;
    //direccion, es a donde se direge la pieza, derecha = +1 | izquierda = -1.
    for (i = 0; i < juego->pieza_actual.pieza.filas; i++) {
        for (j = 0; j < juego->pieza_actual.pieza.columnas; j++) {
            if (juego->pieza_actual.pieza.matriz[i][j] != -1) {
                fila_actual = juego->pieza_actual.cord_fila + i;
                columna_siguiente = juego->pieza_actual.cord_columna + j + direccion;

                if (columna_siguiente < 0) return 1;
                if (columna_siguiente >= juego->matriz.columnas) return 1;
                //verificamos si no hay una piaza que sea un limite vertical, osea piezas que ya estan en el tablero(estaticas).
                if (fila_actual >= 0 && fila_actual < juego->matriz.filas) {
                    if (juego->matriz.matriz[fila_actual][columna_siguiente] != -1) return 1;
                }
            }
        }
    }
    return 0;
}

static int juego_pieza_colision(JUEGO* juego){
    int i, j;

    for(i = 0; i < juego->pieza_actual.pieza.filas; i++){
        for(j = 0; j < juego->pieza_actual.pieza.columnas; j++){
            if(juego->pieza_actual.pieza.matriz[i][j] != -1){
                //compruebo colision con final de tablero
                if((juego->pieza_actual.cord_fila + i) + 1 >= juego->matriz.filas) return 1;
                //compruebo colision con otra pieza
                if(juego->matriz.matriz[juego->pieza_actual.cord_fila + i + 1][juego->pieza_actual.cord_columna + j] != -1) return 1;
            }
        }
    }

    return 0;
}

static int generador_aleatorio(){
    return rand() % 7;
}
