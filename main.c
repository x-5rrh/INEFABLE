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
#include "MAESTRO.h"
#include "GRAFICADOR.h"
#define MAX_X 854
#define MAX_Y 480
#define BLOQUE 30

int main()
{
    MAESTRO maestro;
    GRAFICADOR graficador;
    //GBT
    gbt_iniciar();
    if(gbt_crear_ventana("TETRIS INEFABLE", MAX_X, MAX_Y, 2) != 0){
        printf("ALGO SALIO MAL!!!!");
        return 0;
    }
    //

    constructor_graficador(&graficador, MAX_X, MAX_Y);
    contructor_maestro(&maestro, &graficador, 20, 10); //inicializamos todas las propiedades de TDA JUEGO
    while(maestro.estado_juego != -1){
        //*DIBUJO GENERAL
        alternar_estados(&maestro);
        gbt_volcar_backbuffer();
        gbt_esperar(16);
    }

    gbt_destruir_ventana();
    gbt_cerrar();

    return 0;
}

