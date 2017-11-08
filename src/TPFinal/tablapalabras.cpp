#include "tablapalabras.h"

tablaPalabras::tablaPalabras()
{

}

void tablaPalabras::add(nodoMail *A){
    if(A == NULL){
        throw 1;
    }
    bool salir = 0;
    char* tmp = &A->getMail()->content[0];
    while(salir == 0){
        if(largoPalabra(tmp) != 0){
            arbolTexto[(largoPalabra(tmp)%SIZE_TABLA)].add(tmp,largoPalabra(tmp),A->getMail()->id);
            tmp = tmp + largoPalabra(tmp);
        }else{
            if(tmp[0] == '\0'){
                salir = 1;
            }else{
                tmp++;
            }
        }
    }
    salir = 0;
    tmp = &A->getMail()->subject[0];
    while(salir == 0){
        if(largoPalabra(tmp) != 0){
            arbolTexto[(largoPalabra(tmp)%SIZE_TABLA)].add(tmp,largoPalabra(tmp),A->getMail()->id);
            tmp = tmp + largoPalabra(tmp);
        }else{
            if(tmp[0] == '\0'){
                salir = 1;
            }else{
                tmp++;
            }
        }
    }
}
/*
void tablaPalabras::deletePalabras(email* A){
    if(A == NULL){
        throw 1;
    }
    bool salir = 0;
    char* tmp = &A->getMail()->content[0];
    while(salir == 0){
        if(largoPalabra(tmp) != 0){
            arbolTexto[(largoPalabra(tmp)%SIZE_TABLA)].remove(tmp,largoPalabra(tmp),A->getMail()->id);
            tmp = tmp + largoPalabra(tmp);
        }else{
            if(tmp[0] == '\0'){
                salir = 1;
            }else{
                tmp++;
            }
        }
    }
    salir = 0;
    tmp = &A->getMail()->subject[0];
    while(salir == 0){
        if(largoPalabra(tmp) != 0){
            arbolTexto[(largoPalabra(tmp)%SIZE_TABLA)].remove(tmp,largoPalabra(tmp),A->getMail()->id);
            tmp = tmp + largoPalabra(tmp);
        }else{
            if(tmp[0] == '\0'){
                salir = 1;
            }else{
                tmp++;
            }
        }
    }
}
*/
void tablaPalabras::get(vector<unsigned long>* A,char* texto){
    if(texto[0] == '\0'){
        throw 1;
    }
    int len = largoPalabra(texto);
    if(len == 0){
        throw 1;
    }
    arbolTexto[(len%SIZE_TABLA)].get(A,texto,len);
}

int largoPalabra(char* A){
    char* tmp = A;
    int cont = 0;
    while(tmp != NULL){
        if((tmp[0]>96 && tmp[0]<123) || (tmp[0]>159 && tmp[0]<166) || (tmp[0]>64 && tmp[0]<91) || (tmp[0]>47 && tmp[0]<58)){
            cont++;
            tmp++;
        }else{
            tmp = NULL;
        }
    }
    return cont;
}
