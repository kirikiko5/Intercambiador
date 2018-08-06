//
//  main.cpp
//  Intercambiador
//
//  Created by Enrique on 20/11/15.
//  Copyright © 2015 Enrique. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <string>
#include "Tren.h"
#include "Vagon.h"

#define MAX 5
#define Valladolid 0
#define Zaragoza 1
#define Burgos 2
#define Orense 3
#define Bilbao 4

using namespace std;

void buscarVagonNum(Tren []);
void buscarVagonCarga(Tren []);
void buscarVagonDestino(Tren []);
void buscarVagonOrigen(Tren []);
int existeEn (string *, string, int);

int main(int argc, const char * argv[]) {
    
    srand(static_cast<unsigned int>(time(NULL)));
    
    Tren trenes[5];

    //Creando los trenes, locomotoras y los vagones
    trenes[0].insertarNodo("Sevilla","Valladolid"," ",123,NULL); //Se crea la locomotora
    for(int i = 0; i < (2+(rand()%(int)(4-2 +1))); i++) { //Se ejecuta un numero aleatorio de veces entre
        trenes[0].insertarNodo(" "," "," ",NULL,NULL); //Se crean vagones
    }
    
    trenes[1].insertarNodo("Zamora","Zaragoza"," ",456,NULL); //Se crea la locomotora de la linea 2
    for(int i = 0; i < (2+(rand()%(int)(4-2 +1))); i++) {
        trenes[1].insertarNodo(" "," "," ",NULL,NULL); //Se crean los vagones
    }
    
    trenes[2].insertarNodo("Badajoz","Burgos"," ",224,NULL); //Se crea la locomotora de la linea 3
    for(int i = 0; i < (2+(rand()%(int)(4-2 +1))); i++) {
        trenes[2].insertarNodo(" "," "," ",NULL,NULL); //Se crean los vagones
    }
    
    trenes[3].insertarNodo("Cuenca","Orense"," ",801,NULL); //Se crea la locomotora de la linea 4
    for(int i = 0; i < (2+(rand()%(int)(4-2 +1))); i++) {
        trenes[3].insertarNodo(" "," "," ",NULL,NULL); //Se crean los vagones
    }
    
    trenes[4].insertarNodo("Albacete","Bilbao"," ",652,NULL); //Se crea la locomotora de la linea 5
    for(int i = 0; i < (2+(rand()%(int)(4-2 +1))); i++) {
        trenes[4].insertarNodo(" "," "," ",NULL,NULL); //Se crean los vagones
    }
    
    for (int i = 0; i < MAX; i++) {
        trenes[i].mostrarLista();
        cout<< "--------------------------------------\n";
    }
    
    cout << "\n\nTODOS LOS TRENES HAN LLEGADO A MADRID\n\n";
    
    
    pnodo aux = trenes[0].esPrimero()->getSiguiente(); //Guardmos en la variable 'aux' el primer vagon de la primera lista
    trenes[0].esPrimero()->setSiguiente(NULL); //Rompemos la relacion que hay entre la locomotora y el primer vagon
    trenes[0].setFinal(trenes[0].esPrimero()); //
    pnodo temhead = aux;
    for (int num = 1; num <MAX; num++) {
        while (aux->getSiguiente()) {
            aux = aux->getSiguiente();
        }
        pnodo aux2 = trenes[num].esPrimero()->getSiguiente();
        aux->setSiguiente(aux2);
        trenes[num].esPrimero()->setSiguiente(NULL);
        trenes[num].setFinal(trenes[num].esPrimero());
    }
    
    while (temhead != NULL) {
        if (!temhead->getDestino().compare("Valladolid")) {
            trenes[Valladolid].insertarNodo(temhead);
        } else if (!temhead->getDestino().compare("Zaragoza")) {
            trenes[Zaragoza].insertarNodo(temhead);
        } else if (!temhead->getDestino().compare("Burgos")) {
            trenes[Burgos].insertarNodo(temhead);
        } else if (!temhead->getDestino().compare("Orense")) {
            trenes[Orense].insertarNodo(temhead);
        } else if (!temhead->getDestino().compare("Bilbao")) {
            trenes[Bilbao].insertarNodo(temhead);
        }
        pnodo aux2 = temhead->getSiguiente();
        temhead->setSiguiente(NULL);
        temhead = aux2;
    }
    
    for (int j = 0; j < MAX; j++) {
        trenes[j].actualizar();
    }
    
    for (int i = 0; i < MAX; i++) {
        trenes[i].mostrarLista();
        cout<< "--------------------------------------\n";
    }
    
    int eleccion;
    bool menuOn = true;
    while (menuOn != false) {
        
        cout << "\n\n********************************************************************************\n";
        cout << "**  1.Pulse '1' para buscar un vagon por su numero de identificacion            **\n";
        cout << "**  2.Pulse '2' para buscar todos los vagones que lleven una carga especifica   **\n";
        cout << "**  3.Pulse '3' para buscar un conjunto de vagones según su origen              **\n";
        cout << "**  4.Pulse '4' para buscar un conjunto de vagones según su destino             **\n";
        cout << "**  5.Pulse '5' para salir                                                      **\n";
        cout << "**********************************************************************************\n\n";
        
        cin >> eleccion;
        switch (eleccion) {
            case 1:
                buscarVagonNum(trenes);
                break;
            
            case 2:
                buscarVagonCarga(trenes);
                break;
                
            case 3:
                buscarVagonOrigen(trenes);
                break;
                
            case 4:
                buscarVagonDestino(trenes);
                break;
            
            case 5:
                cout << "Fin del programa\n";
                menuOn = false;
                break;
            default:
                cout << "Por favor, introduzca un número válido";
                cin >> eleccion;
                break;
        }
    }
}

void buscarVagonNum(Tren trenes[]) {
    
    Tren lista;
    pnodo actual, clon;
    int numero; //Encontrado sirve para ver si se ha encontrado o no.
    cout << "Escriba el numero de Vagon que desea buscar: ";
    cin >> numero;
    for (int i = 0; i < MAX; i++) {
        actual = trenes[i].esPrimero()->getSiguiente();
        while (actual!=NULL) {
            if (actual->getNum_Vagon() == numero) {
                clon = actual->clonar();
                lista.insertarNodo(clon);
            }
            actual = actual->getSiguiente();
        }
    }
    if (lista.listaVacia()) {
        cout << "\nNo se ha encontrado ningun vagon con ese numero.\n";
    } else {
        lista.mostrarListaAuxiliar();
    }
    lista.~Tren();
}

void buscarVagonCarga(Tren trenes[]) {
    
    Tren lista;
    pnodo actual, clon;
    string array [8] = {"Cereales","Alimentos","Madera","Acero","Cobre","Carbon","Automoviles","Hormigon"};
    string carga; //Encontrado sirve para ver si se ha encontrado o no.
    cout << "Escriba la carga que desea: (Cereales, Acero, Alimentos, Hormigon, Carbon, Madera, Automoviles, Cobre)\n";
    cin >> carga;
    if (existeEn(array, carga, 8)) {
        for (int i = 0; i < MAX; i++) {
            actual = trenes[i].esPrimero()->getSiguiente();
            while (actual!=NULL) {
                if (actual->getCarga() == carga) {
                    clon = actual->clonar();
                    lista.insertarNodo(clon);
                }
                actual = actual->getSiguiente();
            }
        }
        if (lista.listaVacia()) {
            cout << "No se ha encontrado ningun elemento";
        } else {
            lista.mostrarListaAuxiliar();
        }
    } else {
        cout << "Palabra no reconocida:";
    }
    lista.~Tren();
}

int existeEn (string *array, string cadena, int tamanio) {
    for (int i =0; i < tamanio; i++) {
        if (array[i].compare(cadena) == 0) {
            return true;
        }
    }
    return false;
}

void buscarVagonDestino(Tren trenes[]) {
    
    Tren lista;
    pnodo actual, clon;
    string destino; //Encontrado sirve para ver si se ha encontrado o no.
    cout << "Escriba el destino deseado: ";
    cin >> destino;
    for (int i = 0; i < MAX; i++) {
        actual = trenes[i].esPrimero()->getSiguiente();
        while (actual!=NULL) {
            if (actual->getDestino() == destino) {
                clon = actual->clonar();
                lista.insertarNodo(clon);
            }
            actual = actual->getSiguiente();
        }
    }
    if (lista.listaVacia()) {
        cout << "\nNo se a encontrado ningun vagon con ese destino.\n";
    } else {
        lista.mostrarListaAuxiliar();
    }
    lista.~Tren();
}

void buscarVagonOrigen(Tren trenes[]) {
    
    Tren lista;
    pnodo actual, clon;
    string origen; //Encontrado sirve para ver si se ha encontrado o no.
    cout << "Escriba el origen deseado: ";
    cin >> origen;
    for (int i = 0; i < MAX; i++) {
        actual = trenes[i].esPrimero()->getSiguiente();
        while (actual!=NULL) {
            if (actual->getOrigen() == origen) {
                clon = actual->clonar();
                lista.insertarNodo(clon);
            }
            actual = actual->getSiguiente();
        }
    }
    if (lista.listaVacia()) {
        cout << "\nNo se a encontrado ningun vagon con ese origen.\n";
    } else {
        lista.mostrarListaAuxiliar();
    }
    lista.~Tren();
}

