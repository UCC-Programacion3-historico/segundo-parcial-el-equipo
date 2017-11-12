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
    return (date[0]-48)*10000000 + (date[1]-48)*1000000 + (date[2]-48)*100000 + (date[3]-48)*10000 + (date[5]-48)*1000 + (date[6]-48)*100 + (date[8]-48)*10 + (date[9]-48);
}

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
