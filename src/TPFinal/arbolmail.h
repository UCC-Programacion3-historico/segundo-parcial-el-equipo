#ifndef ARBOLMAIL_H
#define ARBOLMAIL_H

#include "email.h"
#include "vector"

class nodoMail {
private:
    email* mail;
    nodoMail* izq;
    nodoMail* der;
    nodoMail* lista;
public:
    nodoMail(email *m) {
        mail = m;
        izq = NULL;
        der = NULL;
        lista = NULL;
    }
    nodoMail(email m){
        mail = new email;
        *mail = m;
        izq = NULL;
        der = NULL;
        lista = NULL;
    }

    nodoMail* getNext(){
        return lista;
    }

    void setNext(nodoMail* A){
        lista = A;
    }

    nodoMail* getLista(){
        return lista;
    }

    void setLista(nodoMail* lis){
        lista = lis;
    }

    email* getMail() {
        return mail;
    }

    void setMail(email* A) {
        mail = A;
    }

    nodoMail* getIzq(){
        return izq;
    }

    void setIzq(nodoMail* A){
        izq = A;
    }

    nodoMail* getDer(){
        return der;
    }

    void setDer(nodoMail* A) {
        der = A;
    }

    nodoMail* put(email n,int modo);
    nodoMail* put(nodoMail* &n,int modo);
    void getAll(vector<email>* A);
    void getFiltered(vector<email>* A,unsigned long desde,unsigned long hasta);
    void getByFrom(vector<email>* A,string dat);
    email* getId(unsigned long d);
    email* deleteNodo(unsigned long id);
    email* deleteNodoDate(email* m);
    void deleteMail(email* m);
    nodoMail* agregar(nodoMail* &n,int modo);
    nodoMail* getFirstLista();
    nodoMail* addLista(email n);
    nodoMail* addLista(nodoMail* n);
    nodoMail* agregarLista(nodoMail* n);
    email* deleteLista(unsigned long d);
    void getLista(vector<email>* A);
};

class arbolMail {
private:
    nodoMail* raiz;
public:
    arbolMail();

    nodoMail* put(email n,int modo);
    nodoMail* put(nodoMail* n,int modo);
    void getAll(vector<email>* A);
    void getFiltered(vector<email>* A,unsigned long desde,unsigned long hasta);
    void getByFrom(vector<email>* A,string dat);
    email* getId(unsigned long d);
    email* deleteNodo(unsigned long id);
    email* deleteNodoDate(email* m);
    void deleteMail(email* m);
};

#endif // ARBOLMAIL_H
