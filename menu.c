#include "GBT/gbt.h"
#include "GRAFICADOR.h"
#include "MENU.h"
#include "MATRIZ.h"

MATRIZ matriz;
    int letra_c[] = {
        1,  1,  1,  1,
        1, 2, 2, 2,
        1 ,2, 2, 2,
        1,  1,  1,  1,
};

void constructor_menu(MENU* menu, GRAFICADOR* graficador_ajeno, int* dificulta_m){
    menu->difucultad = dificulta_m;
    menu->graficador = graficador_ajeno;
    crear_matriz_molde(&matriz, letra_c, 4, 4);
}

void dibujar_menu(MENU* menu){
    gbt_borrar_backbuffer(12);

    graficar_matriz(menu->graficador, &matriz, 20, 20, 30);

    //eliminar_matriz(&matriz);
}
