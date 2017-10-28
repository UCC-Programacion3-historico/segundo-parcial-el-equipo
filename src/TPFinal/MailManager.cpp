#include "MailManager.h"

/**
 * Constructor
 */
MailManager::MailManager() {
    FILE* archivo = NULL;
    int largo;

    archivo = fopen("../TPFinal/DBmails.txt","r");
    if (archivo == NULL) {
        throw 1;
    }
    fscanf(archivo," %d",&largo);
    sizeTablaMails = largo;

    tablaMails = new email[largo];
    for(int i; i < largo; i++) {
        fscanf(archivo, " %d",&tablaMails[i].id);
        fgetc(archivo); //Para eliminar el \n

        tablaMails[i].from = new char[20];
        tablaMails[i].to = new char[20];
        tablaMails[i].date = new char[20];
        tablaMails[i].subject = new char[30];
        tablaMails[i].content = new char[250];

        if (fgets(tablaMails[i].from,20,archivo) != NULL) {
            puts(tablaMails[i].from);
        }
        if (fgets(tablaMails[i].to,20,archivo) != NULL) {
            puts(tablaMails[i].to);
        }
        if (fgets(tablaMails[i].date,20,archivo) != NULL) {
            puts(tablaMails[i].date);
        }
        if (fgets(tablaMails[i].subject,30,archivo) != NULL) {
            puts(tablaMails[i].subject);
        }
        if (fgets(tablaMails[i].content,250,archivo) != NULL) {
            puts(tablaMails[i].content);
        }
        fgetc(archivo);
    }
    fclose(archivo);
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

void MailManager::setTablaMails(email* m, int n) {
    if(n > sizeTablaMails) {
        throw 1;
    }
    tablaMails[n] = *m;
}

email* MailManager::getTablaMails(int n) {
    if(n > sizeTablaMails) {
        throw 1;
    }
    return &tablaMails[n];
}
