
#include "Ejercicio2.h"

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

// Función logMessage sobrecargada para registrar errores con archivo y línea 
void logMessage(const string& mensajeError, const string& archivo, int linea) {
    ofstream eventos("eventos.txt", ios::app);    // Abre el archivo en modo agregar
    if (!eventos.is_open()) {                     // Si el archivo no pudo abrirse emite mensaje y finaliza con valor 1
        cerr << "Error al abrir el archivo de log." << endl;
        exit(1);                                  // Finaliza el programa con un código de error
    }
    // Escribe el mensaje con información adicional
    eventos << "[ERROR] " << mensajeError << " (Archivo: " << archivo << ", Línea: " << linea << ")" << endl;
    eventos.close();
}

// Sobrecarga para registrar eventos de seguridad
void logMessage(const string& mensajeAcceso, const string& nombreUsuario) {

    ofstream eventos("eventos.txt", ios::app);    // Abre el archivo en modo agregar
    if (!eventos.is_open()) {                     // Si el archivo no pudo abrirse emite mensaje y finaliza con valor 1
        cerr << "Error al abrir el archivo de log." << endl;
        exit(1);                                  // Finaliza el programa con un código de error
    }
    // Escribe el mensaje con la etiqueta de seguridad
    eventos << "[SECURITY] Usuario: " << nombreUsuario << " - " << mensajeAcceso << endl;
    eventos.close();
}

// Función principal para probar el sistema de log
int main() {
    // Registrar mensajes de diferentes niveles de severidad
    logMessage("Este es un mensaje de depuración.", DEBUG);
    logMessage("El sistema está funcionando correctamente.", INFO);
    logMessage("Hay una advertencia sobre el uso de memoria.", WARNING);
    logMessage("Se produjo un error al conectar a la base de datos.", ERROR);
    logMessage("El sistema está en estado crítico. Reinicio necesario.", CRITICAL);

    // Registrar un mensaje de error con archivo y línea
    logMessage("Null pointer exception.", "Ejercicio2.cpp", 42);

    // Registrar eventos de seguridad
    logMessage("Access Granted", "admin");
    logMessage("Access Denied", "guest");

    // Simular un error en tiempo de ejecución
    try {
        throw runtime_error("Error crítico en tiempo de ejecución.");
    } catch (const runtime_error& e) {
        logMessage(e.what(), "Ejercicio2.cpp", 66); // Captura el error y lo registra
        cerr << "Se produjo un error en tiempo de ejecución: " << e.what() << endl;
        return 1; // Finaliza con un código de error
    }

    return 0; // Indica que el programa terminó exitosamente
}