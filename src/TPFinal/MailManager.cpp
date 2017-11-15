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
    m.id = idMatriz[coordNum[0]]*1000000 + idMatriz[coordNum[1]]*100000 + idMatriz[coordNum[2]]*10000 + idMatriz[coordNum[3]] * 1000 + idMatriz[coordNum[4]]*100  + idMatriz[coordNum[5]]*10 + idMatriz[coordNum[6]];
    coordNum[0]++;
    for(int i = 0;i<7;i++){
        if(coordNum[i] > 6){
            coordNum[i] = 0;
            coordNum[i+1]++;
        }
    }
    tabla.add(arbolFrom.put(arbolDate.put(arbolId.put(m,2),0),1));
}

/**
 * Elimina un mail del gestor
 * @param id identificador del mail a borrar
 */
void MailManager::deleteMail(unsigned long id) {
    email* A = NULL;
    try{
        A = arbolId.deleteNodo(id);
        A = arbolDate.deleteNodoDate(A);
        tabla.deletePalabras(A);
        arbolFrom.deleteMail(A);
    }catch(int e){
        if(e == 1){
            puts("Error al borrar un mail.");
        }
        if(e == 2){
            puts("Hay palabras de mas");
        }
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
    unsigned long a = (desde[0]-48)*10000000 + (desde[1]-48)*1000000 + (desde[2]-48)*100000 + (desde[3]-48)*10000 + (desde[5]-48)*1000 + (desde[6]-48)*100 + (desde[8]-48)*10 + (desde[9]-48);
    unsigned long b = (hasta[0]-48)*10000000 + (hasta[1]-48)*1000000 + (hasta[2]-48)*100000 + (hasta[3]-48)*10000 + (hasta[5]-48)*1000 + (hasta[6]-48)*100 + (hasta[8]-48)*10 + (hasta[9]-48);
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
    try{
        tabla.get(&aux,texto);
    }catch(int e){
        if(e == 1){
            puts("Palabra invalida");
        }
    }
    while(aux.empty() != 1){
        ret.push_back(*arbolId.getId(aux.back()));
        aux.pop_back();
    }
    return ret;
}
