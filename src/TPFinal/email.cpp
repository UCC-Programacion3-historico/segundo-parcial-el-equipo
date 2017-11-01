#include "email.h"

email &email::operator = (const email &c) {
    id = c.id;
    from = c.from;
    to = c.to;
    date = c.date;
    subject = c.subject;
    content = c.content;
}

unsigned long email::getDateScore() {
    return date[0]*10000000 + date[1]*1000000 + date[2]*100000 + date[3]*10000 + date[5]*1000 + date[6]*100 + date[8]*10 + date[9];
}

void email::put(email nuevo) {
    if(getDateScore() < nuevo.getDateScore()) {
        if(izq == NULL) {
            izq = new email;
            izq = &nuevo;
            return;
        }
        izq->put(nuevo);
        return;
    }
    if(der == NULL) {
        der = new email;
        der = &nuevo;
        return;
    }
    der->put(nuevo);
}

email* email::getFirst(email* root) {
    if(izq != NULL) {
        email* aux = izq->get();
        if(aux == NULL) {
            email* tmp = izq;
            izq = izq->der;
            return tmp;
        }
        return aux;
    }
    root = der;
    return this;
}

email* email::get() {
    if(izq != NULL) {
        email* aux = izq->get();
        if(aux == NULL) {
            email* tmp = izq;
            izq = izq->der;
            return tmp;
        }
        return aux;
    }
    return NULL;
}

int email::compareMailsFrom(email *B) {
    int i = 0;
    do {
        if(from[i] < B->from[i]) {
            return 0;
        }
        if(B->from[i] < from[i]) {
            return 2;
        }
        i++;
    } while(from[i] != '\0' && B->from[i] != '\0');
    if(from[i] = '\0') {
        if(B->from[i] = '\0') {
            return 1;
        }
        return 0;
    }
    return 2;
}
