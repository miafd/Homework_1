#ifndef EJERCICIO3_H
#define EJERCICIO3_H

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

// Declaración de funciones
unique_ptr<Nodo> create_nodo(int valor);
void push_front(ListaEnlazada &lista, int valor);
void push_back(ListaEnlazada &lista, int valor);
void insert(ListaEnlazada &lista, int valor, size_t index);
void erase(ListaEnlazada &lista, size_t index);
void print_list(ListaEnlazada &lista);

#endif