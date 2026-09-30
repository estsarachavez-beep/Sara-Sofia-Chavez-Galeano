#pragma once

/**
 * @file miVector.h
 * @brief MOMENTO 1: Declaracion de la clase CmiVector, sus atributos y metodos.
 * 
 * Universidad Militar Nueva Granada
 * Programa de Ingenieria en Multimedia
 * Sara Sofia Chavez Galeano
 * Codigo: 1203029
 * Fecha de realizacion: 30/09/2026
 * 
 * EJEMPLO DE ESTUDIO
 * Tema: Estructuras de Datos Secuenciales, Memoria Dinamica y Pilas (Stack)
 * 
 * Descripcion de la aplicacion:
 * Dada la clase base CmiVector analizada en clase para la gestion de arreglos 
 * dinamicos de tipo entero, este desarrollo permite extender sus funcionalidades 
 * para implementarla como una Estructura de Datos Lineal tipo PILA (Stack) 
 * con capacidad de autorredimension dinamicamente controlada.
 * 
 * Convencion de Estados:
 *  -1 : No creado / Error en asignacion de memoria Heap
 *   0 : Vacio (Objeto/arreglo creado pero aN = 0)
 *  >0 : Con datos (Arreglo con aN elementos almacenados)
 */

class CmiVector {
private:
    // ATRIBUTOS PRIVADOS
    int aM;      // Tamano maximo / capacidad del vector
    int aN;      // Cantidad de elementos actuales (o indice del ultimo elemento)
    int* aArr;   // Apuntador al arreglo dinamico
    bool aI;     // Indicador de exito/fracaso de la ultima operacion

public:
    // Constructor y Destructor
    CmiVector();
    ~CmiVector();

    // Metodos Getters y Setters
    int getaM();
    void setaM(int paM);

    int getaN();
    void setaN(int paN);

    int* getaArr();
    void setaArr(int* paArr);

    bool getaI();
    void setaI(bool paI);

    // Metodos de la clase (MOMENTO 1)
    void mCrearVec(int pTam);
    void minsertar(int pdato, int pk);
    // Mostrar antes y despues de operaciones: el propio metodo hace prints a consola
    int mver(int pk);
    void mVer();
    int mEliminar(int pk);
    int* mDestruir();
    void mSumar(int* pV1, int* pV2);
    void mOrdlineal();
    void mBurbuja();
    void mOrdIns(int pdato);
};

// Declaracion de la funcion global de suma (fuera de la clase)
void fSumar(int* pV1, int* pV2, CmiVector& obj3);
