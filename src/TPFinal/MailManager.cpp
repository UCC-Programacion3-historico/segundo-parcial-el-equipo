#include "MailManager.h"

/**
 * Constructor
 *
 */
MailManager::MailManager() {

}


/**
 * Agrega un mail al gestor
 * @param m mail a agregar
 */
void MailManager::addMail(email m) {
    tabla.add(arbolFrom.put(arbolDate.put(arbolId.put(m,2),0),1));
}


/**
 * Elimina un mail del gestor
 * @param id identificador del mail a borrar
 */
void MailManager::deleteMail(unsigned long id) {
    email* A =  NULL;

    try{
        A = arbolId.deleteNodo(id);
        //tabla.deletePalabras(A);
        A = arbolDate.deleteNodoDate(A);
        arbolFrom.deleteMail(A);
    }catch(int e){
        puts("error 1");
    }
}


/**
 * Devuelve una lista de mails ordenados por fecha
 * @return lista de mails ordenados
 */
vector<email> MailManager::getSortedByDate() {
    vector<email> A;
    arbolDate.getAll(&A);
    return A;
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
    unsigned long a = desde[0]*10000000 + desde[1]*1000000 + desde[2]*100000 + desde[3]*10000 + desde[5]*1000 + desde[6]*100 + desde[8]*10 + desde[9];
    unsigned long b = hasta[0]*10000000 + hasta[1]*1000000 + hasta[2]*100000 + hasta[3]*10000 + hasta[5]*1000 + hasta[6]*100 + hasta[8]*10 + hasta[9];
    arbolDate.getFiltered(&ret,a,b);
    return ret;
}


/**
 * Devuelve una lista de mails ordenados por Remitente
 * @return lista de mails ordenados
 */
vector<email> MailManager::getSortedByFrom() {
    vector<email> ret;
    arbolFrom.getAll(&ret);
    return ret;
}


/**
 * Devuelve una lista de mails de un determinado remitente
 * @param from String con direccion del remitente
 * @return lista de mails del remitente
 */
vector<email> MailManager::getByFrom(string from) {
    vector<email> ret;
    arbolFrom.getByFrom(&ret,from);
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
    char *texto = (char*)query.c_str();
    vector<unsigned long> aux;
    tabla.get(&aux,texto);

    while(aux.empty() != 1){
        ret.push_back(*arbolId.getId(aux.back()));
        aux.pop_back();
    }
    return ret;
}
