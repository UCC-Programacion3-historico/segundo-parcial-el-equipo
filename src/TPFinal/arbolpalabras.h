#ifndef ARBOLPALABRAS_H
#define ARBOLPALABRAS_H

#include "arbolmail.h"

class nodoPalabra{
private:
    unsigned long id;
    char* palabra;
    int largo;
    nodoPalabra* izq;
    nodoPalabra* der;
public:
    nodoPalabra(char* pa,int lar,unsigned long i){
        izq = NULL;
        der = NULL;
        palabra = pa;
        largo = lar;
        id = i;
    }
    nodoPalabra(){
        izq = NULL;
        der = NULL;
        palabra = NULL;
    }
    unsigned long getId(){
        return id;
    }
    void setId(unsigned long d){
        id = d;
    }
    char* getPalabra(){
        return palabra;
    }
    void setPalabra(char* p){
        palabra = p;
    }
    int getLargo(){
        return largo;
    }
    void setLargo(int a){
        largo = a;
    }
    nodoPalabra* getDer(){
        return der;
    }
    void setDer(nodoPalabra* d){
        der = d;
    }
    nodoPalabra* getIzq(){
        return izq;
    }
    void setIzq(nodoPalabra* i){
        izq = i;
    }

    void add(char* pa,int lar, unsigned long d);
    void get(vector<unsigned long>* A,char* texto, int len);
    void remove(char* pa,int lar, unsigned long d);
};

class arbolPalabras
{
private:
    nodoPalabra* raiz;
public:
    arbolPalabras();
    void add(char* pa,int lar, unsigned long d);
    void get(vector<unsigned long>* A,char* texto, int len);
    void remove(char* pa,int lar, unsigned long d);
};

int comparaPalabra(char* A,char* B,int largo);

#endif // ARBOLPALABRAS_H
