#pragma once
#include "cnodo.h"// Define los nodos enlazados que almacenan los elementos de la cola.
#include <iostream>// Permite mostrar mensajes y datos en la consola.
/*
 * Universidad Militar Nueva Granada
 * Programa de Ingenieria en Multimedia
 * Sara Sofia Chavez Galeano
 * Codigo: 1203029
 * Tania Lorena Triana Espitia
 * Codigo: 1203190
 * Fecha de Realizacion: 4/11/2026
 *Descripcion de la aplicacion:  
 * Aplicacion de consola en C++ para practicar estructuras de datos lineales
 * implementadas con nodos enlazados y memoria dinamica. Desde el menu
 * principal, el usuario puede trabajar con una lista, una cola y una pila.
 * La lista permite crear, insertar, consultar y eliminar datos por posicion,
 * sumar listas, ordenar elementos e implementar busquedas secuenciales y
 * binarias. La cola permite insertar elementos al final y eliminarlos desde
 * el frente, siguiendo el principio FIFO (primero en entrar, primero en salir).
 * La pila permite apilar y desapilar elementos desde el tope, siguiendo el
 * principio LIFO (ultimo en entrar, primero en salir). Las tres estructuras
 * permiten mostrar sus elementos y liberar la memoria al destruirse; comparten
 * la clase cnodo para enlazar los datos.
*/ 
class clista {
private:
	cnodo* aInicio; // Puntero al inicio de la lista
	cnodo* aP;      // Puntero al primer nodo (cabeza)
	cnodo* aU;      // Puntero al ultimo nodo (cola)
	int aN;         // Contador total de nodos en la lista
	bool aI;        // Bandera de estado de la ultima operacion (true/false)

public:
	clista();  // Constructor por defecto
	~clista(); // Destructor para liberar memoria dinamica

	// Getters y Setters
	int getaN();
	void setaN(int paN);
	bool getaI();
	void setaI(bool paI);
	cnodo* getaInicio();
	void setaInicio(cnodo* paInicio);
	cnodo* getaP();
	void setaP(cnodo* paP);
	cnodo* getaU();
	void setaU(cnodo* paU);

	// Metodos de operaciones sobre la lista
	void mCrearVector(int pTamano);   // Crea e inicializa la lista reservando memoria
	void mInsertar(int pdato, int pk); // Inserta un dato en la posicion especificada pk (base 1)
	int mver(int pk);                 // Consulta el dato que esta en la posicion especificada pk
	int mEliminar(int pk);             // Elimina el dato en la posicion pk y ajusta la lista
	int mDestruir();                   // Destruye la lista y devuelve la suma/copia de sus datos
	void mSumarV(clista& pV1, clista& pV2); // Suma dos listas elemento por elemento
	void mOrdLineal();                 // Ordena la lista usando ordenamiento lineal (seleccion/directo)
	void mOrdBurbuja();                // Ordena la lista usando el algoritmo de la burbuja
	void mOrdInsercion(int pdato);     // Inserta un dato manteniendo el orden ascendente de la lista
	int mBusquedaSecD(int pdato);      // Busqueda secuencial directa del elemento pdato
	int mBusquedaOrdenado(int pdato);  // Busqueda secuencial optimizada para lista ordenada
	int mBusquedaBinaria(int pdato);   // Busqueda binaria adaptada sobre los elementos
};
