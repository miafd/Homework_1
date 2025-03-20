#ifndef EJERCICIO4_H
#define EJERCICIO4_H

#include <iostream>
#include <string>
#include <chrono>

using namespace std;


//Declaración de funciones

// Función recursiva usando string
bool comparar_recursivo(const string& str1, const string& str2, size_t index=0);

// Función recursiva usando char*
bool comparar_recursivo_2(const char* str1, const char* str2, size_t index=0);

// Función recursiva en tiempo de compilación
constexpr bool comparar_recursivo_3(const char* str1, const char* str2, size_t index=0);

#endif
