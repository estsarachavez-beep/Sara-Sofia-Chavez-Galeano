#include "miVector.h"
#include <iostream>

using namespace std;

/**
 * MOMENTO 3: Menu principal e interaccion con el usuario
 */

 // Declaracion de funciones auxiliares para cada opcion del menu
void fnCrearVector(CmiVector& obj);
void fnInsertarDato(CmiVector& obj);
void fnVerDato(CmiVector& obj);
void fnVerTodoElVector(CmiVector& obj);
void fnEliminarDato(CmiVector& obj);
void fnDestruirVector(CmiVector& obj);
void fnSumarVectores(CmiVector& obj1, CmiVector& obj2, CmiVector& obj3);
void fSumar(int* pV1, int* pV2, CmiVector& obj3);
void mOrdlineal(CmiVector& obj);
void mBurbuja(CmiVector& obj);
void mOrdIns(CmiVector& obj);

int main() {
    CmiVector obj1;
    CmiVector obj2;
    CmiVector obj3;

    int vOpcion = 0;

    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Crear vector" << endl;
        cout << "2. Insertar" << endl;
        cout << "3. Ver dato por posicion" << endl;
        cout << "4. Ver todo el vector" << endl;
        cout << "5. Eliminar dato" << endl;
        cout << "6. Destruir vector" << endl;
        cout << "7. Sumar vectores" << endl;
        cout << "8. Ordenamiento lineal" << endl;
        cout << "9. Ordenamiento Burbuja" << endl;
        cout << "10. Ordenamiento por insercion" << endl;
        cout << "11. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> vOpcion;

        switch (vOpcion) {
        case 1:
            fnCrearVector(obj1);
            break;

        case 2:
            fnInsertarDato(obj1);
            break;
        case 3:
            fnVerDato(obj1);
            break;

        case 4:
            fnVerTodoElVector(obj1);
            break;
        case 5:
            fnEliminarDato(obj1);
            break;

        case 6:
            fnDestruirVector(obj1);
            break;

        case 7:
            fnSumarVectores(obj1, obj2, obj3);
            break;

        case 8:
            mOrdlineal(obj1);
            break;

        case 9:
            mBurbuja(obj1);
            break;

        case 10:
            mOrdIns(obj1);
            break;

        case 11:
            cout << "Saliendo del programa..." << endl;
            break;

        default:
            cout << "Opcion invalida." << endl;
        }

    } while (vOpcion != 11); // Salir cuando el usuario seleccione la opcion 11

    return 0;
}

// DEFINICION DE LAS FUNCIONES PARA CADA CASE

void fnCrearVector(CmiVector& obj) {
    int vx = 0;
    cout << "Ingrese el tamano del vector: ";
    cin >> vx;
    obj.mCrearVec(vx);
    if (obj.getaI()) {
        cout << "Vector creado exitosamente." << endl;
    }
    else {
        cout << "Error al crear el vector." << endl;
    }
}

void fnInsertarDato(CmiVector& obj) {
    int vdato = 0, vpos = 0, vx = 0, resul = 0;
    cout << "Ingrese el dato a insertar: ";
    cin >> vdato;
    cout << "Ingrese la posicion: ";
    cin >> vpos;

    obj.minsertar(vdato, vpos);

    if (obj.getaI()) {
        cout << "Insercion realizada." << endl;
        cout << "¿Que posicion quiere ver?: ";
        cin >> vx;
        if (vx >= 0 && vx < obj.getaN()) {
            resul = obj.mver(vx);
            cout << "El dato es: " << resul << endl;
        }
        else {
            cout << "Posicion fuera de rango." << endl;
        }
    }
    else {
        cout << "No se pudo insertar el dato." << endl;
    }
}
// 3. VER DATO EN UNA POSICIÓN ESPECÍFICA (Ajustado a índices base 0)
void fnVerDato(CmiVector& obj) {
    int vx = 0, resul = 0;

    if (obj.getaN() == 0) {
        cout << "El vector esta vacio." << endl;
        return;
    }

    cout << "Ingrese la posicion que quiere ver (0 a " << obj.getaN()
- 1 << "): ";
    cin >> vx;

    resul = obj.mver(vx);

    if (obj.getaI()) {
        cout << "El dato en la posicion " << vx << " es: " << resul << endl;
    }
    else {
        cout << "No hay dato disponible en esa posicion." << endl;
    }
}

// 4. VER TODO EL VECTOR
void fnVerTodoElVector(CmiVector& obj) {
    obj.mVer();
}
void fnEliminarDato(CmiVector& obj) {
    int vx = 0, Res = 0, resul = 0;
    cout << "¿Que posicion desea eliminar?: ";
    cin >> vx;
    Res = obj.mEliminar(vx);

    if (obj.getaI()) {
        cout << "El valor eliminado fue: " << Res << endl;

        cout << "¿Que posicion quiere ver ahora?: ";
        cin >> vx;
        if (vx >= 0 && vx < obj.getaN()) {
            resul = obj.mver(vx);
            cout << "El dato es: " << resul << endl;
        }
        else {
            cout << "No hay dato en esa posicion." << endl;
        }
    }
    else {
        cout << "La operacion no se pudo realizar." << endl;
    }
}

void fnDestruirVector(CmiVector& obj) {
    int vx = obj.getaN();
    int* vAux2 = obj.mDestruir();

    if (obj.getaI() && vAux2 != NULL) {
        for (int i = 0; i < vx; i++) {
            cout << "Eliminado: " << vAux2[i] << endl;
        }
        delete[] vAux2; // Liberamos la memoria del vector auxiliar retornado
    }
    else {
        cout << "No se pudo destruir el vector o esta vacio." << endl;
    }
}

void fnSumarVectores(CmiVector& obj1, CmiVector& obj2, CmiVector& obj3) {
    int tam = 0;
    cout << "Ingrese el tamano para los vectores a sumar: ";
    cin >> tam;

    if (tam <= 0) {
        cout << "Tamano invalido." << endl;
        return;
    }

    obj1.mCrearVec(tam);
    obj2.mCrearVec(tam);

    if (!obj1.getaI() || !obj2.getaI()) {
        cout << "No se pudieron crear los vectores." << endl;
        return;
    }

    int val = 0;
    cout << "Ingrese los elementos del primer vector:" << endl;
    for (int i = 0; i < tam; i++) {
        cout << "Elemento " << i << ": ";
        cin >> val;
        obj1.minsertar(val, i);
        if (!obj1.getaI()) {
            cout << "Error al insertar en el primer vector." << endl;
            return;
        }
    }

    cout << "Ingrese los elementos del segundo vector:" << endl;
    for (int i = 0; i < tam; i++) {
        cout << "Elemento " << i << ": ";
        cin >> val;
        obj2.minsertar(val, i);
        if (!obj2.getaI()) {
            cout << "Error al insertar en el segundo vector." << endl;
            return;
        }
    }

    obj3.mCrearVec(tam);
    if (!obj3.getaI()) {
        cout << "No se pudo crear el vector resultado." << endl;
        return;
    }

    fSumar(obj1.getaArr(), obj2.getaArr(), obj3);

    if (obj3.getaI()) {
        cout << "Resultado de la suma: ";
        obj3.mVer();
    }
    else {
        cout << "No se pudo sumar los vectores." << endl;
    }
}

// ORDENAMIENTO LINEAL
void mOrdlineal(CmiVector& obj1) {
    obj1.mOrdlineal();

    if (obj1.getaI()) {
        cout << "Vector ordenado correctamente." << endl;
    }
    else {
        cout << "No se pudo ordenar el vector." << endl;
    }
}

// ORDENAMIENTO BURBUJA
void mBurbuja(CmiVector& obj1) {
    obj1.mBurbuja();

    if (obj1.getaI()) {
        cout << "Vector ordenado correctamente." << endl;
    }
    else {
        cout << "No se pudo ordenar el vector." << endl;
    }
}

// ORDENAMIENTO POR INSERCION
void mOrdIns(CmiVector& obj1) {
    int vx = 0;
    cout << "Ingrese el dato a insertar de forma ordenada: ";
    cin >> vx;
    obj1.mOrdIns(vx);
    if (obj1.getaI()) {
        cout << "Vector ordenado correctamente." << endl;
    }
    else {
        cout << "No se pudo ordenar el vector." << endl;
    }
}
