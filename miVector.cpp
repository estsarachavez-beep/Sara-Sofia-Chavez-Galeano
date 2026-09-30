#include "miVector.h"
#include <iostream>

using namespace std;

/**
 * Universidad Militar Nueva Granada
 * Programa de Ingenieria en Multimedia
 * Sara Sofia Chavez Galeano
 * Codigo 1203029
 * Fecha de realizacion 30/09/2026
* Descripcion de la aplicacion:
 * El programa administra un arreglo dinamico de enteros mediante la
clase CmiVector.
 * Se sobrecarga el metodo mVer para tener un solo punto de acceso a
la visualizacion:
 *  - mVer(): Imprime en pantalla el vector completo con sus metricas
(aN, aM, aI).
 *  - mVer(int pk): Consulta y retorna el elemento especifico en el indice pk.
 */

 // Constructor: Inicializa las variables en un estado vacio/seguro
CmiVector::CmiVector() {
    aM = 0;
    aN = 0;        // Cantidad de elementos almacenados
    aI = false;   // Estado inicial de operacion
    aArr = NULL;
}

// Destructor: Libera la memoria si existe
CmiVector::~CmiVector() {
    if (aArr != NULL) {
        delete[] aArr;
        aArr = NULL;
    }
    aM = 0;
    aN = 0;
    aI = false;
}

// Getters y Setters
int CmiVector::getaM() { return aM; }
void CmiVector::setaM(int paM) { aM = paM; }

int CmiVector::getaN() { return aN; }
void CmiVector::setaN(int paN) { aN = paN; }

int* CmiVector::getaArr() { return aArr; }
void CmiVector::setaArr(int* paArr) { aArr = paArr; }

bool CmiVector::getaI() { return aI; }
void CmiVector::setaI(bool paI) { aI = paI; }

// Crear el arreglo dinamico
void CmiVector::mCrearVec(int pTam) {
    if (pTam > 0 && pTam < 1000) {
        if (aArr != NULL) {
            delete[] aArr; // Si ya existia un arreglo, lo liberamos antes
        }
        aM = pTam;
        aArr = new int[aM];
        // Inicializar los elementos a 0 para evitar valores basura
        for (int i = 0; i < aM; i++) {
            aArr[i] = 0;
        }
        aN = 0;
        aI = true;
    }
    else {
        aI = false;
    }
}

// Insertar un dato en la posicion pk (0 <= pk <= aN)
// Insertar o asignar un dato en la posicion pk (0 <= pk < aM).
// Si se asigna en una posicion mayor que aN-1, se actualiza aN al
nuevo tama o utilizado.
void CmiVector::minsertar(int pdato, int pk) {
    if (aArr != NULL && pk >= 0 && pk < aM) {
        cout << "Antes de insertar: ";
        mVer();

        aArr[pk] = pdato; // Asignaci n directa en la posici n
        if (pk >= aN) {
            aN = pk + 1; // Actualiza la cantidad de elementos usados
        }
        aI = true;

        cout << "Despues de insertar: ";
        mVer();
    }
    else {
        aI = false;
    }
}

// CORRECCIÓN DEL MÉTODO mver(pk)
int CmiVector::mver(int pk) {
    int aux = -1; // Valor por defecto si falla la búsqueda

    // Rango válido: desde 0 hasta aN - 1
    if (aArr != NULL && pk >= 0 && pk < aN) {
        aux = aArr[pk];
        aI = true;
    }
    else {
        aI = false;
    }

    return aux;
}

// Método mVer() para mostrar todo el vector
void CmiVector::mVer() {
    if (aArr != NULL && aN > 0) {
        cout << "Vector: [ ";
        for (int i = 0; i < aN; i++) {
            cout << aArr[i] << " ";
        }
        cout << "]" << endl;
    }
    else {
        cout << "El vector está vacío o no ha sido creado." << endl;
    }
}

// Eliminar un dato en la posicion pk (0 <= pk < aN)
int CmiVector::mEliminar(int pk) {
    int aux = -1;
    if (aArr != NULL && pk >= 0 && pk < aN) {
        cout << "Antes de eliminar: ";
        mVer();

        aux = aArr[pk];
        // Desplazamos los elementos a la izquierda para cubrir la vacante
        for (int i = pk; i < aN - 1; i++) {
            aArr[i] = aArr[i + 1];
        }
        aN--;
        aI = true;

        cout << "Despues de eliminar: ";
        mVer();
    }
    else {
        aI = false;
    }
    return aux;
}

// Destruir el vector y devolver una copia de los datos antes de borrarlo
int* CmiVector::mDestruir() {
    if (aArr == NULL || aN == 0) {
        aI = false;
        return NULL;
    }

    cout << "Antes de destruir: ";
    mVer();

    int* vAux = new int[aN]; // Arreglo para guardar la copia
    for (int i = 0; i < aN; i++) {
        vAux[i] = aArr[i];
    }

    delete[] aArr;
    aArr = NULL;
    aM = 0;
    aN = 0;
    aI = true;

    cout << "Despues de destruir: ";
    mVer();

    return vAux; // Devuelve la copia guardada
}

// Sumar los vectores pV1 y pV2 guardando el resultado en el objeto actual
void CmiVector::mSumar(int* pV1, int* pV2) {
    if (aArr != NULL && pV1 != NULL && pV2 != NULL) {
        cout << "Antes de sumar (vector resultado): ";
        mVer();

        for (int i = 0; i < aM; i++) {
            aArr[i] = pV1[i] + pV2[i];
        }
        aN = aM; // Se actualiza la cantidad de elementos almacenados
        aI = true;

        cout << "Despues de sumar (vector resultado): ";
        mVer();
    }
    else {
        aI = false;
    }
}

// Funcion global auxiliar de suma
void fSumar(int* pV1, int* pV2, CmiVector& obj3) {
    obj3.mSumar(pV1, pV2);
}

// Ordenamiento Lineal / Seleccion
void CmiVector::mOrdlineal() {
    int vAux = 0;
    // Se corrigen indices a base 0 (de 0 a aN - 1) para evitar
desbordamientos y bucles infinitos
    if (aArr != NULL && aN > 1) {
        cout << "Antes de ordenamiento (seleccion): ";
        mVer();

        for (int i = 0; i < aN - 1; i++) {
            for (int j = i + 1; j < aN; j++) {
                if (aArr[i] > aArr[j]) {
                    vAux = aArr[i];
                    aArr[i] = aArr[j];
                    aArr[j] = vAux;
                }
            }
        }
        aI = true;

        cout << "Despues de ordenamiento (seleccion): ";
        mVer();
    }
    else {
        aI = false;
    }
}

// Ordenamiento Burbuja
void CmiVector::mBurbuja() {
    int vAux = 0;
    bool flag = true;

    // Se ajustan indices a base 0 (i va de 0 a aN - 2 para que i + 1
no se salga del arreglo)
    if (aArr != NULL && aN >= 2) {
        cout << "Antes de ordenamiento (burbuja): ";
        mVer();

        while (flag == true) {
            flag = false;
            for (int i = 0; i < aN - 1; i++) {
                if (aArr[i] > aArr[i + 1]) {
                    vAux = aArr[i];
                    aArr[i] = aArr[i + 1];
                    aArr[i + 1] = vAux;
                    flag = true;
                }
            }
        }
        aI = true;

        cout << "Despues de ordenamiento (burbuja): ";
        mVer();
    }
    else {
        aI = false;
    }
}

// Ordenamiento por Insercion de un nuevo dato
void CmiVector::mOrdIns(int pdato) {
    // Se inserta pdato manteniendo el vector ordenado
    if (aArr != NULL && aN < aM) {
        cout << "Antes de insercion ordenada: ";
        mVer();

        int i = aN - 1;
        while (i >= 0 && aArr[i] > pdato) {
            aArr[i + 1] = aArr[i]; // Desplaza elementos mayores a la derecha
            i--;
        }
        aArr[i + 1] = pdato;
        aN++;
        aI = true;

        cout << "Despues de insercion ordenada: ";
        mVer();
    }
    else {
        aI = false;
    }
}
