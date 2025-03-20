#ifndef EJERCICIO1_H
#define EJERCICIO1_H

#include <vector>
#include <iostream>
using namespace std;

// Declaración de funciones

// Función para generar una matriz cuadrada de tamaño n x n con valores consecutivos
vector<vector<int>> generar_matriz(int n);

// Función para imprimir la matriz en orden descendente
void imprimir_matriz_descendente(const vector<vector<int>>& matriz);

#endif