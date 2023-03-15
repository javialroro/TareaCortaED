//
// Created by QUIROS CALVO on 11/3/2023.
//

#include "prototipos.h"
#include "estructuras.h"
#include <iostream>
#include <string>

BaseDeDatos *base = new BaseDeDatos();
using namespace std;

// Procedimiento que genera el menú principal en consola
void menuPrincipal(){
    for (;;){
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
        cout << endl; cout << endl;

        cout << "------------------> Seleccion <-------------------" << endl;
        cout << endl;
        cout << "A continuacion ingrese un numero segun su seleccion:" << endl;
        string strSeleccion;
        getline(cin, strSeleccion);

        int valSeleccion = stoi(strSeleccion); // Convierte la entrada de consola (str) a entero.

        //A continuacion condicionales de prueba (igual despues se modifican para que cumplan su funcion en el programa)

        if  (valSeleccion == 1) {

            base->agregarCombo();
            cout << "Su seleccion fue: Agregar Combo" << endl;
            cout << endl;
            continue;
        }else if  (valSeleccion == 2) {
            cout << "Su seleccion fue: Buscar Combo" << endl;
            cout << endl;
            continue;
        }else if  (valSeleccion == 3) {
            cout << "Su seleccion fue: Borrar Combo" << endl;
            cout << endl;
            continue;
        }else if  (valSeleccion == 4) {
            cout << "Su seleccion fue: Imprimir todos los Combos" << endl;
            base->imprimir();
            cout << endl;
            continue;
        }else if  (valSeleccion == 5) {
            cout << "Su seleccion fue: Modificar nombre de un Combo" << endl;
            cout << endl;
            continue;
        }else if  (valSeleccion == 6) {
            cout << "Su seleccion fue: Modificar cantidad de un Componente de un combo" << endl;
            cout << endl;
            continue;
        }else if  (valSeleccion == 7) {
            cout << "Su seleccion fue: Agregar Componente a un Combo" << endl;
            cout << endl;
            continue;
        }else if  (valSeleccion == 8) {
            cout << "Su seleccion fue: Calcular para porciones" << endl;
            cout << endl;
            continue;
        }else if  (valSeleccion == 9) {
            break; // Este break solo detiene el switch
        }else{}
                cout << "La opcion elegida no es valida, intente de nuevo";
                cout << endl;
    }
}