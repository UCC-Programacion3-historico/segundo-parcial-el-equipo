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
/*
void arbolPalabras::remove(char* pa,int lar, unsigned long d){
    if(raiz == NULL){
        return;
    }
    if(raiz->getId() == d){
        nodoPalabra* aux = raiz->getDer();
        nodoPalabra* aux2 = raiz->getIzq();
        delete raiz;
        if(aux != NULL){
            raiz = aux;
            raiz->put(aux2);
            return;
        }
        if(aux2 != NULL){
            raiz = aux2;
            return;
        }
        raiz = NULL;
        return;
    }

}*/

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
            if(id == d){
                return;
            }
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
        A->push_back(id);
        if(der != NULL){
            der->get(A,texto,len);
        }
        break;
    case 2:
        if(der != NULL){
            der->get(A,texto,len);
        }
        break;
    }
}

void nodoPalabra::remove(char* pa,int lar, unsigned long d){

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
