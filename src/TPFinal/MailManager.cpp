#include "MailManager.h"

/**
 * Constructor
 *
 * Primero abre la DB y carga la tablaMails
 * Despues los ordena y crea las tablas
 *
 */
MailManager::MailManager() {
    //Valores iniciales
    tablaMails = NULL;
    listaNuevos = NULL;
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

    try {
        initTablasOrdenadas();
    }
    catch (int e) {

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
 * devvuelve el mail de la posicion n de la tabla ordenada por fecha
 * @param n Indice del mail que se quiere buscar
 * @return Puntero del mail en la tabla
 */
email* MailManager::getTablaOrdenadaDate(int n) {
    if(n > sizeTablaMails) {
        throw 1;
    }
    return tablaOrdenadaDate[n];
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

    for(int i=0; i < largo; i++) {

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

/**
 * Ordena la tablaMails en dos tablas de punteros.
 */
void MailManager::initTablasOrdenadas() {
    tablaOrdenadaDate = new email*[sizeTablaMails];
    tablaOrdenadaFrom = new email*[sizeTablaMails];

    for(int i=0; i < sizeTablaMails; i++) {
        tablaOrdenadaFrom[i] = &tablaMails[i];
        tablaOrdenadaDate[i] = &tablaMails[i];
    }

    QuickSortDate(tablaOrdenadaDate,0,sizeTablaMails-1);
    QuickSortFrom(tablaOrdenadaFrom,0,sizeTablaMails-1);
}

/**
 * Funcion implementa el algoritmo Quicksort para ordenar por fecha los mails en una tabla
 * @param A tabla para ordenar los mails por fecha
 * @param inicio posicion de la tabla de inicio
 * @param fin posicion de la tabla final
 */
void MailManager::QuickSortDate(email** A,unsigned long inicio,unsigned long fin) {
    if(inicio < fin) {
        int pivot;
        pivot = crearPivotDate(A,inicio,fin);
        if(pivot != 0){
            QuickSortDate(A,inicio,pivot-1);
        }
        QuickSortDate(A,pivot+1,fin);
    }
}
/**
 * Selecciona un valor de la tabla para que sea el pivot.
 *
 *  -Se selecciona como pivot un valor medio entre el inicio, el fin y el valor del medio
 *
 * @param A tabla para ordenar los mails por fecha
 * @param inicio posicion de la tabla inicio
 * @param fin posicion de la tabla final
 * @return devuelve una posicion de memoria que es el pivot
 */
int MailManager::crearPivotDate(email** A,unsigned long inicio,unsigned long fin) {
    unsigned long a = inicio + ((fin-inicio)/2); //Posicion del medio
    unsigned long aux;

    //Seleccion del mejor pivot
    if(A[inicio]->getDateScore() < A[a]->getDateScore()){
        if(A[inicio]->getDateScore() < A[fin]->getDateScore()) {
            if(A[fin]->getDateScore() < A[a]->getDateScore()) {
                aux = fin;
            }else{
                aux = a;
            }
        }else{
            aux = inicio;
        }
    }else{
        if(A[inicio]->getDateScore() < A[fin]->getDateScore()){
            aux = inicio;
        }else{
            if(A[fin]->getDateScore() < A[a]->getDateScore()){
                aux = a;
            }else{
                aux = fin;
            }
        }
    }

    unsigned long pivot = A[aux]->getDateScore();
    int i = (inicio - 1);
    email *tmp;

    for(int j = inicio; j < aux;j++) {
        if (A[j]->getDateScore() <= pivot) {
            i++;
            //Switch
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    //Switch
    tmp = A[i+1];
    A[i+1] = A[aux];
    A[aux] = tmp;

    aux = i+1; //Actualizo la posicion del aux
    i = fin+1; //El i ahora va del final y decrece
    for(int j = fin;j > aux;j--) {
        if(A[j]->getDateScore() > pivot) {
            i--;
            //Switch
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    //Switch
    tmp = A[i-1];
    A[i-1] = A[aux];
    A[aux] = tmp;

    return (i-1);
}

/**
 * devuelve el mail de la posicion n de la tabla ordenada por remitente
 * @param n Indice del mail que se quiere buscar
 * @return Puntero del mail en la tabla
 */
email* MailManager::getTablaOrdenadaFrom(int n) {
    if(n > sizeTablaMails) {
        throw 1;
    }
    return tablaOrdenadaFrom[n];
}

/**
 * Funcion implementa el algoritmo Quicksort para ordenar por remitente los mails en una tabla
 * @param A tabla para ordenar los mails por remitente
 * @param inicio posicion de la tabla de inicio
 * @param fin posicion de la tabla final
 */
void MailManager::QuickSortFrom(email** A,unsigned long inicio,unsigned long fin) {
    if(inicio < fin) {
        int pivot;
        pivot = crearPivotFrom(A,inicio,fin);
        if(pivot != 0){
            QuickSortFrom(A,inicio,pivot-1);
        }
        QuickSortFrom(A,pivot+1,fin);
    }
}

/**
 * Selecciona un valor de la tabla para que sea el pivot.
 *
 *  -Se selecciona como pivot un valor medio entre el inicio, el fin y el valor del medio
 *
 * @param A tabla para ordenar los mails por remitente
 * @param inicio posicion de la tabla inicio
 * @param fin posicion de la tabla final
 * @return devuelve una posicion de memoria que es el pivot
 */
int MailManager::crearPivotFrom(email** A,unsigned long inicio,unsigned long fin) {
    unsigned long a = inicio + ((fin-inicio)/2); //Posicion del medio
    unsigned long aux;

    //Seleccion del mejor pivot
    if(compareMailsFrom(A[a],A[inicio]) == 0) {
        if(compareMailsFrom(A[fin],A[inicio]) == 0) {
            if(compareMailsFrom(A[fin],A[a]) == 0) {
                aux = a;
            }else{
                aux = fin;
            }
        }else{
            aux = inicio;
        }
    }else{
        if(compareMailsFrom(A[fin],A[inicio]) == 0) {
            aux = inicio;
        }else{
            if(compareMailsFrom(A[a],A[fin]) == 0) {
                aux = a;
            }else{
                aux = fin;
            }
        }
    }

    int i = (inicio - 1);
    email *tmp;

    for(int j = inicio; j < aux;j++) {
        if (compareMailsFrom(A[j],A[aux]) < 2) {
            i++;
            //Switch
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    //Switch
    tmp = A[i+1];
    A[i+1] = A[aux];
    A[aux] = tmp;

    aux = i+1; //Actualizo la posicion del aux
    i = fin+1; //El i ahora va del final y decrece
    for(int j = fin;j > aux;j--) {
        if(compareMailsFrom(A[j],A[aux]) == 2) {
            i--;
            //Switch
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    //Switch
    tmp = A[i-1];
    A[i-1] = A[aux];
    A[aux] = tmp;

    return (i-1);
}

/**
 * Funcion para comparar dos mails por remitente
 *
 * @param A
 * @param B
 * @return Devuelve:
 *  0 si A < B
 *  1 Si A = B
 *  2 si A > B
 */
int MailManager::compareMailsFrom(email* A, email* B) {
    int i = 0;
    do {
        if(A->from[i] < B->from[i]) {
            return 0;
        }
        if(B->from[i] < A->from[i]) {
            return 2;
        }
        i++;
    } while(A->from[i] != '\0' && B->from[i] != '\0');
    if(A->from[i] = '\0') {
        if(B->from[i] = '\0') {
            return 1;
        }
        return 0;
    }
    return 2;
}

