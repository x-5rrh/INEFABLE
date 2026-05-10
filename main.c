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

int main()
{
    JUEGO juego;
    contructor_juego(&juego, 854, 480, 20, 10); //inicializamos todas las propiedades de TDA JUEGO

    gbt_iniciar();
    int ventana = gbt_crear_ventana("TETRIS INEFABLE", juego.offset_x, juego.offset_y, 2);
    gbt_borrar_backbuffer(15);
    if(ventana != 0){
        printf("ALGO SALIO MAL!!!!");
    }else{
        dibujar_tablero(&juego.tablero, juego.ancla_x, juego.ancla_y);
        gbt_esperar(3000);
    }
    gbt_destruir_ventana();
    gbt_cerrar();

    return 0;
}

