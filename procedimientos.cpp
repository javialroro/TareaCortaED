//
// Created by javia on 09/03/2023.
//

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct Componente{
    string nombre;
    int cantidad;
    string unidad;
    Componente(string n, int c, string u){
        nombre = n;
        cantidad = c;
        unidad = u;
    }
    Componente(){
        nombre = "";
        cantidad = 0;
        unidad = "";
    }

    void imprimir(){
        cout << "Nombre: " << nombre << endl;
        cout << "Cantidad: " << cantidad << endl;
        cout << "Unidad: " << unidad << endl;
        cout << "-------------------------"<< endl;
    }
};

struct Combo{
    string nombre;
    int cantidadPorciones;
    int cantidadComponentes = 0;
    Componente * listaComponentes[30];

    void imprimir(){
        cout << "Nombre: " << nombre << endl;
        cout << "Cantidad de porciones: " << cantidadPorciones << endl;
        cout << "Componentes: " << endl;
        for (int i = 0; i < cantidadComponentes; i++){
            if (listaComponentes[i]->nombre != ""){
                cout << "-------------------------"<< endl;
                cout << "Componente numero: " << i+1 << endl;
                listaComponentes[i]->imprimir();
            }
        }
    }
};


struct BaseDeDatos {
    Combo *listaCombos[100];
    int cantidadCombos = 0;

    void imprimir() {
        cout << "----------------- IMPRIMIR -----------------";
        cout << endl;
        if (!listaComboVacia()) {
            for (int i = 0; i < cantidadCombos; i++) {
                if (listaCombos[i]->nombre != "") {
                    cout << "-------> COMBO " << i+1 << " <-------" << endl;
                    cout << "-------------------------"<< endl;
                    listaCombos[i]->imprimir();
                }
            }
        }else {
            cout << "No hay combos" << endl;
        }
    }

    // Procedimiento auxiliar para facilitar la validación en algunos casos.
    bool listaComboVacia(){
        for (int i = 0; i < cantidadCombos; i++) {
            if (listaCombos[i]->nombre != ""){
                 return false;
            }
        }
        return true;
    }

    // Procedimiento auxiliar para mejorar eficiencia.
    int buscarComboIndex(string comboBuscado) {
        for (int i = 0; i < cantidadCombos; i++) {
            if (listaCombos[i]->nombre == comboBuscado) {
                return i;
            }
        }
        return -1;
    }

    // Procedimiento auxiliar para mejorar eficiencia.
    int buscarComponenteIndex(Combo *combo, string comp) {
        for (int i = 0; i < combo->cantidadComponentes; i++) {
            if (combo->listaComponentes[i]->nombre == comp) {
                return i;
            }
        }
        return -1;
    }

    void agregarCombo() {
        cout << "----------------- AGREGAR COMBO -----------------";
        cout << endl;
        if (cantidadCombos == 100) {
            cout << "No se pueden agregar mas combos" << endl;
            return;
        }
        Combo *combo = new Combo();
        cout << "Ingrese el nombre del combo: ";
        cin >> combo->nombre;
        cout << "Ingrese la cantidad de porciones: ";
        cin >> combo->cantidadPorciones;
        for (int i = 0; i < 30; i++) {
            Componente *componente = new Componente();
            string nombre;
            int cantidad;
            string unidad;
            cout << "Ingrese el nombre del componente: ";
            cin >> componente->nombre;
            cout << "Ingrese la cantidad del componente: ";
            cin >> cantidad;
            //cout <<cantidad<< endl;
            componente->cantidad = cantidad;
            cout << "Ingrese la unidad del componente: ";
            cin >> componente->unidad;
            combo->listaComponentes[i] = componente;
            combo->cantidadComponentes++;
            cout << "Desea agregar otro componente? (S/N): ";
            string respuesta;
            cin >> respuesta;
            //cout <<respuesta << endl;
            if (respuesta == "N" || respuesta == "n") {
                cout << "Se ha terminado de agregar los componentes" << endl;
                break;
            }

        }
        listaCombos[cantidadCombos] = combo;
        cantidadCombos++;
        cout << "Combo agregado exitosamente" << endl;

    }

    void buscarCombo() {
        cout << "----------------- BUSCAR COMBO -----------------";
        cout << endl;
        string nombre;
        bool encontrado = false;
        cout << "Ingrese el nombre del combo que desea buscar: ";
        cin >> nombre;
        for (int i = 0; i < cantidadCombos; i++) {
            if (listaCombos[i]->nombre == nombre) {
                listaCombos[i]->imprimir();
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            cout << "No se encontro el combo" << endl;
        }
    }

    void borrarCombo() {
        cout << "----------------- BORRAR COMBO -----------------";
        cout << endl;
        string nombre;
        cout << "Ingrese el nombre del combo que desea borrar: ";
        cin >> nombre;
        bool encontrado = false;
        for (int i = 0; i < cantidadCombos; i++) {
            if (listaCombos[i]->nombre == nombre) {
                listaCombos[i]->nombre = "";
                listaCombos[i]->cantidadPorciones = 0;
                encontrado = true;
                for (int j = 0; j < listaCombos[i]->cantidadComponentes; j++) {
                    listaCombos[i]->listaComponentes[j]->nombre = "";
                    listaCombos[i]->listaComponentes[j]->cantidad = 0;
                    listaCombos[i]->listaComponentes[j]->unidad = "";
                }
                cout << "Combo borrado exitosamente" << endl;
                break;
            }

        }
        if (!encontrado) {
            cout << "No se encontro el combo" << endl;
        }

    }

    void modificarNombre() {
        while (true) {
            cout << "----------------- MODIFICAR NOMBRE -----------------";
            cout << endl;
            string nombre;
            cout << "Ingrese el nombre del combo que desea modificar: ";
            cin >> nombre;
            int index = buscarComboIndex(nombre);
            if (index != -1) {
                string nuevoNombre;
                cout << "Ingrese el nuevo nombre del combo: ";
                cin >> nuevoNombre;
                listaCombos[index]->nombre = nuevoNombre;
                cout << endl;
                cout << "Nombre modificado con exito!";
                cout << endl;
                break;
            } else {
                cout << "ERROR! Combo no encontrado, intente de nuevo";
                cout << endl;
            }
        }
    }

    void modificarCantComponentes() {
        while (true) {
            cout << "----------- MODIFICAR CANTIDAD COMPONENTE -----------";
            cout << endl;
            string combo;
            cout << "Ingrese el nombre del combo que desea modificar: ";
            cin >> combo;
            int indCombo = buscarComboIndex(combo);
            if (indCombo != -1) {
                cout << endl;
                string nombre;
                cout << "Ingrese el nombre del componente que desea modificar: ";
                cin >> nombre;
                int indComponente = buscarComponenteIndex(listaCombos[indCombo], nombre);
                if (indComponente != -1) {
                    int nuevaCantidad;
                    cout << "Ingrese la nueva cantidad de componente deseada: ";
                    cin >> nuevaCantidad;
                    listaCombos[indCombo]->listaComponentes[indComponente]->cantidad = nuevaCantidad;
                    break;
                } else {
                    cout << "ERROR! Componente no encontrado, intente de nuevo" << endl;
                    cout << endl;
                }
            } else {
                cout << "ERROR! Combo no encontrado, intente de nuevo" << endl;
                cout << endl;
            }
        }
    }

    void agregarComponente() {
        while (true) {
            cout << "----------- AGREGAR COMPONENTE -----------";
            cout << endl;
            string combo;
            cout << "Ingrese el nombre del combo que desea modificar: ";
            cin >> combo;
            int indCombo = buscarComboIndex(combo);
            if (indCombo != -1) {
                cout << endl;
                string nombreComp;
                cout << "Ingrese el nombre del componente que desea agregar: ";
                cin >> nombreComp;
                if (buscarComponenteIndex(listaCombos[indCombo], nombreComp) == -1) {
                    Componente *componente = new Componente();
                    int cantidad;
                    string unidad;
                    componente->nombre = nombreComp;
                    cout << "Ingrese la cantidad del componente: ";
                    cin >> cantidad;
                    componente->cantidad = cantidad;
                    cout << "Ingrese la unidad del componente: ";
                    cin >> componente->unidad;
                    listaCombos[indCombo]->listaComponentes[listaCombos[indCombo]->cantidadComponentes] = componente;
                    listaCombos[indCombo]->cantidadComponentes++;
                    cout << "Desea agregar otro componente? (S/N): ";
                    string respuesta;
                    cin >> respuesta;
                    if (respuesta == "N" || respuesta == "n") {
                        cout << "Se ha terminado de agregar los componentes" << endl;
                        break;
                    }
                } else {
                    cout << "ERROR! El componente ingresado ya existe, pruebe con otro" << endl;
                }
            } else {
                cout << "ERROR! Combo no encontrado, intente de nuevo" << endl;
                cout << endl;
            }
        }
    }

    void imprimirComponentes (Combo *combo){
        for (int i = 0; i < combo->cantidadComponentes; i++) {
            if (combo->listaComponentes[i]->nombre != "") {
                combo->listaComponentes[i]->imprimir();
            }
        }
    }

    void calcularParaPorciones(){
        while (true) {
            int porcionesRequeridas;
            cout << "------------ CALCULAR PARA PORCIONES ------------";
            cout << endl;
            string combo;
            cout << "Ingrese el nombre del combo que desea calcular: ";
            cin >> combo;
            int indCombo = buscarComboIndex(combo);
            if (indCombo != -1) {
                cout << "Ingrese la cantidad de porciones requeridas: ";
                cin >> porcionesRequeridas;
                if (listaCombos[indCombo]->cantidadPorciones >= porcionesRequeridas) {
                    listaCombos[indCombo]->imprimir();
                    break;
                } else{
                    cout << endl;
                    cout << "---> Combo Calculado <---" << endl;
                    cout << "Nombre: " << listaCombos[indCombo]->nombre << endl;
                    cout << "Cantidad de porciones: " << listaCombos[indCombo]->cantidadPorciones << endl;
                    cout << "Componentes: " << endl;
                    cout << "-------------------------"<< endl;
                    int i = 0;
                    int vecesCombo;
                    // Calculo de porciones.
                    vecesCombo = static_cast<int>(std::ceil(static_cast<double>(porcionesRequeridas) /
                                                            static_cast<double>(listaCombos[indCombo]->cantidadPorciones)));
                    while(i < vecesCombo){
                        cout << "----------> " << i+1 << " <----------" << endl;
                        cout << "-------------------------"<< endl;
                        imprimirComponentes(listaCombos[indCombo]);
                        i++;
                    }
                    cout << endl;
                    cout << "Se necesitan " << vecesCombo << " veces el combo seleccionado para cumplir con " << porcionesRequeridas << " porciones" << endl;
                    cout << endl;
                    break;
                }
            } else {
                cout << "ERROR! Combo no encontrado, intente de nuevo" << endl;
                cout << endl;
            }
        }
    }
};