#include "arbolpalabras.h"

arbolPalabras::arbolPalabras()
{
    raiz = NULL;
}

/**
 * Agrega una palabra al arbol creando el nodo
 * @param pa palabra a agregar
 * @param lar largo de la palabra
 * @param d id del mail al que pertenece la palabra
 */
void arbolPalabras::add(char* pa,int lar, unsigned long d){
    if(raiz == NULL){
        raiz = new nodoPalabra(pa,lar,d);
        return;
    }
    raiz->add(pa,lar,d);
    return;
}

/**
 * Devuelve un vector con las id de los mails que tienen la palabra
 * @param A vector de ids
 * @param texto palabra a buscar
 * @param len largo de la palabra
 */
void arbolPalabras::get(vector<unsigned long>* A,char* texto, int len){
    if(raiz == NULL){
        A->clear();
        return;
    }
    raiz->get(A,texto,len);
}

/**
 * Elimina una palabra del arbol
 * @param pa palabra a eliminar
 * @param lar largo de la palabra
 * @param d id del mail al que pertenece la palabra
 *  Throw 1 no se encontro la palabra
 */
void arbolPalabras::remove(char* pa,int lar, unsigned long d){
    if(raiz == NULL)throw 1;

    if(raiz->getLargo() == lar && comparaPalabra(pa,raiz->getPalabra(),lar) == 1){
        if(raiz->getId() == d){
            nodoPalabra* lis = raiz->getLis();
            nodoPalabra* aux = raiz->getDer();
            nodoPalabra* aux2 = raiz->getIzq();
            delete raiz;
            if(lis != NULL){
                raiz = lis;
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
        try{
            raiz->deleteLista(d);
        }catch(int e){
            if(e == 1){
                throw 1;
            }
        }
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
                        raiz->setIzq(lis);
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
                try{
                    raiz->getIzq()->deleteLista(d);
                }catch(int e){
                    if(e == 1){
                        throw 1;
                    }
                }
                return;
            }
            try{
                raiz->getIzq()->remove(pa,lar,d);
            }catch(int e){
                if(e == 1){
                    throw 1;
                }
            }
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
                    raiz->setDer(lis);
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
            try{
                raiz->getDer()->deleteLista(d);
            }catch(int e){
                if(e == 1){
                    throw 1;
                }
            }
            return;
        }
        try{
            raiz->getDer()->remove(pa,lar,d);
        }catch(int e){
            if(e == 1){
                throw 1;
            }
        }
    }
}

/**
 * Agrega una palabra al arbol creando un nodo nuevo
 * @param pa palabra a agregar
 * @param lar largo de la palabra
 * @param d id del mail al que corresponde la palabra
 */
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

/**
 * Busca el nodo que se quiere devolver
 * @param A vector para almacenar las id de los mail que tienen la palabra buscada
 * @param texto palabra a buscar
 * @param len largo de la palabra
 */
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

/**
 * Elimina una palabra del arbol
 * @param pa palabra a eliminar
 * @param lar largo de la palabra
 * @param d id del mail al que pertenece la palabra
 *  Throw 1 no se encontro el nodo a eliminar
 */
void nodoPalabra::remove(char* pa,int lar, unsigned long d){
    if(largo > lar || (largo == lar && comparaPalabra(pa,palabra,lar) == 0)){
        if(izq != NULL){
            if( izq->getLargo() == lar && comparaPalabra(pa,izq->getPalabra(),lar) == 1){
                if(izq->getId() == d){
                    //Copia los datos del nodo a borrar
                    nodoPalabra* lis = izq->getLis();
                    nodoPalabra* aux = izq->getIzq();
                    nodoPalabra* aux2 = izq->getDer();
                    delete izq;

                    if(lis != NULL){
                        izq = lis;
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
                try{
                    izq->deleteLista(d);
                }catch(int e){
                    if(e == 1){
                        throw 1;
                    }
                }
                return;
            }
            try{
                izq->remove(pa,lar,d);
            }catch(int e){
                if(e == 1){
                    throw 1;
                }
            }
        }
        return;
    }
    if(der != NULL){
        if( der->getLargo() == lar && comparaPalabra(pa,der->getPalabra(),lar) == 1){
            if(der->getId() == d){
                nodoPalabra* lis = der->getLis();
                nodoPalabra* aux = der->getIzq();
                nodoPalabra* aux2 = der->getDer();
                delete der;
                if(lis != NULL){
                    der = lis;
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
            try{
                der->deleteLista(d);
            }catch(int e){
                if(e == 1){
                    throw 1;
                }
            }
        }
        try{
            der->remove(pa,lar,d);
        }catch(int e){
            if(e == 1){
                throw 1;
            }
        }
    }
    return;
}

/**
 * Acomoda nodos existentes en el arbol.
 * @param A nodo a acomodar
 */
void nodoPalabra::put(nodoPalabra* A){
    if(A == NULL)return;
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

/**
 * Busca en la lista si hay una palabra con ese id y la elimina el nodo
 * @param d id del mail que se va a eliminar
 *  Throw 1 es que no encontro la palabra para borrar.
 */
void nodoPalabra::deleteLista(unsigned long d){
    if(lista == NULL)throw 1;
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
    throw 1;
}

/**
 * Agrega una palabra a la lista
 * @param A nodoPalabra a agregar a la lista
 */
void nodoPalabra::addLista(nodoPalabra* A){
    if(A->getId() == id)return;

    if(lista == NULL){
        lista = A;
        return;
    }
    nodoPalabra* aux = lista;

    while (aux->getNext() != NULL && aux->getId() != A->getId()) {
        aux = aux->getNext();
    }
    if(aux->getId() == A->getId())return;
    aux->setNext(A);
}

/**
 * Carga todas las id de que estan en la lista en el vector
 * @param A Vector para almacenar los id
 */
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

/**
 * Compara dos palabras alfabeticamente del mismo largo
 * @param A una palabra
 * @param B la otra palabra
 * @param largo largo de las palabras
 * @return devuelve:
 *  - 0 si A<B
 *  - 1 si A=B
 *  - 2 si A>B
 */
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
