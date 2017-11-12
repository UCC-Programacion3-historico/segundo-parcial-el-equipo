#include "arbolpalabras.h"

arbolPalabras::arbolPalabras()
{
    raiz = NULL;
}

void arbolPalabras::add(char* pa,int lar, unsigned long d){
    if(raiz == NULL){
        raiz = new nodoPalabra(pa,lar,d);
        return;
    }
    raiz->add(pa,lar,d);
    return;
}

void arbolPalabras::get(vector<unsigned long>* A,char* texto, int len){
    if(raiz == NULL){
        A->clear();
        return;
    }

    raiz->get(A,texto,len);
}

void arbolPalabras::remove(char* pa,int lar, unsigned long d){
    if(raiz == NULL){
        return;
    }

    if(raiz->getLargo() == lar && comparaPalabra(pa,raiz->getPalabra(),lar) == 1){
        if(raiz->getId() == d){
            nodoPalabra* lis = raiz->getLis();
            nodoPalabra* aux = raiz->getDer();
            nodoPalabra* aux2 = raiz->getIzq();
            delete raiz;
            if(lis != NULL){
                raiz = lis->getFirstLista();
                raiz->put(aux);
                raiz->put(aux2);
                return;
            }
            if(aux2 == NULL){
                raiz = aux;
                return;
            }
            raiz = aux2;
            raiz->put(aux);
            return;
        }
        raiz->deleteLista(d);
        return;
    }
    if(raiz->getLargo() > lar || (raiz->getLargo() == lar && comparaPalabra(pa,raiz->getPalabra(),lar) == 0)){
        if(raiz->getIzq() != NULL){
            if(raiz->getIzq()->getLargo() == lar && comparaPalabra(pa,raiz->getIzq()->getPalabra(),lar) == 1){
                if(raiz->getIzq()->getId() == d){
                    nodoPalabra* lis = raiz->getIzq()->getLis();
                    nodoPalabra* aux = raiz->getIzq()->getIzq();
                    nodoPalabra* aux2 = raiz->getIzq()->getDer();
                    delete raiz->getIzq();
                    if(lis != NULL){
                        raiz->setIzq(lis->getFirstLista());
                        raiz->getIzq()->put(aux);
                        raiz->getIzq()->put(aux2);
                        return;
                    }
                    if(aux2 == NULL){
                        raiz->setIzq(aux);
                        return;
                    }
                    raiz->setIzq(aux2);
                    raiz->getIzq()->put(aux);
                    return;
                }
                raiz->getIzq()->deleteLista(d);
                return;
            }
            raiz->getIzq()->remove(pa,lar,d);
        }
        return;
    }
    if(raiz->getDer() != NULL){
        if(raiz->getDer()->getLargo() == lar && comparaPalabra(pa,raiz->getDer()->getPalabra(),lar) == 1){
            if(raiz->getDer()->getId() == d){
                nodoPalabra* lis = raiz->getDer()->getLis();
                nodoPalabra* aux = raiz->getDer()->getDer();
                nodoPalabra* aux2 = raiz->getDer()->getDer();
                delete raiz->getDer();
                if(lis != NULL){
                    raiz->setDer(lis->getFirstLista());
                    raiz->getDer()->put(aux);
                    raiz->getDer()->put(aux2);
                    return;
                }
                if(aux2 == NULL){
                    raiz->setDer(aux);
                    return;
                }
                raiz->setDer(aux2);
                raiz->getDer()->put(aux);
                return;
            }
            raiz->getDer()->deleteLista(d);
            return;
        }
        raiz->getDer()->remove(pa,lar,d);
    }
}

void arbolPalabras::put(nodoPalabra* A){
    if(A = NULL){
        return;
    }
    if(raiz == NULL){
        raiz = A;
        return;
    }
    raiz->put(A);
}

void nodoPalabra::add(char* pa,int lar, unsigned long d){
    if(lar > largo){
        if(der != NULL){
            der->add(pa,lar,d);
            return;
        }
        der = new nodoPalabra(pa,lar,d);
        return;
    }
    if(lar < largo){
        if(izq != NULL){
            izq->add(pa,lar,d);
            return;
        }
        izq = new nodoPalabra(pa,lar,d);
        return;
    }
    if(comparaPalabra(pa,palabra,largo) > 0){
        if(comparaPalabra(pa,palabra,largo) == 1){
            addLista(new nodoPalabra(pa,lar,d));
            return;
        }
        if(der != NULL){
            der->add(pa,lar,d);
            return;
        }
        der = new nodoPalabra(pa,lar,d);
        return;
    }
    if(izq != NULL){
        izq->add(pa,lar,d);
        return;
    }
    izq = new nodoPalabra(pa,lar,d);
    return;
}

void nodoPalabra::get(vector<unsigned long>* A,char* texto, int len){
    switch (comparaPalabra(texto,palabra,len)) {
    case 0:
        if(izq != NULL){
            izq->get(A,texto,len);
        }
        break;
    case 1:
        getLista(A);
        break;
    case 2:
        if(der != NULL){
            der->get(A,texto,len);
        }
        break;
    }
}

void nodoPalabra::remove(char* pa,int lar, unsigned long d){
    if(largo > lar || (largo == lar && comparaPalabra(pa,palabra,lar) == 0)){
        if(izq != NULL){
            if(comparaPalabra(pa,izq->getPalabra(),lar) == 1 && izq->getLargo() == lar){
                if(izq->getId() == d){
                    nodoPalabra* lis = izq->getLis();
                    nodoPalabra* aux = izq->getIzq();
                    nodoPalabra* aux2 = izq->getDer();
                    delete izq;
                    if(lis != NULL){
                        izq = lis->getFirstLista();
                        izq->put(aux);
                        izq->put(aux2);
                        return;
                    }
                    if(aux2 == NULL){
                        setIzq(aux);
                        return;
                    }
                    setIzq(aux2);
                    izq->put(aux);
                    return;
                }
                izq->deleteLista(d);
                return;
            }
            izq->remove(pa,lar,d);
        }
        return;
    }
    if(der != NULL){
        if(comparaPalabra(pa,der->getPalabra(),lar) == 1 && der->getLargo() == lar){
            if(der->getId() == d){
                nodoPalabra* lis = der->getLis();
                nodoPalabra* aux = der->getIzq();
                nodoPalabra* aux2 = der->getDer();
                delete der;
                if(lis != NULL){
                    der = lis->getFirstLista();
                    der->put(aux);
                    der->put(aux2);
                    return;
                }
                if(aux2 == NULL){
                    setDer(aux);
                    return;
                }
                setDer(aux2);
                der->put(aux);
                return;
            }
            der->deleteLista(d);
            return;
        }
        der->remove(pa,lar,d);
    }
    return;
}

void nodoPalabra::put(nodoPalabra* A){
    if(largo > A->getLargo() || (largo == A->getLargo() && comparaPalabra(A->getPalabra(),palabra,A->getLargo()) == 0)){
        if(izq != NULL){
            izq->put(A);
            return;
        }
        izq = A;
        return;
    }
    if(der != NULL){
        der->put(A);
        return;
    }
    der = A;
    return;
}

nodoPalabra* nodoPalabra::getFirstLista(){
    if(lista == NULL) return NULL;
    nodoPalabra* aux = lista;
    lista = lista->getNext();
    return aux;

}

void nodoPalabra::deleteLista(unsigned long d){
    if(lista == NULL)return;
    nodoPalabra* aux = lista;
    if(lista->id == d){
        lista = lista->getNext();
        delete aux;
        return;
    }

    while(aux->getNext() != NULL && aux->getNext()->id != d){
        aux = aux->getNext();
    }
    if(aux->getNext()->id == d){
        nodoPalabra* tmp = aux->getNext();
        aux->setNext(tmp->getNext());
        delete tmp;
        return;
    }
    return;
}

void nodoPalabra::addLista(nodoPalabra* A){
    if(A->getId() == id){
        return;
    }
    if(lista == NULL){
        lista = A;
        return;
    }
    nodoPalabra* aux = lista;

    while (aux->getNext() != NULL && aux->getId() != A->getId()) {
        aux = aux->getNext();
    }
    if(aux->getId() == A->getId()){
        return;
    }
    aux->setNext(A);
}

void nodoPalabra::getLista(vector<unsigned long>* A){
    A->push_back(id);
    if(lista == NULL)return;
    nodoPalabra* aux = lista;
    while(aux->getNext() != NULL){
        A->push_back(aux->id);
        aux = aux->getNext();
    }
    A->push_back(aux->id);
}

int comparaPalabra(char* A,char* B,int largo){
    int i = 0;
    do{
        if(A[i] < B[i]){
            return 0;
        }
        if(B[i] < A[i]){
            return 2;
        }
        i++;
    }while(i < largo-1);
    return 1;
}
