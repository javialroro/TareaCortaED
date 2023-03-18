//
// Created by javia on 09/03/2023.
//

#ifndef TAREACORTAED_PROTOTIPOS_H
#define TAREACORTAED_PROTOTIPOS_H
#endif //TAREACORTAED_PROTOTIPOS_H

#include <iostream>
#include <string>
#include "procedimientos.cpp"


// Procedimiento que despliega el menu en consola
void menuPrincipal();

// Procedimiento que despliega todos los combos en base de datos
void imprimir();

// Procedimiento para evaluar si hay combos en la base de datos,
// retorna true si esta vacia y false en caso contrario.
bool listaComboVacia();

// Procedimiento que busca un combo en la base de datos por su nombre
// en caso de ser encontrado retorna su indice, en caso contrario retorna -1
int buscarComboIndex (string comboBuscado);

// Procedimiento que busca un componente por su nombre en un combo dado.\
// en caso de ser encontrado retorna su indice, en caso contrario retorna -1
int buscarComponenteIndex (Combo combo, string comp);

// Procedimiento para agregar combos a la base de datos,
// solicitando los datos necesarios al usuario
void agregarCombo();

// Procedimiento que busca un combo en la base de datos y lo despliega en consola.
void buscarCombo();

// Procedimiento que elimina un combo de la base de datos, identificandolo por su nombre.
void borrarCombo();

// Procedimiento que facilita cambiar el nombre a un combo.
void modificarNombre ();

// Procedimiento que busca un combo y uno de sus componentes para cambiar la cantidad de este ultimo.
void modificarCantComponentes ();

// Procedimiento que permite agregar componente a un combo.
void agregarComponente ();

// Procedimiento que imprime solo los componentes de un combo.
void imprimirComponentes (Combo *combo);

// Procedimiento que selecciona un combo con sus respectivas porciones y calcula cuantos combos
// se necesitan para satisfacer n cantidad de porciones.
void calcularParaPorciones();
