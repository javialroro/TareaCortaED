#include <iostream>
#include <string>
#include "prototipos.h"
#include "estructuras.h"
using namespace std;

//
// Created by javia on 09/03/2023.
//
int main(int argc, char** argv) {
    menuPrincipal();
    /*
    Combo *prueba= new Combo();
    prueba->nombre = "Combo Prueba";
    prueba->cantidadPorciones = 10;
    prueba->listaComponentes[0] = new Componente("hola", 10, "vaso");
    prueba->listaComponentes[1] = new Componente("hola2", 10, "vaso");
    prueba->imprimir();
    return 0;
     */
    BaseDeDatos *base = new BaseDeDatos();

    //base->agregarCombo();
    //base->imprimir();


}
