//
//  Vagon.h
//  Intercambiador
//
//  Created by Enrique on 20/11/15.
//  Copyright © 2015 Enrique. All rights reserved.
//

#ifndef Vagon_h
#define Vagon_h
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class Vagon {
    
private:
    
    string origen;
    string destino;
    string carga;
    int num_vagon;
    int num_tren_nuevo;
    int num_tren;
    Vagon *siguiente;
    friend class Tren;
    
public:
    Vagon(string origen1, string destino1, string carga1,  int num_tren1,int num_vagon1,Vagon *sig = NULL) {
        origen = origen1;
        destino = destino1;
        carga = carga1;
        num_tren_nuevo = num_tren1;
        num_tren = num_tren1;
        num_vagon = num_vagon1;
        siguiente = sig;
    }
    Vagon *clonar () {
        Vagon *vagon = new Vagon(origen, destino, carga, num_tren, num_vagon);
        return vagon;
    }
    
    Vagon *getSiguiente () {
        return siguiente;
    }
    
    string getDestino() {
        return destino;
    }
    
    void setSiguiente (Vagon *puntero) {
        siguiente = puntero;
    }
    
    int getNum_Vagon() {
        return num_vagon;
    }
    
    string getCarga() {
        return carga;
    }
    
    string getOrigen() {
        return origen;
    }
    
};
typedef Vagon *pnodo;





#endif /* Vagon_h */
