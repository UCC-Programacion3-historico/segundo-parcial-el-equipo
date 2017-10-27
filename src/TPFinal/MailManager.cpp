#include "MailManager.h"

/**
 * Constructor
 */
MailManager::MailManager() {
    FILE* archivo = NULL;
    int largo;

    archivo = fopen("../Other Files/DBmails.txt","r");
    if (archivo == NULL) {
        throw 1;
    }
    fscanf(archivo," %d[^\n]",&largo);
    tablaMails = new email[largo];
    for(int i; i < largo; i++) {
        fscanf(archivo, "%d[^\n]",&tablaMails[i].id);
        fscanf(archivo, "%s[^\n]",&tablaMails[i].from);
        fscanf(archivo, "%s[^\n]",&tablaMails[i].to);
        fscanf(archivo, "%s[^\n]",&tablaMails[i].date);
        fscanf(archivo, "%s[^\n]",&tablaMails[i].subject);
        fscanf(archivo, "%s[^\n]",&tablaMails[i].content);
        fgetc(archivo);
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

void setTablaMails(email* m, int n) {
    tablaMails[n]
}

email* getTablaMails(int n) {

}
