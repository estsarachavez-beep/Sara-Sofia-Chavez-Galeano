#pragma once

/**
 * @file miVector.h
 * @brief MOMENTO 1: Declaracion de la clase CmiVector, sus atributos y metodos.
 */

class CmiVector {
private:
    // ATRIBUTOS PRIVADOS
    int aM;      // Tamano maximo / capacidad del vector
    int aN;      // Cantidad de elementos actuales (o indice del
ultimo elemento)
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

    // Metodos de la clase
    void mCrearVec(int pTam);
    void minsertar(int pdato, int pk);
    // Mostrar antes y despues de operaciones: el propio metodo hace
prints a consola
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

