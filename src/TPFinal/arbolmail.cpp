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
    if(raiz->getMail()->id > n.id) {
        if(raiz->getIzq() != NULL) {
            return raiz->getIzq()->put(n,modo);
        }
        raiz->setIzq(new nodoMail(n));
        return raiz->getIzq();
    }
    if(raiz->getDer() != NULL) {
        return raiz->getDer()->put(n,modo);
    }
    raiz->setDer(new nodoMail(n));
    return raiz->getDer();
}

nodoMail* arbolMail::put(nodoMail* n,int modo) {
    if(n == NULL){
        return NULL;
    }
    if (raiz == NULL) {
        raiz = new nodoMail(n->getMail());
        return raiz;
    }
    if(modo == 0) {
        if(raiz->getMail()->getDateScore() > n->getMail()->getDateScore()) {
            if(raiz->getIzq() != NULL) {
                return raiz->getIzq()->put(n,modo);
            }
            raiz->setIzq(new nodoMail(n->getMail()));
            return raiz->getIzq();
        }
        if(n->getMail()->getDateScore() == raiz->getMail()->getDateScore()){
            return raiz->addLista(n);
        }
        if(raiz->getDer() != NULL) {
            return raiz->getDer()->put(n,modo);
        }
        raiz->setDer(new nodoMail(n->getMail()));
        return raiz->getDer();
    }
    if(modo == 1) {
        if(compareFrom(n->getMail()->from,raiz->getMail()->from) < 1) {
            if(raiz->getIzq() != NULL) {
                return raiz->getIzq()->put(n,modo);
            }
            raiz->setIzq(new nodoMail(n->getMail()));
            return raiz->getIzq();
        }
        if(compareFrom(n->getMail()->from,raiz->getMail()->from) == 1){
            return raiz->addLista(n);
        }
        if(raiz->getDer() != NULL) {
            return raiz->getDer()->put(n,modo);
        }
        raiz->setDer(new nodoMail(n->getMail()));
        return raiz->getDer();
    }
    if(raiz->getMail()->id > n->getMail()->id) {
        if(raiz->getIzq() != NULL) {
            return raiz->getIzq()->put(n,modo);
        }
        raiz->setIzq(new nodoMail(n->getMail()));
        return raiz->getIzq();
    }
    if(raiz->getDer() != NULL) {
        return raiz->getDer()->put(n,modo);
    }
    raiz->setDer(new nodoMail(n->getMail()));
    return raiz->getDer();
}

void arbolMail::getAll(vector<email> *A) {
    if(raiz == NULL) {
        A->clear();
        return;
    }
    raiz->getAll(A);
}

void arbolMail::getFiltered(vector<email>* A,unsigned long desde,unsigned long hasta) {
    if(raiz == NULL) {
        A->clear();
        return;
    }
    raiz->getFiltered(A,desde,hasta);
}

void arbolMail::getByFrom(vector<email>* A,string dat) {
    if(raiz == NULL) {
        A->clear();
        return;
    }
    raiz->getByFrom(A,dat);
}

email* arbolMail::getId(unsigned long d){
    if(raiz == NULL){
        return NULL;
    }
    return raiz->getId(d);
}

email* arbolMail::deleteNodo(unsigned long id){
    if(raiz == NULL) {
        return NULL;
    }
    if(raiz->getMail()->id == id){
        email* tmp = raiz->getMail();
        nodoMail* aux = raiz->getDer();
        nodoMail* aux2 = raiz->getIzq();
        delete raiz;
        if(aux2 == NULL){
            raiz = aux;
            return tmp;
        }
        raiz = aux2;
        raiz->put(aux,2);
        return tmp;
    }
    if(id < raiz->getMail()->id) {
        if(raiz->getIzq() != NULL){
            if(raiz->getIzq()->getMail()->id == id) {
                email* tmp = raiz->getIzq()->getMail();
                nodoMail* aux = raiz->getIzq()->getIzq();
                nodoMail* aux2 = raiz->getIzq()->getDer();
                delete raiz->getIzq();
                if(aux2 == NULL){
                    raiz->setIzq(aux);
                    return tmp;
                }
                raiz->setIzq(aux2);
                raiz->getIzq()->put(aux,2);
                return tmp;
            }
            return raiz->getIzq()->deleteNodo(id);
        }
        return NULL;
    }
    if(raiz->getDer() != NULL) {
        if(raiz->getDer()->getMail()->id == id) {
            email* tmp = raiz->getDer()->getMail();
            nodoMail* aux = raiz->getDer()->getDer();
            nodoMail* aux2 = raiz->getDer()->getIzq();
            delete raiz->getDer();
            if(aux2 == NULL) {
                raiz->setDer(aux);
                return tmp;
            }
            raiz->setDer(aux2);
            raiz->getDer()->put(aux,2);
            return tmp;
        }
        return raiz->getDer()->deleteNodo(id);
    }
    return NULL;
}

email* arbolMail::deleteNodoDate(email *m){
    if(m == NULL){
        throw 1;
    }
    if(raiz == NULL){
        return NULL;
    }
    if(m->getDateScore() == raiz->getMail()->getDateScore()){
        if(raiz->getMail()->id == m->id){
            nodoMail* lis = raiz->getLista();
            nodoMail* aux = raiz->getDer();
            nodoMail* aux2 = raiz->getIzq();
            delete raiz;
            if(lis != NULL){
                raiz = lis;
                raiz->put(aux,0);
                raiz->put(aux2,0);
                return m;
            }else{
                if(aux2 == NULL){
                    raiz = aux;
                    return m;
                }
                raiz = aux2;
                raiz->put(aux,0);
                return m;
            }
        }
        return raiz->deleteLista(m->id);
    }
    if(m->getDateScore() < raiz->getMail()->getDateScore()) {
        if(raiz->getIzq() != NULL){
            if(raiz->getIzq()->getMail()->getDateScore() == m->getDateScore()){
                if(raiz->getIzq()->getMail()->id == m->id){
                    nodoMail* lis = raiz->getIzq()->getLista();
                    nodoMail* aux = raiz->getIzq()->getIzq();
                    nodoMail* aux2 = raiz->getIzq()->getDer();
                    delete raiz->getIzq();
                    if(lis != NULL){
                        raiz = lis;
                        raiz->put(aux,0);
                        raiz->put(aux2,0);
                        return m;
                    }else{
                        if(aux2 == NULL){
                            raiz->setIzq(aux);
                            return m;
                        }
                        raiz->setIzq(aux2);
                        raiz->getIzq()->put(aux,0);
                        return m;
                    }
                }
                return raiz->getIzq()->deleteLista(m->id);
            }
            return raiz->getIzq()->deleteNodoDate(m);
        }
        return NULL;
    }
    if(raiz->getDer() != NULL) {
        if(raiz->getDer()->getMail()->getDateScore() == m->getDateScore()){
            if(raiz->getDer()->getMail()->id == m->id){
                nodoMail* lis = raiz->getDer()->getLista();
                nodoMail* aux = raiz->getDer()->getDer();
                nodoMail* aux2 = raiz->getDer()->getIzq();
                delete raiz->getDer();
                if(lis != NULL){
                    raiz = lis;
                    raiz->put(aux,0);
                    raiz->put(aux2,0);
                    return m;
                }else{
                    if(aux2 == NULL){
                        raiz->setDer(aux);
                        return m;
                    }
                    raiz->setDer(aux2);
                    raiz->getDer()->put(aux,0);
                    return m;
                }
            }
            return raiz->getDer()->deleteLista(m->id);
        }
        return raiz->getDer()->deleteNodoDate(m);
    }
    return NULL;
}

void arbolMail::deleteMail(email* m){
    if(m == NULL) {
        throw 1;
    }
    if(raiz == NULL) {
        return;
    }
    if(compareFrom(raiz->getMail()->from,m->from) == 1){
        if(raiz->getMail()->id == m->id){
            nodoMail* lis = raiz->getLista();
            nodoMail* aux = raiz->getDer();
            nodoMail* aux2 = raiz->getIzq();
            delete raiz->getMail();
            delete raiz;
            if(lis != NULL){
                raiz = lis;
                raiz->put(aux,1);
                raiz->put(aux2,1);
                return;
            }else{
                if(aux2 == NULL){
                    raiz = aux;
                    return;
                }
                raiz = aux2;
                raiz->put(aux,1);
                return;
            }
        }
        delete raiz->deleteLista(m->id);
        return;
    }

    if(compareFrom(raiz->getMail()->from,m->from) == 0){
        if(raiz->getDer() != NULL) {
            if(compareFrom(raiz->getDer()->getMail()->from,m->from) == 1){
                if(raiz->getDer()->getMail()->id == m->id) {
                    nodoMail* lis = raiz->getDer()->getLista();
                    nodoMail* aux = raiz->getDer()->getDer();
                    nodoMail* aux2 = raiz->getDer()->getIzq();
                    delete raiz->getDer()->getMail();
                    delete raiz->getDer();
                    if(lis != NULL){
                        raiz = lis;
                        raiz->put(aux,1);
                        raiz->put(aux2,1);
                        return;
                    }else{
                        if(aux2 == NULL){
                            raiz->setDer(aux);
                            return;
                        }
                        raiz->setDer(aux2);
                        raiz->getDer()->put(aux,1);
                        return;
                    }
                }
                delete raiz->getDer()->deleteLista(m->id);
                return;
            }
            raiz->getDer()->deleteMail(m);
            return;
        }
        return;
    }
    if(raiz->getIzq() != NULL) {
        if(compareFrom(raiz->getIzq()->getMail()->from,m->from) == 1){
            if(raiz->getIzq()->getMail()->id == m->id){
                nodoMail* lis = raiz->getIzq()->getLista();
                nodoMail* aux = raiz->getIzq()->getIzq();
                nodoMail* aux2 = raiz->getIzq()->getDer();
                delete raiz->getIzq()->getMail();
                delete raiz->getIzq();
                if(lis != NULL){
                    raiz = lis;
                    raiz->put(aux,1);
                    raiz->put(aux2,1);
                    return;
                }
                if(aux2 == NULL){
                    raiz->setIzq(aux);
                    return;
                }
                raiz->setIzq(aux2);
                raiz->getIzq()->put(aux,1);
                return;
            }
            delete raiz->getIzq()->deleteLista(m->id);
            return;
        }
        raiz->getIzq()->deleteMail(m);
        return;
    }
    return;
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
        if(n.getDateScore() == mail->getDateScore()){
            return addLista(n);
        }
        if(der != NULL) {
            return der->put(n,modo);
        }
        der = new nodoMail(n);
        return der;
    }
    if(modo == 1) {
        if(compareFrom(n.from,mail->from) < 1) {
            if(izq != NULL) {
                return izq->put(n,modo);
            }
            izq = new nodoMail(n);
            return izq;
        }
        if(compareFrom(n.from,mail->from) == 1){
            return addLista(n);
        }
        if(der != NULL) {
            return der->put(n,modo);
        }
        der = new nodoMail(n);
        return der;
    }
    if(this->getMail()->id > n.id){
        if(izq != NULL) {
            return izq->put(n,modo);
        }
        izq = new nodoMail(n);
        return izq;
    }
    if(der != NULL){
        return der->put(n,modo);
    }
    der = new nodoMail(n);
    return der;
}

nodoMail* nodoMail::put(nodoMail* n,int modo) {
    if(n == NULL) return NULL;
    if(modo == 0) {
        if(n->getMail()->getDateScore() < mail->getDateScore()) {
            if(izq != NULL) {
                return izq->put(n,modo);
            }
            izq = new nodoMail(n->getMail());
            return izq;
        }
        if(n->getMail()->getDateScore() == mail->getDateScore()){
            return addLista(n);
        }
        if(der != NULL) {
            return der->put(n,modo);
        }
        der = new nodoMail(n->getMail());
        return der;
    }
    if(modo == 1) {
        if(compareFrom(n->getMail()->from,mail->from) < 1) {
            if(izq != NULL) {
                return izq->put(n,modo);
            }
            izq = new nodoMail(n->getMail());
            return izq;
        }
        if(compareFrom(n->getMail()->from,mail->from) == 1){
            return addLista(n);
        }
        if(der != NULL) {
            return der->put(n,modo);
        }
        der = new nodoMail(n->getMail());
        return der;
    }
    if(this->getMail()->id > n->getMail()->id) {
        if(izq != NULL) {
            return izq->put(n,modo);
        }
        izq = new nodoMail(n->getMail());
        return izq;
    }
    if(this->getMail()->id == n->getMail()->id){
        throw 1;
    }
    if(der != NULL) {
        return der->put(n,modo);
    }
    der = new nodoMail(n->getMail());
    return der;
}

void nodoMail::getAll(vector<email> *A) {
    if(izq != NULL) {
        izq->getAll(A);
    }
    getLista(A);
    if(der != NULL) {
        der->getAll(A);
    }
}

void nodoMail::getFiltered(vector<email>* A,unsigned long desde,unsigned long hasta) {
    if(mail->getDateScore() >= desde) {
        if(izq != NULL) {
            izq->getFiltered(A,desde,hasta);
        }
        if(mail->getDateScore() <= hasta) {
            getLista(A);
            if(der != NULL) {
                der->getFiltered(A,desde,hasta);
            }
        }
    }
    return;
}

void nodoMail::getByFrom(vector<email>* A,string dat) {
    switch (compareFrom(this->getMail()->from,dat)) {
    case 0:
        if(der != NULL) {
            der->getByFrom(A,dat);
        }
        break;
    case 1:
        getLista(A);
        return;
        break;
    case 2:
        if(izq != NULL) {
            izq->getByFrom(A,dat);
        }
        return;
        break;
    }
}

email* nodoMail::getId(unsigned long d){
    if(d < getMail()->id){
        if(izq != NULL){
            return izq->getId(d);
        }
        return NULL;
    }
    if(d > getMail()->id){
        if(der != NULL){
            return der->getId(d);
        }
        return NULL;
    }
    if(d == getMail()->id){
        return getMail();
    }
    return NULL;
}

email* nodoMail::deleteNodo(unsigned long id){
    if(id < this->getMail()->id) {
        if(izq != NULL){
            if(izq->getMail()->id == id) {
                email* tmp = izq->getMail();
                nodoMail* aux = izq->izq;
                nodoMail* aux2 = izq->der;
                delete izq;
                if(aux2 == NULL){
                    izq = aux;
                    return tmp;
                }
                izq = aux2;
                izq->put(aux,2);
                return tmp;
            }
            return izq->deleteNodo(id);
        }
        return NULL;
    }
    if(der != NULL) {
        if(der->getMail()->id == id) {
            email* tmp = der->getMail();
            nodoMail* aux = der->der;
            nodoMail* aux2 = der->izq;
            delete der;
            if(aux2 == NULL){
                der = aux;
                return tmp;
            }
            der = aux2;
            der->put(aux,2);
            return tmp;
        }
        return der->deleteNodo(id);
    }
    return NULL;
}

email* nodoMail::deleteNodoDate(email* m) {
    if(this->getMail()->getDateScore() > m->getDateScore()) {
        if(izq != NULL) {
            if(izq->getMail()->getDateScore() == m->getDateScore()){
                if(izq->getMail()->id == m->id) {
                    nodoMail* lis = izq->getLista();
                    nodoMail* aux = izq->izq;
                    nodoMail* aux2 = izq->der;
                    delete izq;
                    if(lis != NULL){
                        izq = lis;
                        izq->put(aux,0);
                        izq->put(aux2,0);
                        return m;
                    }else{
                        if(aux2 == NULL) {
                            izq = aux;
                            return m;
                        }
                        izq = aux2;
                        izq->put(aux,0);
                        return m;
                    }
                }
                return izq->deleteLista(m->id);
            }
            return izq->deleteNodoDate(m);
        }
        return NULL;
    }
    if(der != NULL){
        if(der->getMail()->getDateScore() == m->getDateScore()){
            if(der->getMail()->id == m->id) {
                nodoMail* lis = der->getLista();
                nodoMail* aux = der->der;
                nodoMail* aux2 = der->izq;
                delete der;
                if(lis != NULL){
                    der = lis;
                    der->put(aux,0);
                    der->put(aux2,0);
                    return m;
                }else{
                    if(aux2 == NULL){
                        der = aux;
                        return m;
                    }
                    der = aux2;
                    der->put(aux,0);
                    return m;
                }
            }
            return der->deleteLista(m->id);
        }
        return der->deleteNodoDate(m);
    }
    return NULL;
}

void nodoMail::deleteMail(email* m){
    if(compareFrom(this->getMail()->from,m->from) == 2){
        if(izq != NULL) {
            if(compareFrom(getIzq()->getMail()->from,m->from) == 1){
                if(izq->getMail()->id == m->id) {
                    nodoMail* lis = izq->getLista();
                    nodoMail* aux = izq->izq;
                    nodoMail* aux2 = izq->der;
                    delete izq->mail;
                    delete izq;
                    if(lis != NULL){
                        izq = lis;
                        izq->put(aux,1);
                        izq->put(aux2,1);
                        return;
                    }else{
                        if(aux2 == NULL){
                            izq = aux;
                            return;
                        }
                        izq = aux2;
                        izq->put(aux,1);
                        return;
                    }
                }
                delete getIzq()->deleteLista(m->id);
                return;
            }
            izq->deleteMail(m);
        }
        return;
    }
    if(der != NULL) {
        if(compareFrom(getDer()->getMail()->from,m->from) == 1){
            if(der->getMail()->id == m->id) {
                nodoMail* lis = der->getLista();
                nodoMail* aux = der->der;
                nodoMail* aux2 = der->izq;
                delete der->mail;
                delete der;
                if(lis != NULL){
                    der = lis;
                    der->put(aux,1);
                    der->put(aux2,1);
                    return;
                }else{
                    if(aux2 == NULL){
                        der = aux;
                        return;
                    }
                    der = aux2;
                    der->put(aux,1);
                    return;
                }
            }
            delete getDer()->deleteLista(m->id);
            return;
        }
        der->deleteMail(m);
    }
    return;
}

nodoMail* nodoMail::addLista(email n){
    nodoMail* aux = new nodoMail(n);
    aux->setNext(lista);
    lista = aux;
    return lista;
}

nodoMail* nodoMail::addLista(nodoMail* n){
    if(n == NULL)return NULL;
    nodoMail* aux = new nodoMail(n->getMail());
    aux->setNext(lista);
    lista = aux;
    return lista;
}

email* nodoMail::deleteLista(unsigned long d){
    if(lista == NULL)return NULL;

    nodoMail* aux = lista;
    if(lista->getMail()->id == d){
        email* ret = lista->getMail();
        lista = lista->getNext();
        delete aux;
        return ret;
    }

    while(aux->getNext() != NULL && aux->getNext()->getMail()->id != d){
        aux = aux->getNext();
    }
    if(aux->getNext()->getMail()->id == d){
        email* ret = aux->getNext()->getMail();
        nodoMail* tmp = aux->getNext();
        aux->setNext(tmp->getNext());
        delete tmp;
        return ret;
    }
    return NULL;
}

void nodoMail::getLista(vector<email>* A){
    A->push_back(*getMail());
    if(lista == NULL){
        return;
    }
    nodoMail* aux = lista;
    while(aux->getNext() != NULL){
        A->push_back(*aux->getMail());
        aux = aux->getNext();
    }
    A->push_back(*aux->getMail());
}
