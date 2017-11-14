#ifndef TABLAPALABRAS_H
#define TABLAPALABRAS_H

#include "arbolpalabras.h"
#include <iostream>

#define SIZE_TABLA 10

class tablaPalabras {
private:
    arbolPalabras arbolTexto[SIZE_TABLA];
public:
    tablaPalabras();

    void add(nodoMail* A);
    void get(vector<unsigned long>* A,char* texto);
    void deletePalabras(email* A);
};

int largoPalabra(char* A);

#endif // TABLAPALABRAS_H
