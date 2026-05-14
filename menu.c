#include <stdio.h>
#include "GBT/gbt.h"
#include "GRAFICADOR.h"
#include "MENU.h"
#include "MATRIZ.h"

MATRIZ matriz;
int letra_c[] = {
    1,  1,  1,  1,
    1, 2, 1, 2,
    1 ,2, 5, 2,
    1,  1,  1,  0,
};

void constructor_menu(MENU* menu, GRAFICADOR* graficador_ajeno, int* dificulta_m){
    menu->difucultad = dificulta_m;
    menu->graficador = graficador_ajeno;
    menu->is_render = 0;
}

void dibujar_menu(MENU* menu){
    if(menu->is_render == 0 ){
        crear_matriz_molde(&matriz, letra_c, 4, 4);
         menu->is_render = 1;
    }
    gbt_borrar_backbuffer(12);
    graficar_matriz(menu->graficador, &matriz, 20, 20, 50);
}
