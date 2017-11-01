#ifndef EMAIL_H
#define EMAIL_H
#include <string>
#include <vector>
using namespace std;

/**
 * Clase con los datos del mail
 */
class email {
public:
    unsigned long id;
    string from;
    string to;
    string date;
    string subject;
    string content;

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
