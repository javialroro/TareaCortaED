//
// Created by javia on 09/03/2023.
//


#include <iostream>
#include <string>
#include <cctype>


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
                cout << "------------------------"<< endl;
                cout << "Componente numero: " << i+1 << endl;
                cout << "Nombre: " << listaComponentes[i]->nombre << endl;
                cout << "Cantidad: " << listaComponentes[i]->cantidad << endl;
                cout << "Unidad: " << listaComponentes[i]->unidad << endl;
                cout << "------------------------"<< endl;
            }
        }
    }
};


struct BaseDeDatos{
    Combo *listaCombos[100];
    int cantidadCombos = 0;

    void imprimir(){
        for (int i = 0; i < cantidadCombos; i++){
            if (listaCombos[i]->nombre != ""){
                listaCombos[i]->imprimir();
            }
            else{
                cout << "No hay combos" << endl;
            }
        }
    }
    void agregarCombo(){
        if (cantidadCombos == 100){
            cout << "No se pueden agregar mas combos" << endl;
            return;
        }
        Combo *combo = new Combo();
        cout << "Ingrese el nombre del combo: ";
        cin >> combo->nombre;
        cout << "Ingrese la cantidad de porciones: ";
        cin >> combo->cantidadPorciones;
        for (int i = 0; i < 30; i++){
            Componente *componente = new Componente();
            string nombre;
            int cantidad;
            string unidad;
            cout << "Ingrese el nombre del componente: ";
            cin >> componente->nombre;
            cout << "Ingrese la cantidad del componente: ";
            cin >> cantidad;
            cout <<cantidad<< endl;
            componente->cantidad = cantidad;
            cout << "Ingrese la unidad del componente: ";
            cin >> componente->unidad;
            combo->listaComponentes[i] = componente;
            combo->cantidadComponentes++;
            cout << "Desea agregar otro componente? (S=1/N=0): ";
            string respuesta;
            cin >> respuesta;
            cout <<respuesta << endl;
            if (respuesta == "0"){
                cout << "Se ha terminado de agregar los componentes" << endl;
                break;
            }

        }
        listaCombos[cantidadCombos] = combo;
        cantidadCombos++;
        cout << "Combo agregado exitosamente" << endl;

    }
    void buscarCombo(){
        string nombre;
        bool encontrado = false;
        cout << "Ingrese el nombre del combo que desea buscar: ";
        cin >> nombre;
        for (int i = 0; i < cantidadCombos; i++){
            if (listaCombos[i]->nombre == nombre){
                listaCombos[i]->imprimir();
                encontrado = true;
                break;
            }
        }
        if (!encontrado){
            cout << "No se encontro el combo" << endl;
        }
    }
    void borrarCombo(){
        string nombre;
        cout << "Ingrese el nombre del combo que desea borrar: ";
        cin >> nombre;
        bool encontrado = false;
        for (int i = 0; i < cantidadCombos; i++){
            if (listaCombos[i]->nombre == nombre){
                listaCombos[i]->nombre = "";
                listaCombos[i]->cantidadPorciones = 0;
                encontrado = true;
                for (int j = 0; j < listaCombos[i]->cantidadComponentes; j++){
                    listaCombos[i]->listaComponentes[j]->nombre = "";
                    listaCombos[i]->listaComponentes[j]->cantidad = 0;
                    listaCombos[i]->listaComponentes[j]->unidad = "";
                }
                cout << "Combo borrado exitosamente" << endl;
                break;
            }

        }
        if (!encontrado){
            cout << "No se encontro el combo" << endl;
        }

    }

};



