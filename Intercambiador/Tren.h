//
//  Tren.h
//  Intercambiador
//
//  Created by Enrique on 20/11/15.
//  Copyright © 2015 Enrique. All rights reserved.
//

#ifndef Tren_h
#define Tren_h
#include "Vagon.h"
#include <string>
    
class Tren {
    
    private:
        pnodo cabeza, final, actual;

    public:
        Tren(){cabeza = actual = NULL;}
        ~Tren();
        void insertarNodo(string, string, string, int, int);
        void borrarNodo(int);
        bool listaVacia();
        void mostrarLista();
        pnodo getFinal();
        pnodo esPrimero();
        void insertarNodo(Vagon *);
        void actualizar();
        void setFinal(Vagon *);
        void mostrarListaAuxiliar();
};

#endif /* Tren_h */
