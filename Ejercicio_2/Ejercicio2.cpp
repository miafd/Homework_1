
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

// Función logMessage punto a
void logMessage(const string& mensaje, NivelSeveridad nivel) {

    ofstream eventos("eventos.txt", ios::app);    // Abre el archivo en modo agregar
    if (!eventos.is_open()) {                     // Si el archivo no pudo abrirse emite mensaje y finaliza con valor 1
        cerr << "Error al abrir el archivo de log." << endl;
        exit(1);                                  // Finaliza el programa con un código de error
    }
    
    // Determina la etiqueta según el nivel de severidad
    string etiqueta;
    switch (nivel) {
        case DEBUG: etiqueta = "[DEBUG]"; break;
        case INFO: etiqueta = "[INFO]"; break;
        case WARNING: etiqueta = "[WARNING]"; break;
        case ERROR: etiqueta = "[ERROR]"; break;
        case CRITICAL: etiqueta = "[CRITICAL]"; break;
        case SECURITY: etiqueta = "[SECURITY]"; break;
        default: etiqueta = "[UNKNOWN]"; break;
    }

    // Escribe el mensaje con el formato esperado
    eventos << etiqueta << " " << mensaje << endl;
    eventos.close();
}

