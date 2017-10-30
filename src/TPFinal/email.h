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

    unsigned long getDateScore();
};


#endif // EMAIL_H
