#ifndef ARBOLMAIL_H
#define ARBOLMAIL_H

#include "email.h"

class nodoMail {
private:
    email mail;
    nodoMail* izq;
    nodoMail* der;
public:
    nodoMail(email mail) : mail(mail){
        izq = NULL;
        der = NULL;
    }

    email getMail() {
        return mail;
    }

    nodoMail* put(email n,int modo);
    void put(nodoMail* n,int modo);
    void print(); //Falta implementar
};

class arbolMail {
private:
    nodoMail* raiz;
public:
    arbolMail();
    ~arbolMail();

    nodoMail* put(email n,int modo);
    void remove(); //Sin implementar
    bool esVacio();
    void print();
};

#endif // ARBOLMAIL_H
