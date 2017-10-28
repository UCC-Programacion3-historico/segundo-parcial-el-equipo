#include "MailManager.h"

/**
 * Constructor
 *
 * Primero abre la DB y carga la tablaMails
 *
 */
MailManager::MailManager() {
    //Valores iniciales
    tablaMails = NULL;
    sizeTablaMails = 0;

    try {
        initTablaMails();
    }
    catch (int e) {
        if (e == 1) {
            puts("Error al abrir base de datos. El programa va a cerrarse.");
            exit(0);
        }
        if (e == 2) {
            puts("Memoria insuficiente. Problema al reservar memoria. El programa va a cerrarse.");
            exit(0);
        }
        if (e == 3) {
            puts("Error en el archivo DBmails.txt al leer. El programa va a cerrarse.");
            exit(0);
        }
    }
}


/**
 * Agrega un mail al gestor
 * @param m mail a agregar
 */
void MailManager::addMail(email m) {

}


/**
 * Elimina un mail del gestor
 * @param id identificador del mail a borrar
 */
void MailManager::deleteMail(unsigned long id) {

}


/**
 * Devuelve una lista de mails ordenados por fecha
 * @return lista de mails ordenados
 */
vector<email> MailManager::getSortedByDate() {
    vector<email> ret;
    return ret;
}


/**
 * Devuelve una lista de mails oredenados por fecha que estan en el rango
 * desde - hasta
 * @param desde Fecha desde donde buscar
 * @param hasta Fecha hasta donde buscar
 * @return lista de mails ordenados
 */
vector<email> MailManager::getSortedByDate(string desde, string hasta) {
    vector<email> ret;
    return ret;
}


/**
 * Devuelve una lista de mails ordenados por Remitente
 * @return lista de mails ordenados
 */
vector<email> MailManager::getSortedByFrom() {
    vector<email> ret;
    return ret;
}


/**
 * Devuelve una lista de mails de un determinado remitente
 * @param from String con direccion del remitente
 * @return lista de mails del remitente
 */
vector<email> MailManager::getByFrom(string from) {
    vector<email> ret;
    return ret;
}


/**
 * Devuelve una lista de mails que contengan las palabras de 'query'
 * en su asunto o en su contenido
 * @param query String con palabra/s a buscar
 * @return lista de mails que contienen dicha/s palabra/s
 */
vector<email> MailManager::getByQuery(string query) {
    vector<email> ret;
    return ret;
}

/**
 * Devuelve el mail de la posicion n
 * @param n El indice del mail que se quiere buscar
 * @return Puntero del mail en la tabla
 */
email* MailManager::getTablaMails(int n) {
    if(n > sizeTablaMails) {
        throw 1;
    }
    return &tablaMails[n];
}

/**
 * Crea la tabla de mails y la llena con los datos del archivo
 *
 * Throw 1: Error al abrir el archivo
 * Throw 2: Error al reservar memoria
 * Throw 3: Erorr al leer del archivo
 *
 */
void MailManager::initTablaMails() {
    FILE* archivo = NULL;
    int largo;

    archivo = fopen("../TPFinal/DBmails.txt","r");
    if (archivo == NULL) throw 1;

    fscanf(archivo," %d",&largo);
    sizeTablaMails = largo;
    if (largo == 0) {
        fclose(archivo);
        return;
    }

    //Reserva de espacio para la tabla
    try {
        tablaMails = new email[largo];
    } catch (int e) {
        throw 2;
    }

    for(int i; i < largo; i++) {

        //Lectura de ID
        if (fscanf(archivo, " %d",&tablaMails[i].id) < 1) throw 3;
        fgetc(archivo); //Para eliminar el \n

        //Reserva de espacio para los datos del mail
        // #Intentar corregir para que no sean de tamaño estatico
        try {
            tablaMails[i].from = new char[20];
            tablaMails[i].to = new char[20];
            tablaMails[i].date = new char[20];
            tablaMails[i].subject = new char[30];
            tablaMails[i].content = new char[250];
        } catch (int e) {
            throw 2;
        }

        if (fgets(tablaMails[i].from,20,archivo) == NULL) throw 3;
        if (fgets(tablaMails[i].to,20,archivo) == NULL) throw 3;
        if (fgets(tablaMails[i].date,20,archivo) == NULL) throw 3;
        if (fgets(tablaMails[i].subject,30,archivo) == NULL) throw 3;
        if (fgets(tablaMails[i].content,250,archivo) == NULL) throw 3;
        fgetc(archivo);
    }
    fclose(archivo);
}
