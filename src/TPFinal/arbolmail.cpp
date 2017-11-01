#include "arbolmail.h"

arbolMail::arbolMail() {
    raiz = NULL;
}

arbolMail::~arbolMail() {

}

nodoMail* arbolMail::put(email n,int modo) {
    if (raiz == NULL) {
        raiz = new nodoMail(n);
        return raiz;
    }
    return raiz->put(n,modo);
}

void arbolMail::put(nodoMail* n,int modo) {
    if (raiz == NULL) {
        raiz = new nodoMail(n->getMail());
        return;
    }
    raiz->put(n,modo);
}

void arbolMail::remove() {

}

bool arbolMail::esVacio() {
    if(raiz == NULL) return 1;
    return 0;
}

void arbolMail::getAll(vector<email> *A) {
    if(raiz == NULL) {
        A->clear();
        return;
    }
    raiz->getAll(A);
}



nodoMail* nodoMail::put(email n,int modo) {
    if(modo == 0) {
        if(n.getDateScore() < this->mail->getDateScore()) {
            if(izq != NULL) {
                return izq->put(n,modo);
            }
            izq = new nodoMail(n);
            return izq;
        }
        if(der != NULL) {
            return der->put(n,modo);
        }
        der = new nodoMail(n);
        return der;
    }
    if(n.compareMailsFrom(mail) < 1) {
        if(izq != NULL) {
            return izq->put(n,modo);
        }
        izq = new nodoMail(n);
        return izq;
    }
    if(der != NULL) {
        return der->put(n,modo);
    }
    der = new nodoMail(n);
    return der;
}

void nodoMail::put(nodoMail* n,int modo) {
    if(modo == 0) {
        if(n->getMail().getDateScore() < mail->getDateScore()) {
            if(izq != NULL) {
                izq->put(n,modo);
                return;
            }
            izq = new nodoMail(n->getMail());
            return;
        }
        if(der != NULL) {
            der->put(n,modo);
            return;
        }
        der = new nodoMail(n->getMail());
        return;
    }
    if(n->getMail().compareMailsFrom(mail) < 1) {
        if(izq != NULL) {
            izq->put(n,modo);
            return;
        }
        izq = new nodoMail(n->getMail());
        return;
    }
    if(der != NULL) {
        der->put(n,modo);
        return;
    }
    der = new nodoMail(n->getMail());
}

void nodoMail::getAll(vector<email> *A) {
    if(izq != NULL) {
        izq->getAll(A);
    }
    A->push_back(this->getMail());
    if(der != NULL) {
        der->getAll(A);
    }
}
