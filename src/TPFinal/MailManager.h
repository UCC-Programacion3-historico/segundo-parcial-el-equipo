#include <string>
#include <vector>
#include <math.h>
#include "email.h"

#ifndef MAILMANAGER_H
#define MAILMANAGER_H

#include <stdio.h>

#include "arbolmail.h"
#include "tablapalabras.h"

using namespace std;

class MailManager {
private:
    // Propiedades y metodos privados de la clase
    arbolMail arbolDate;
    arbolMail arbolFrom;
    arbolMail arbolId;

    tablaPalabras tabla;
public:
    MailManager();

    // Métodos de uso
    void addMail(email m);

    void deleteMail(unsigned long id);

    vector<email> getSortedByDate();

    vector<email> getSortedByDate(string desde, string hasta);

    vector<email> getSortedByFrom();

    vector<email> getByFrom(string from);

    vector<email> getByQuery(string query);
};

#endif // MAILMANAGER_H
