#include <iostream>
#include <string>
#include <chrono>

using namespace std;

// Función recursiva para comparar dos cadenas
bool comparar_recursivo(const string& str1, const string& str2, size_t index = 0) {
    // Caso base: Si llegamos al final de ambas cadenas, son iguales
    if (index == str1.size() && index == str2.size()) {
        return true;
    }
    // Caso base: Si los caracteres en la posición actual no coinciden
    if (index >= str1.size() || index >= str2.size() || str1[index] != str2[index]) {
        return false;
    }
    // Llamada recursiva para comparar el siguiente carácter
    return comparar_recursivo(str1, str2, index + 1);
}

//Función recursiva usando *char
bool comparar_recursivo_2(const char* str1, const char* str2, size_t index = 0) {
    // Caso base: Si llegamos al final de ambas cadenas, son iguales
    if (str1[index] == '\0' && str2[index] == '\0') {
        return true;
    }
    // Caso base: Si los caracteres en la posición actual no coinciden
    if (str1[index] != str2[index]) {
        return false;
    }
    // Llamada recursiva para comparar el siguiente carácter
    return comparar_recursivo(str1, str2, index + 1);
}

// Función recursiva en tiempo de compilación
constexpr bool comparar_recursivo(const char* str1, const char* str2, size_t index = 0) {
    return (str1[index] == '\0' && str2[index] == '\0') ? true :
           (str1[index] != str2[index]) ? false :
           comparar_recursivo(str1, str2, index + 1);
}



int main() {
    // Definición de textos de prueba
    string text1 = "Este es un ejemplo con un texto de al menos 64 caracteres...";
    string text2 = "Este es un ejemplo con un texto de al menos 64 caracteres...";
    string text3 = "Texto distinto para comprobar la funcionalidad.";
    string text4 = "La imaginación nos permite explorar mundos desconocidos, crear nuevas ideas y soñaar sin limites";
    string text5 = "Este es un ejemplo con un texto de al menos 64 caracteres...Este es un ejemplo con un texto de al menos 64 caracteres...";
    string text6 = "Este es un ejemplo con un texto de al menos 64 caracteres...Este es un ejemplo con un texto de al menos 64 caracteres...";

    // Comparaciones directas
    cout << "=== Comparaciones Directas ===" << endl;
    cout << "Comparación 1 (text1 vs text2): " << boolalpha << comparar_recursivo(text1, text2) << endl;
    cout << "Comparación 2 (text1 vs text3): " << boolalpha << comparar_recursivo(text1, text3) << endl;
    
    // Medición de tiempo para comparaciones largas
    cout << "\n=== Medición de Tiempo ===" << endl;

    auto startTime1 = chrono::high_resolution_clock::now();
    bool result1 = comparar_recursivo(text1, text4);
    auto endTime1 = chrono::high_resolution_clock::now();
    auto elapsedTime1 = chrono::duration_cast<chrono::nanoseconds>(endTime1 - startTime1);

    cout << "Comparación 3 (text1 vs text4): " << boolalpha << result1 << endl;
    cout << "Tiempo de ejecución: " << elapsedTime1.count() << " nanosegundos" << endl;

    auto startTime2 = chrono::high_resolution_clock::now();
    bool result2 = comparar_recursivo(text5, text6);
    auto endTime2 = chrono::high_resolution_clock::now();
    auto elapsedTime2 = chrono::duration_cast<chrono::nanoseconds>(endTime2 - startTime2);

    cout << "Comparación 4 (text5 vs text6): " << boolalpha << result2 << endl;
    cout << "Tiempo de ejecución: " << elapsedTime2.count() << " nanosegundos" << endl;

    // Prueba de la función en tiempo de compilación
    cout << "\n=== Comparaciones en Tiempo de Compilación ===" << endl;
    constexpr const char* text7 = "Este es un ejemplo con un texto de al menos 64 caracteres...";
    constexpr const char* text8 = "Este es un ejemplo con un texto de al menos 64 caracteres...";
    constexpr const char* text9 = "Texto distinto para comprobar la funcionalidad.";

    constexpr bool result3 = comparar_recursivo(text7, text8);
    constexpr bool result4 = comparar_recursivo(text7, text9);

    cout << "Comparación 5 (text7 vs text8): " << boolalpha << result3 << endl; //true
    cout << "Comparación 6 (text7 vs text9): " << boolalpha << result4 << endl; //False

    return 0;
}
