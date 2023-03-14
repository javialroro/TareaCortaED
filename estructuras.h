//
// Created by javia on 12/03/2023.
//
#include <iostream>
#include <string>

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
    Componente * listaComponentes[30];

    void imprimir(){
        cout << "Nombre: " << nombre << endl;
        cout << "Cantidad de porciones: " << cantidadPorciones << endl;
        cout << "Componentes: " << endl;
        for (int i = 0; i < 30; i++){
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
;

struct BaseDeDatos{
    Combo *listaCombos[100];
    void imprimir(){
        for (int i = 0; i < 100; i++){
            if (listaCombos[i]->nombre != ""){
                listaCombos[i]->imprimir();
            }
        }
    }
    void agregarCombo(){
        Combo *combo = new Combo();
        cout << "Ingrese el nombre del combo: ";
        cin >> combo->nombre;
        cout << "Ingrese la cantidad de porciones: ";
        cin >> combo->cantidadPorciones;
        for (int i = 0; i < 30; i++){
            Componente *componente = new Componente();
            string nombre;
            cout << "Ingrese el nombre del componente: ";
            cin >> componente->nombre;
            cout << "Ingrese la cantidad del componente: ";
            cin >> componente->cantidad;
            cout << "Ingrese la unidad del componente: ";
            cin >> componente->unidad;
            combo->listaComponentes[i] = componente;
            cout << "Desea agregar otro componente? (s/n): ";
            string respuesta;
            cin >> respuesta;
            if (respuesta == "n"){
                break;
            }
        }
        for (int i = 0; i < 100; i++){
            if (listaCombos[i]->nombre == ""){
                listaCombos[i] = combo;
                break;
            }
        }
    }
};
