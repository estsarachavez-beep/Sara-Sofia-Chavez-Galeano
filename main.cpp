#include "ccola.h"
#include "clista.h"
#include "cpila.h"
#include <iostream>

using namespace std;

// Declaracion de funciones auxiliares para cada menu
void fnMenuCola(ccola& obj);
void fnMenuLista(clista& obj, clista& objResultado);
void fnMenuPila(cpila& obj);

// Funciones para las operaciones de la cola
void fnCrearCola(ccola& obj);
void fnInsertarCola(ccola& obj);
void fnEliminarCola(ccola& obj);
void fnVerCola(ccola& obj);
void fnDestruirCola(ccola& obj);

// Funciones para las operaciones de la lista
void fnCrearLista(clista& obj);
void fnInsertarLista(clista& obj);
void fnVerDatoLista(clista& obj);
void fnEliminarLista(clista& obj);
void fnDestruirLista(clista& obj);
void fnSumarListas(clista& objResultado);
void fnOrdenarLineal(clista& obj);
void fnOrdenarBurbuja(clista& obj);
void fnInsertarOrdenado(clista& obj);
void fnBusquedaSecuencial(clista& obj);
void fnBusquedaOrdenada(clista& obj);
void fnBusquedaBinaria(clista& obj);
void fnMostrarLista(clista& obj);

// Funciones para las operaciones de la pila
void fnCrearPila(cpila& obj);
void fnApilar(cpila& obj);
void fnDesapilar(cpila& obj);
void fnVerPila(cpila& obj);
void fnDestruirPila(cpila& obj);

/**
 * Menu principal para seleccionar la estructura de datos que se desea utilizar.
 */
int main() {
    ccola objCola;
    clista objLista;
    clista objResultado;
    cpila objPila;
    int vOpcion = 0;

    do {
        cout << "\n===== MENU PRINCIPAL =====" << endl;
        cout << "1. Operaciones con cola" << endl;
        cout << "2. Operaciones con lista" << endl;
        cout << "3. Operaciones con pila" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> vOpcion;

        switch (vOpcion) {
        case 1:
            fnMenuCola(objCola);
            break;
        case 2:
            fnMenuLista(objLista, objResultado);
            break;
        case 3:
            fnMenuPila(objPila);
            break;
        case 4:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion invalida." << endl;
        }
    } while (vOpcion != 4);

    return 0;
}

// ============================================================================
// DEFINICION DE LAS FUNCIONES AUXILIARES
// ============================================================================

// MENU DE LA COLA
void fnMenuCola(ccola& obj) {
    int vOpcion = 0;
    do {
        cout << "\n===== MENU COLA =====" << endl;
        cout << "1. Crear cola" << endl;
        cout << "2. Insertar elemento" << endl;
        cout << "3. Eliminar elemento del frente" << endl;
        cout << "4. Ver elemento del frente" << endl;
        cout << "5. Destruir cola" << endl;
        cout << "6. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> vOpcion;

        switch (vOpcion) {
        case 1: fnCrearCola(obj); break;
        case 2: fnInsertarCola(obj); break;
        case 3: fnEliminarCola(obj); break;
        case 4: fnVerCola(obj); break;
        case 5: fnDestruirCola(obj); break;
        case 6: break;
        default: cout << "Opcion invalida." << endl;
        }
    } while (vOpcion != 6);
}

// 1. CREAR COLA
void fnCrearCola(ccola& obj) {
    int vDato = 0;
    cout << "Ingrese el dato inicial: ";
    cin >> vDato;

    obj.mCrear(vDato);
    if (obj.getaI())
        cout << "Cola creada exitosamente." << endl;
    else
        cout << "No se pudo crear la cola; verifique que este vacia." << endl;
}

// 2. INSERTAR ELEMENTO AL FINAL DE LA COLA
void fnInsertarCola(ccola& obj) {
    int vDato = 0;
    cout << "Ingrese el dato que desea insertar: ";
    cin >> vDato;

    obj.mInsertar(vDato);
    if (obj.getaI())
        cout << "Elemento insertado en la cola." << endl;
    else
        cout << "No se pudo insertar. Primero debe crear la cola." << endl;
}

// 3. ELIMINAR ELEMENTO DEL FRENTE
void fnEliminarCola(ccola& obj) {
    if (obj.getaN() == 0) {
        cout << "La cola esta vacia." << endl;
        return;
    }

    obj.mEliminar();
    if (obj.getaI())
        cout << "Elemento del frente eliminado." << endl;
    else
        cout << "No se pudo eliminar el elemento." << endl;
}

// 4. VER ELEMENTO DEL FRENTE
void fnVerCola(ccola& obj) {
    obj.mVer();
}

// 5. DESTRUIR COLA Y LIBERAR SUS NODOS
void fnDestruirCola(ccola& obj) {
    obj.mDestruir();
    cout << "Cola destruida." << endl;
}

// MENU DE LA LISTA
void fnMenuLista(clista& obj, clista& objResultado) {
    int vOpcion = 0;
    do {
        cout << "\n===== MENU LISTA =====" << endl;
        cout << "1. Crear lista" << endl;
        cout << "2. Insertar por posicion" << endl;
        cout << "3. Ver dato por posicion" << endl;
        cout << "4. Eliminar dato por posicion" << endl;
        cout << "5. Destruir lista" << endl;
        cout << "6. Sumar dos listas" << endl;
        cout << "7. Ordenamiento lineal" << endl;
        cout << "8. Ordenamiento burbuja" << endl;
        cout << "9. Insertar manteniendo el orden" << endl;
        cout << "10. Busqueda secuencial" << endl;
        cout << "11. Busqueda secuencial ordenada" << endl;
        cout << "12. Busqueda binaria" << endl;
        cout << "13. Mostrar lista" << endl;
        cout << "14. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> vOpcion;

        switch (vOpcion) {
        case 1: fnCrearLista(obj); break;
        case 2: fnInsertarLista(obj); break;
        case 3: fnVerDatoLista(obj); break;
        case 4: fnEliminarLista(obj); break;
        case 5: fnDestruirLista(obj); break;
        case 6: fnSumarListas(objResultado); break;
        case 7: fnOrdenarLineal(obj); break;
        case 8: fnOrdenarBurbuja(obj); break;
        case 9: fnInsertarOrdenado(obj); break;
        case 10: fnBusquedaSecuencial(obj); break;
        case 11: fnBusquedaOrdenada(obj); break;
        case 12: fnBusquedaBinaria(obj); break;
        case 13: fnMostrarLista(obj); break;
        case 14: break;
        default: cout << "Opcion invalida." << endl;
        }
    } while (vOpcion != 14);
}

// 1. CREAR LISTA CON NODOS INICIALIZADOS EN CERO
void fnCrearLista(clista& obj) {
    int vTamano = 0;
    cout << "Ingrese la cantidad de nodos que desea crear: ";
    cin >> vTamano;

    obj.mCrearVector(vTamano);
    if (obj.getaI())
        cout << "Lista creada exitosamente." << endl;
    else
        cout << "No se pudo crear la lista. Verifique que este vacia y que el tamano sea mayor que cero." << endl;
}

// 2. INSERTAR DATO EN UNA POSICION DE BASE 1
void fnInsertarLista(clista& obj) {
    int vDato = 0, vPosicion = 0;
    cout << "Ingrese el dato que desea insertar: ";
    cin >> vDato;
    cout << "Ingrese la posicion (comienza en 1): ";
    cin >> vPosicion;

    obj.mInsertar(vDato, vPosicion);
    if (obj.getaI())
        cout << "Dato insertado exitosamente." << endl;
    else
        cout << "No se pudo insertar. Verifique la lista y la posicion." << endl;
}

// 3. CONSULTAR EL DATO QUE SE ENCUENTRA EN UNA POSICION
void fnVerDatoLista(clista& obj) {
    int vPosicion = 0;
    cout << "Ingrese la posicion que desea consultar: ";
    cin >> vPosicion;

    int vResultado = obj.mver(vPosicion);
    if (obj.getaI())
        cout << "El dato en la posicion " << vPosicion << " es: " << vResultado << endl;
    else
        cout << "No existe un dato en esa posicion." << endl;
}

// 4. ELIMINAR UN DATO POR SU POSICION
void fnEliminarLista(clista& obj) {
    int vPosicion = 0;
    cout << "Ingrese la posicion que desea eliminar: ";
    cin >> vPosicion;

    int vResultado = obj.mEliminar(vPosicion);
    if (obj.getaI())
        cout << "El dato eliminado fue: " << vResultado << endl;
    else
        cout << "No se pudo eliminar. Verifique la posicion." << endl;
}

// 5. DESTRUIR LA LISTA Y MOSTRAR LA SUMA DE SUS DATOS
void fnDestruirLista(clista& obj) {
    if (obj.getaN() == 0) {
        cout << "La lista esta vacia." << endl;
        return;
    }

    int vSuma = obj.mDestruir();
    cout << "Lista destruida. Suma de los datos eliminados: " << vSuma << endl;
}

// 6. SUMAR DOS LISTAS DEL MISMO TAMANO
void fnSumarListas(clista& objResultado) {
    int vTamano = 0, vDato = 0;
    clista obj1, obj2;

    cout << "Ingrese el tamano de las dos listas: ";
    cin >> vTamano;
    if (vTamano <= 0) {
        cout << "El tamano debe ser mayor que cero." << endl;
        return;
    }

    obj1.mCrearVector(vTamano);
    obj2.mCrearVector(vTamano);
    if (!obj1.getaI() || !obj2.getaI()) {
        cout << "No se pudieron crear las listas." << endl;
        return;
    }

    cnodo* vNodo = obj1.getaInicio();
    cout << "Ingrese los datos de la primera lista:" << endl;
    for (int i = 1; i <= vTamano; i++) {
        cout << "Elemento " << i << ": ";
        cin >> vDato;
        vNodo->ainfo = vDato;
        vNodo = vNodo->asing;
    }

    vNodo = obj2.getaInicio();
    cout << "Ingrese los datos de la segunda lista:" << endl;
    for (int i = 1; i <= vTamano; i++) {
        cout << "Elemento " << i << ": ";
        cin >> vDato;
        vNodo->ainfo = vDato;
        vNodo = vNodo->asing;
    }

    objResultado.mSumarV(obj1, obj2);
    if (objResultado.getaI()) {
        cout << "Resultado de la suma: ";
        fnMostrarLista(objResultado);
    } else {
        cout << "No se pudieron sumar las listas." << endl;
    }
}

// 7. ORDENAR LA LISTA MEDIANTE EL METODO LINEAL
void fnOrdenarLineal(clista& obj) {
    obj.mOrdLineal();
    if (obj.getaI())
        cout << "Lista ordenada correctamente." << endl;
    else
        cout << "No se pudo ordenar la lista." << endl;
}

// 8. ORDENAR LA LISTA MEDIANTE EL METODO BURBUJA
void fnOrdenarBurbuja(clista& obj) {
    obj.mOrdBurbuja();
    if (obj.getaI())
        cout << "Lista ordenada correctamente." << endl;
    else
        cout << "No se pudo ordenar la lista." << endl;
}

// 9. INSERTAR UN DATO CONSERVANDO EL ORDEN ASCENDENTE
void fnInsertarOrdenado(clista& obj) {
    int vDato = 0;
    cout << "Ingrese el dato que desea insertar ordenadamente: ";
    cin >> vDato;

    obj.mOrdInsercion(vDato);
    if (obj.getaI())
        cout << "Dato insertado en orden." << endl;
    else
        cout << "No se pudo insertar el dato." << endl;
}

// 10. BUSCAR UN DATO MEDIANTE BUSQUEDA SECUENCIAL DIRECTA
void fnBusquedaSecuencial(clista& obj) {
    int vDato = 0;
    cout << "Ingrese el dato que desea buscar: ";
    cin >> vDato;

    int vPosicion = obj.mBusquedaSecD(vDato);
    if (vPosicion != -1)
        cout << "Dato encontrado en la posicion " << vPosicion << endl;
    else
        cout << "Dato no encontrado." << endl;
}

// 11. BUSCAR EN UNA LISTA ORDENADA CON BUSQUEDA SECUENCIAL OPTIMIZADA
void fnBusquedaOrdenada(clista& obj) {
    int vDato = 0;
    cout << "Esta busqueda requiere que la lista este ordenada." << endl;
    cout << "Ingrese el dato que desea buscar: ";
    cin >> vDato;

    int vPosicion = obj.mBusquedaOrdenado(vDato);
    if (vPosicion != -1)
        cout << "Dato encontrado en la posicion " << vPosicion << endl;
    else
        cout << "Dato no encontrado." << endl;
}

// 12. BUSCAR EN UNA LISTA ORDENADA CON BUSQUEDA BINARIA
void fnBusquedaBinaria(clista& obj) {
    int vDato = 0;
    cout << "Esta busqueda requiere que la lista este ordenada." << endl;
    cout << "Ingrese el dato que desea buscar: ";
    cin >> vDato;

    int vPosicion = obj.mBusquedaBinaria(vDato);
    if (vPosicion != -1)
        cout << "Dato encontrado en la posicion " << vPosicion << endl;
    else
        cout << "Dato no encontrado." << endl;
}

// 13. MOSTRAR TODOS LOS ELEMENTOS DE LA LISTA
void fnMostrarLista(clista& obj) {
    cnodo* vNodo = obj.getaInicio();
    if (vNodo == NULL) {
        cout << "La lista esta vacia." << endl;
        return;
    }

    cout << "Lista: ";
    while (vNodo != NULL) {
        cout << vNodo->ainfo;
        if (vNodo->asing != NULL)
            cout << " -> ";
        vNodo = vNodo->asing;
    }
    cout << endl;
}

// MENU DE LA PILA
void fnMenuPila(cpila& obj) {
    int vOpcion = 0;
    do {
        cout << "\n===== MENU PILA =====" << endl;
        cout << "1. Crear pila" << endl;
        cout << "2. Apilar elemento" << endl;
        cout << "3. Desapilar elemento" << endl;
        cout << "4. Ver pila" << endl;
        cout << "5. Destruir pila" << endl;
        cout << "6. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> vOpcion;

        switch (vOpcion) {
        case 1: fnCrearPila(obj); break;
        case 2: fnApilar(obj); break;
        case 3: fnDesapilar(obj); break;
        case 4: fnVerPila(obj); break;
        case 5: fnDestruirPila(obj); break;
        case 6: break;
        default: cout << "Opcion invalida." << endl;
        }
    } while (vOpcion != 6);
}

// 1. CREAR PILA
void fnCrearPila(cpila& obj) {
    int vDato = 0;
    cout << "Ingrese el dato inicial: ";
    cin >> vDato;

    obj.mCrear(vDato);
    if (obj.getaI())
        cout << "Pila creada exitosamente." << endl;
    else
        cout << "No se pudo crear la pila; verifique que este vacia." << endl;
}

// 2. APILAR UN NUEVO ELEMENTO EN EL TOPE
void fnApilar(cpila& obj) {
    int vDato = 0;
    cout << "Ingrese el dato que desea apilar: ";
    cin >> vDato;

    obj.mInsertar(vDato);
    if (obj.getaI())
        cout << "Dato apilado correctamente." << endl;
    else
        cout << "No se pudo apilar. Primero debe crear la pila." << endl;
}

// 3. DESAPILAR Y MOSTRAR EL DATO DEL TOPE
void fnDesapilar(cpila& obj) {
    if (obj.getaN() == 0) {
        cout << "La pila esta vacia." << endl;
        return;
    }

    int vDato = obj.mEliminar();
    if (obj.getaI())
        cout << "El elemento desapilado fue: " << vDato << endl;
    else
        cout << "No se pudo desapilar el elemento." << endl;
}

// 4. MOSTRAR LOS ELEMENTOS DESDE EL TOPE HASTA LA BASE
void fnVerPila(cpila& obj) {
    obj.mVer();
}

// 5. DESTRUIR LA PILA Y LIBERAR SUS NODOS
void fnDestruirPila(cpila& obj) {
    obj.mDestruir();
    cout << "Pila destruida." << endl;
}
