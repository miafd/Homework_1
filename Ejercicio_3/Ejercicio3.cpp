#include <iostream>
#include <memory>

using namespace std;

// Definición de un nodo
struct Nodo {
    int valor;
    unique_ptr<Nodo> siguiente;
};

// Definición de la lista enlazada
struct ListaEnlazada {
    unique_ptr<Nodo> cabeza = nullptr; // Puntero al primer nodo de la lista
    Nodo* cola = nullptr;              // Puntero al último nodo de la lista
};


