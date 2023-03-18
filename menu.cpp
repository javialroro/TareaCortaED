//
// Created by QUIROS CALVO on 11/3/2023.
//

#include "prototipos.h"
#include <iostream>
#include <string>
#include <limits>

BaseDeDatos *base = new BaseDeDatos();

// Procedimiento que genera el menú principal en consola
void menuPrincipal() {
    while (true) {
        cout << "----------------> Menu Principal <----------------" << endl;
        cout << endl;
        cout << "1.......Agregar Combo" << endl;
        cout << "2.......Buscar Combo" << endl;
        cout << "3.......Borrar Combo" << endl;
        cout << "4.......Imprimir todos los Combos" << endl;
        cout << "5.......Modificar nombre de un Combo" << endl;
        cout << "6.......Modificar cantidad de un Componente de un combo" << endl;
        cout << "7.......Agregar Componente a un Combo" << endl;
        cout << "8.......Calcular para porciones" << endl;
        cout << "9.......Salir" << endl;
        cout << endl;

        cout << "------------------> Seleccion <-------------------" << endl;
        cout << "A continuacion ingrese un numero segun su seleccion: ";
        int valSeleccion;
        // While de validacion, este ciclo no termina hasta que el usuario ingrese un numero.
        while (!(cin >> valSeleccion)) {
            cin.clear(); // limpia el estado de error
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Se limpia el búfer de entrada
            cout << "ERROR! Estrada invalida, intente de nuevo: ";
        }
        cout << endl;
        cout << endl;
        //A continuacion condicionales de prueba (igual despues se modifican para que cumplan su funcion en el programa)

        if (valSeleccion == 1) {
            base->agregarCombo();
            cout << endl;
            continue;
        }else if (valSeleccion == 2) {
            base->buscarCombo();
            cout << endl;
            continue;
        }else if (valSeleccion == 3) {
            base->borrarCombo();
            cout << endl;
            continue;
        }else if (valSeleccion == 4) {
            base->imprimir();
            cout << endl;
            continue;
        }else if (valSeleccion == 5) {
            base->modificarNombre();
            cout << endl;
            continue;
        }else if (valSeleccion == 6) {
            base->modificarCantComponentes();
            cout << endl;
            continue;
        }else if (valSeleccion == 7) {
            base->agregarComponente();
            cout << endl;
            continue;
        }else if (valSeleccion == 8) {
            base->calcularParaPorciones();
            cout << endl;
            continue;
        }else if (valSeleccion == 9) {
            break; // Termina el programa.
        }else {
            cout << "ERROR! Estrada invalida, intente de nuevo: ";
            cout << endl;
            continue;
        }
    }
}