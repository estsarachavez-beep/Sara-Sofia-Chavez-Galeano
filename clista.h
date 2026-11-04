#pragma once
#include "cnodo.h"
#include <iostream>

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
