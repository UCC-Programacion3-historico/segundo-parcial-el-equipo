#include <string>
#include <vector>
#include <math.h>
#include "email.h"

#ifndef MAILMANAGER_H
#define MAILMANAGER_H

#include <stdio.h>

using namespace std;


class MailManager {
private:
    // Propiedades y metodos privados de la clase
    email* listaNuevos;
    email* tablaMails;

    //Tablas ordenadas
    email** tablaOrdenadaDate;
    email** tablaOrdenadaFrom;
public:
    int sizeTablaMails;
    MailManager();

    // Métodos de uso
    void addMail(email m);

    void deleteMail(unsigned long id);

    vector<email> getSortedByDate();

    vector<email> getSortedByDate(string desde, string hasta);

    vector<email> getSortedByFrom();

    vector<email> getByFrom(string from);

    vector<email> getByQuery(string query);

    email* getTablaMails(int n);

    email* getTablaOrdenadaDate(int n);
    email* getTablaOrdenadaFrom(int n);

    int compareMailsFrom(email* A, email* B);

    void initTablaMails();

    void initTablasOrdenadas();

    void QuickSortDate(email** A,unsigned long inicio,unsigned long fin);
    int crearPivotDate(email** A,unsigned long inicio,unsigned long fin);

    void QuickSortFrom(email** A,unsigned long inicio,unsigned long fin);
    int crearPivotFrom(email** A,unsigned long inicio,unsigned long fin);
};

#endif // MAILMANAGER_H
