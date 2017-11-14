#include "email.h"

/**
 * Sobrecarga del operador igual
 * @param c el mail al cual se va a igualar
 */
email &email::operator = (const email &c) {
    id = c.id;
    from = c.from;
    to = c.to;
    date = c.date;
    subject = c.subject;
    content = c.content;
}

/**
 * Funcion para obtener un score que representa a la fecha del mail
 * @return un unsigned long que se puede comparar con otros, para saber cual es mas nuevo o viejo
 */
unsigned long email::getDateScore() {
    return (date[0]-48)*10000000 + (date[1]-48)*1000000 + (date[2]-48)*100000 + (date[3]-48)*10000 + (date[5]-48)*1000 + (date[6]-48)*100 + (date[8]-48)*10 + (date[9]-48);
}

/**
 * Compara los from de dos mails
 * @param A un string
 * @param B el otro string
 * @return 0 si A<B , 1 si A=B , 2 si A>B
 */
int compareFrom(string A, string B) {
    int i = 0;
    do {
        if(A[i] < B[i]) {
            return 0;
        }
        if(B[i] < A[i]) {
            return 2;
        }
        i++;
    }while(A[i] != '\0' && B[i] != '\0');
    if(A[i] == '\0') {
        if(B[i] == '\0') {
            return 1;
        }
        return 0;
    }
    return 2;
}
