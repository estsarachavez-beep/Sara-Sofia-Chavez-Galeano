#pragma once

// Nodo de una estructura enlazada.
class cnodo
{
public:
    int ainfo;       // Dato almacenado.
    cnodo* asig;     // Enlace al siguiente nodo.

    explicit cnodo(int pdato = 0) : ainfo(pdato), asig(nullptr) {}
};


