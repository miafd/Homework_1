#ifndef EJERCICIO2_H
#define EJERCICIO2_H

#include <iostream>              // Entrada/salida estándar
#include <fstream>               // Manejo de archivos
#include <string>                // Manejo de cadenas de texto
#include <cstdlib>               // Maneja exit() en caso de errores

using namespace std;

// Enumeración para definir niveles de severidad
enum NivelSeveridad {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL,
    SECURITY
};

// Declaración de funciones
void logMessage(const string& mensaje, NivelSeveridad nivel);
void logMessage(const string& mensajeError, const string& archivo, int linea);
void logMessage(const string& mensajeAcceso, const string& nombreUsuario);

#endif
