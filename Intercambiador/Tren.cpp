//
//  Tren.cpp
//  Intercambiador
//
//  Created by Enrique on 20/11/15.
//  Copyright © 2015 Enrique. All rights reserved.
//

#include <stdio.h>
#include <string>
#include "Vagon.h"
#include "Tren.h"
#define MAX 5
#define Valladolid 0
#define Zaragoza 1
#define Burgos 2
#define Orense 3
#define Bilbao 4

using namespace std;

string static Ciu () {
    string ciudades[5] {"Valladolid", "Zaragoza","Burgos","Orense","Bilbao"};
    
    return ciudades[rand()%5];
}

string static Carga () {
    string carga[8] {"Alimentos","Acero","Cobre", "Cereales","Madera","Automoviles","Hormigon","Carbon"};
    
    return carga[rand()%8];
}

int static id () {
    return (1000 + (rand() % (int)(9999 - 1000 + 1)));
}

Tren::~Tren()
{
    pnodo aux;
    while(cabeza)
    {
        aux = cabeza;
        cabeza = cabeza->siguiente;
        delete aux;
    }
    actual = NULL;
}


bool Tren::listaVacia()
{
    return cabeza == NULL;
}

void Tren::insertarNodo(string origen, string destino, string carga,int num_tren, int num_vagon) {
    
    pnodo aux;
    
    if (listaVacia())
    {
        cabeza = new Vagon(origen, destino, carga, num_tren, num_vagon);
        final=cabeza;
    }
    else
    {
        aux= new Vagon(cabeza->origen, Ciu(), Carga(), cabeza->num_tren, id());
        final->siguiente=aux;
        final=aux;
    }
}

void Tren::mostrarLista() {
    Vagon *aux;
    aux = cabeza;
    while(aux) {
        if (aux == cabeza) {
            cout << "Linea: "<< aux->num_tren << " \n" << aux->origen << " -> " << aux->destino << "\n\n";
            aux = aux->siguiente;
        } else {
            cout << aux->num_tren << " " << aux->origen << " -> " << aux->destino << "\n";
            cout << "Vagon: " << aux->num_vagon << "  ||  Carga: " << aux->carga <<"\n";
            aux = aux->siguiente;
            
        }
    }
    cout << endl;
}

pnodo Tren::esPrimero()
{
    return cabeza;
}

pnodo Tren::getFinal() {
    return final;
}

void Tren::borrarNodo(int v) {
    
    pnodo anterior = nullptr;
    actual = cabeza;
    
    while (actual->num_vagon!=v && (actual->siguiente)!=NULL){
        anterior=actual;
        actual=actual->siguiente;
    }
    if(actual==cabeza) // Primer elemento
        cabeza = actual->siguiente;
    else{
        anterior->siguiente = actual->siguiente;
        if (actual==final){
            final=anterior;
        }
    }
    actual->siguiente=NULL;
    delete actual;
}

void Tren::insertarNodo(Vagon *vagon) {
    pnodo aux;
    
    if (listaVacia())
    {
        cabeza = vagon;
        final=cabeza;
    }
    else
    {
        aux = vagon;
        final->siguiente=aux;
        final=aux;
    }

}

void Tren::actualizar () {
    
    
    int numero = cabeza->num_tren;
    Vagon *aux = cabeza->siguiente;
    
    while (aux != NULL) {
        
        aux->num_tren_nuevo = aux->num_tren;
        aux->num_tren = numero;
        aux = aux->getSiguiente();
    }
}

void Tren::setFinal (Vagon *puntero) {
    final = puntero;
}

void Tren::mostrarListaAuxiliar() {
    Vagon *aux;
    aux = cabeza;
    while(aux) {
        if ((aux->num_tren_nuevo) == (aux->num_tren)) {
            cout << aux->num_tren << " " << aux->origen << " -> " << aux->destino << "\n";
            cout << "Vagon: " << aux->num_vagon << "  ||  Carga: " << aux->carga <<"\n";
            aux = aux->siguiente;
        } else {
            cout << "Linea antigua: "<< aux->num_tren_nuevo<< " ----> " << "Linea nueva: " << aux->num_tren;
            cout << "\n" << aux->origen << " -> " << aux->destino << "\n";
            cout << "Vagon: " << aux->num_vagon << "  ||  Carga: " << aux->carga <<"\n";
            aux = aux->siguiente;
        }
    }
    cout << endl;
}








