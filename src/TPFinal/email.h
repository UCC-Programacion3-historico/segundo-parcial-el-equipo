#include <string>

#ifndef EMAIL_H
#define EMAIL_H

using namespace std;

/**
 * Clase con los datos del mail
 */
class email {
public:
    unsigned long id;
    char* from;
    char* to;
    char* date;
    char* subject;
    char* content;

    email &operator = (const email &c);

    int compareMailsFrom(email *B);

    unsigned long getDateScore();

    email* izq = NULL;
    email* der = NULL;

    void put(email nuevo);
    email* getFirst(email* root);
    email* get();
};


#endif // EMAIL_H
