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

    email getMail() {
        return *mail;
    }

    nodoMail* put(email n,int modo);
    void put(nodoMail* n,int modo);
    void getAll(vector<email>* A); //Falta implementar
};

class arbolMail {
private:
    nodoMail* raiz;
public:
    arbolMail();
    ~arbolMail();

    nodoMail* put(email n,int modo);
    void put(nodoMail* n,int modo);
    void remove(); //Sin implementar
    bool esVacio();
    void getAll(vector<email>* A);
};

#endif // ARBOLMAIL_H
