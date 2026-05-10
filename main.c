/*
Apellido: Russo Rodriguez, Nahuel Sebastian
DNI: 43820382
Usuario: x-5rrh
Entrega: Sí

Apellido: Blanco, Priscila
DNI: 44355393
Usuario: PriWhite
Entrega: Sí

Apellido: Benito, Pablo
DNI: 43569575
Usuario: PabloBeni
Entrega: Sí
*/

#include <stdio.h>
#include <stdlib.h>
#include "GBT/gbt.h"
#include "JUEGO.h"
#include "TABLERO.h"
#define MAX_ANCHO 640
#define MAX_ALTO 480

int main()
{
    JUEGO juego;
    // defino caracteristicas del juego
    juego.tamanio_bloque = 20;
    juego.tamanio_ancho_ventana = MAX_ANCHO;
    juego.tamanio_alto_ventana = MAX_ALTO;
    iniciar_tablero(&juego.tablero, 20, 10, juego.tamanio_bloque);

    gbt_iniciar();

    int ventana = gbt_crear_ventana("TETRIS INEFABLE", MAX_ANCHO, MAX_ALTO, 1);

    if(ventana != 0){
        printf("ALGO SALIO MAL!!!!");
    }else{
        dibujar_tablero(&juego.tablero, juego.tamanio_ancho_ventana, juego.tamanio_alto_ventana);
        gbt_esperar(3000);
    }

    gbt_destruir_ventana();
    gbt_cerrar();

    return 0;
}

