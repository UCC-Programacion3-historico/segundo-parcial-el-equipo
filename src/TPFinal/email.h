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

    unsigned long getDateScore();
};

int compareFrom(string A, string B);

#endif // EMAIL_H
