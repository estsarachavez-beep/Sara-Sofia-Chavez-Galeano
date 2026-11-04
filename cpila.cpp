#include "cpila.h"
#include <iostream>
using namespace std;

/*
 * POSCONDICIÓN: Inicializa los atributos del objeto pila por defecto.
 *               aInicio, aP y aU en NULL, aN en 0 y aI en false.
 */
cpila::cpila() {
	aInicio = NULL; // Puntero al tope nulo
	aP = NULL;      // Primero nulo
	aU = NULL;      // Último nulo
	aN = 0;         // Conteo de elementos inicial en cero
	aI = false;     // Bandera inicial en falso
}

/*
 * POSCONDICIÓN: Llama al método mDestruir() para liberar toda la memoria dinámica.
 */
cpila::~cpila() {
	mDestruir(); // Libera iterativamente todos los nodos apilados
}

// Getters y Setters
int cpila::getaN() { 
	return aN; 
}
void cpila::setaN(int paN) {
	aN = paN; 
}
bool cpila::getaI() { 
	return aI;
}
void cpila::setaI(bool paI) {
	aI = paI;
}
cnodo* cpila::getaInicio() { 
	return aInicio;
}
void cpila::setaInicio(cnodo* paInicio) {
	aInicio = paInicio;
}
cnodo* cpila::getaP() { 
	return aP;
}
void cpila::setaP(cnodo* paP) { 
	aP = paP;
}
cnodo* cpila::getaU() {
	return aU;
}
void cpila::setaU(cnodo* paU) {
	aU = paU;
}

/*
 * PRECONDICIÓN: La pila no debe estar creada (aInicio == NULL).
 * POSCONDICIÓN: Crea el primer nodo Q en la pila, asigna aInicio = Q, 
 *               aP = Q y aU = Q, incrementa aN y asigna aI = true.
 */
void cpila::mCrear(int pdato) { // Inicio del método mCrear
	if (aInicio == NULL) { // Verifica si la pila está vacía
		cnodo* Q = new cnodo(pdato); // Crea la caja en memoria dinámica
		
		aInicio = Q;  // La une: aInicio apunta a la nueva caja Q
		aP = aInicio; // Pega aP al tope de la pila
		aU = aInicio; // Pega aU a la base de la pila
		
		aN++;         // Incrementa la cantidad de elementos
		aI = true;    // Asigna éxito a la operación
	} else { // Si la pila ya existía
		aI = false;   // Asigna falso indicando fallo
	} // Fin del condicional
	return;
} 

/*
 * PRECONDICIÓN: La pila debe estar creada (aInicio != NULL).
 * POSCONDICIÓN: Apilar (Push): Inserta el nuevo nodo Q arriba del tope actual (aInicio / aP),
 *               lo enlaza (Q->asing = aInicio), actualiza aInicio = Q y aP = Q, incrementa aN y asigna aI = true.
 */
void cpila::mInsertar(int pdato) { // Inicio del método mInsertar 
	if (aInicio != NULL) { // Verifica que la pila exista
		cnodo* Q = new cnodo(pdato); // Crea el nuevo nodo dinámico Q con el dato
		
		Q->asing = aInicio;   // El puntero del nuevo nodo apunta al antiguo tope
		aInicio = Q;          // El nuevo tope pasa a ser Q
		aP = aInicio;         // Mantiene aP actualizado con el tope de la pila
		
		aN++;                 // Incrementa la cantidad de elementos apilados
		aI = true;            // Marca operación exitosa
	} else { // Si la pila no existía
		aI = false;           // Asigna falso notificando fallo
	} // Fin del condicional
	return;
} 
/*
 * PRECONDICIÓN: La pila debe estar creada y contener nodos (aInicio != NULL).
 * POSCONDICIÓN: Recorre e imprime los elementos desde el tope (aP) hacia la base.
 */
void cpila::mVer() {
	if (aInicio != NULL) {
		cnodo* Q = aP; // Inicia en el tope de la pila
		cout << "TOPE -> ";
		while (Q != NULL) {
			cout << "[" << Q->ainfo << "] -> ";
			Q = Q->asing;
		}
		cout << "BASE (NULL)" << endl;
		aI = true;
	} else {
		cout << "La pila esta vacia." << endl;
		aI = false;
	}
	return;
}

/*
 * PRECONDICIÓN: La pila debe poseer elementos registrados (aInicio != NULL).
 * POSCONDICIÓN: Desapilar (Pop): Retira el elemento del tope (LIFO), rescata el dato vx,
 *               reordena aInicio al siguiente nodo, libera aP, actualiza aP = aInicio,
 *               decrementa aN y asigna aI = true.
 */
int cpila::mEliminar() { // Inicio del método mEliminar 
	int vx = 0; // Declara la variable de retorno para el dato del tope
	
	if (aInicio != NULL) { // Verifica que existan nodos a desapilar
		vx = aInicio->ainfo;      // Rescata el valor guardado en el tope
		aInicio = aInicio->asing; // Avanza el tope al nodo de abajo
		
		if (aP == aU) {           // Si se está eliminando el último nodo de la pila
			aU = NULL;            // Limpia la referencia de la base
		}
		
		aP->asing = NULL;         // Desconecta el nodo del tope
		delete aP;                // Libera la memoria del nodo retirado
		aP = aInicio;             // Reasigna aP al nuevo tope (aInicio)
		
		aN--;                     // Decrementa la cantidad total de elementos
		aI = true;                // Marca operación exitosa
	} else { // Si la pila estaba vacía
		aI = false;               // Asigna falso indicando error
	} // Fin del condicional
	
	return vx; // Retorna el entero que estaba en el tope
} // Fin del método mEliminar

/*
 * POSCONDICIÓN: Libera iterativamente la pila llamando a mEliminar() hasta vaciarla.
 */
void cpila::mDestruir() { // Inicio del método mDestruir
	if (aInicio != NULL) { // Verifica si existen nodos por liberar
		while (aInicio != NULL) { // Bucle hasta vaciar el tope
			mEliminar(); // Llama iterativamente a mEliminar()
		} // Fin del bucle
		aInicio = NULL; // Asegura aInicio en NULL
		aP = NULL;      // Asegura aP en NULL
		aU = NULL;      // Asegura aU en NULL
		aN = 0;         // Reinicia el contador a cero
		aI = true;      // Notifica éxito en la destrucción
	} else {
		aI = false;     // Notifica que ya estaba vacía
	}
	return;
} 
