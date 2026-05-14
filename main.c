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

int main()
{
    MAESTRO maestro;
    //GBT
    gbt_iniciar();
    if(gbt_crear_ventana("TETRIS INEFABLE", 854, 480, 2) != 0){
        printf("ALGO SALIO MAL!!!!");
        return 0;
    }
    //
    contructor_juego(&maestro, 854, 480, 20, 10); //inicializamos todas las propiedades de TDA JUEGO
    while(juego.estado_juego != -1){
        gbt_procesar_entrada();
        //*DIBUJO GENERAL
        alternar_estados(&maestro);
        gbt_volcar_backbuffer();
        gbt_esperar(16);
    }
    gbt_destruir_ventana();
    gbt_cerrar();

    return 0;
}

