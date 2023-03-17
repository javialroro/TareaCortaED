//
// Created by QUIROS CALVO on 11/3/2023.
//

#include "prototipos.h"
#include <iostream>
#include <string>
#include "procedimientos.cpp"

BaseDeDatos *base = new BaseDeDatos();
using namespace std;
string prueba(){
    cout << "hola" << endl;
    return "Hola";
}
int commit(){
    cout << "hola" << endl;
    return 0;
}
// Procedimiento que genera el menú principal en consola
void menuPrincipal(){
    while (true){
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
        int valSeleccion;
        cin>>valSeleccion;

        //A continuacion condicionales de prueba (igual despues se modifican para que cumplan su funcion en el programa)

        switch (valSeleccion) {
            case 1:
                cout << "Su seleccion fue: Agregar Combo" << endl;
                base->agregarCombo();
                cout << endl;
                break;
            case 2:
                cout << "Su seleccion fue: Buscar Combo" << endl;
                base -> buscarCombo();
                cout << endl;
                break;
            case 3:
                cout << "Su seleccion fue: Borrar Combo" << endl;
                base -> borrarCombo();
                cout << endl;
                break;
            case 4:
                cout << "Su seleccion fue: Imprimir todos los Combos" << endl;
                base->imprimir();
                cout << endl;
                break;
            case 5:
                cout << "Su seleccion fue: Modificar nombre de un Combo" << endl;
                cout << endl;
                break;
            case 6:
                cout << "Su seleccion fue: Modificar cantidad de un Componente de un combo" << endl;
                cout << endl;
                break;
            case 7:
                cout << "Su seleccion fue: Agregar Componente a un Combo" << endl;
                cout << endl;
                break;
            case 8:
                cout << "Su seleccion fue: Calcular para porciones" << endl;
                cout << endl;
                break;
            case 9:
                break; // Este break solo detiene el switch
            default:
                cout << "La opcion elegida no es valida, intente de nuevo";
                cout << endl;
                break;
        }
         // Este break detiene el while
    }
}