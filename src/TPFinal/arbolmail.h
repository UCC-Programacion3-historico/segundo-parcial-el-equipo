#ifndef ARBOLMAIL_H
#define ARBOLMAIL_H

#include "email.h"


class nodoMail {
private:
    email* mail;
    nodoMail* izq;
    nodoMail* der;
public:
    nodoMail(email *m) {
        mail = m;
        izq = NULL;
        der = NULL;
    }
    nodoMail(email m){
        mail = new email;
        *mail = m;
        izq = NULL;
        der = NULL;
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
    nodoMail* put(nodoMail* n,int modo);
    void getAll(vector<email>* A);
    void getFiltered(vector<email>* A,unsigned long desde,unsigned long hasta);
    void getByFrom(vector<email>* A,string dat);
    email* deleteNodo(unsigned long id);
    email* deleteNodoDate(email* m);
    void deleteMail(email* m);
};

class arbolMail {
private:
    nodoMail* raiz;
public:
    arbolMail();
    ~arbolMail();

    nodoMail* put(email n,int modo);
    nodoMail* put(nodoMail* n,int modo);
    bool esVacio();
    void getAll(vector<email>* A);
    void getFiltered(vector<email>* A,unsigned long desde,unsigned long hasta);
    void getByFrom(vector<email>* A,string dat);
    email* deleteNodo(unsigned long id);
    email* deleteNodoDate(email* m);
    void deleteMail(email* m);
};

#endif // ARBOLMAIL_H
