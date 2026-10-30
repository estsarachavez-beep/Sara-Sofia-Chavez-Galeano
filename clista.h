//clista.h

#pragma once // Evita la inclusión múltiple de esta cabecera
/**
 * Universidad Militar Nueva Granada
 * Programa de Ingenieria en Multimedia
 * Sara Sofia Chavez Galeano
 * Codigo: 1203029
 * Fecha de realizacion: 24/10/2026
 *
 * Descripcion de la aplicacion:
 * cmilista es un programa en C++ que gestiona una lista simplemente
 enlazada utilizando memoria dinámica y punteros. Implementa las 5
primitivas básicas
 de listas (mCrear, mInsertar, mEliminar, mVer y mDestruir) para
estructurar, consultar,
 modificar y liberar nodos de manera eficiente a lo largo de dos
etapas de ejecución.
 */
#include "cnodo.h"
#include <iostream>

// Lista simplemente enlazada de enteros.
class clista
{
private:
    cnodo* ainicio; // Primer nodo de la lista.
    int aN;         // Cantidad de nodos.
    bool aI;        // Estado de la última operación.

public:
    clista();
    ~clista();

    int getaN() const;
    bool getaI() const;
    cnodo* getainicio() const;

    // Las cinco primitivas de la lista.
    void mCrear(int pdato);       // Crea el primer nodo.
    void mInsertar(int pdato);    // Inserta al inicio.
    void mEliminar(int p);        // Elimina la posición p; empieza en 1.
    void mVer(int p) const;       // Muestra la posición p.
    void mDestruir();             // Libera todos los nodos.
};
