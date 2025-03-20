#include <iostream>
#include <string>
#include <chrono>

using namespace std;

// Función recursiva usando string
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
    const char* text1_1 = "Este es un ejemplo con un texto de al menos 64 caracteres...";
    const char* text2_1 = "Este es un ejemplo con un texto de al menos 64 caracteres...";
    const char* text3_1 = "Texto distinto para comprobar la funcionalidad.";

    // Comparaciones usando string
    cout << "=== Comparaciones usando string ===" << endl;
    cout << "Comparación 1 (text1 vs text2): " << boolalpha << comparar_recursivo(text1, text2) << endl;
    cout << "Comparación 2 (text1 vs text3): " << boolalpha << comparar_recursivo(text1, text3) << endl;

    // Medición de tiempo para string
    auto startTime1 = chrono::high_resolution_clock::now();
    bool result1 = comparar_recursivo(text1, text2);
    auto endTime1 = chrono::high_resolution_clock::now();
    auto elapsedTime1 = chrono::duration_cast<chrono::nanoseconds>(endTime1 - startTime1);

    cout << "Tiempo de ejecución (string): " << elapsedTime1.count() << " nanosegundos (text1 vs text2)" << endl;

    // Comparaciones usando char*
    cout << "\n=== Comparaciones usando char* ===" << endl;
    cout << "Comparación 3 (text1_1 vs text2_1): " << boolalpha << comparar_recursivo_2(text1_1, text2_1) << endl;
    cout << "Comparación 4 (text1_1 vs text3_1): " << boolalpha << comparar_recursivo_2(text1_1, text3_1) << endl;

    // Medición de tiempo para char*
    auto startTime2 = chrono::high_resolution_clock::now();
    bool result2 = comparar_recursivo_2(text1_1, text2_1);
    auto endTime2 = chrono::high_resolution_clock::now();
    auto elapsedTime2 = chrono::duration_cast<chrono::nanoseconds>(endTime2 - startTime2);

    cout << "Tiempo de ejecución (char*): " << elapsedTime2.count() << " nanosegundos (text1_1 vs text2_1)" << endl;

    // Comparaciones en tiempo de compilación
    cout << "\n=== Comparaciones en Tiempo de Compilación ===" << endl;
    constexpr const char* text4 = "Este es un ejemplo con un texto de al menos 64 caracteres...";
    constexpr const char* text5 = "Este es un ejemplo con un texto de al menos 64 caracteres...";
    constexpr const char* text6 = "Texto distinto para comprobar la funcionalidad.";

    constexpr bool result3 = comparar_recursivo(text4, text5);
    constexpr bool result4 = comparar_recursivo(text4, text6);

    cout << "Comparación 5 (text4 vs text5): " << boolalpha << result3 << endl; // true
    cout << "Comparación 6 (text4 vs text6): " << boolalpha << result4 << endl; // false


    auto startTime3 = chrono::high_resolution_clock::now();
    constexpr bool result5 = comparar_recursivo(text4, text5);
    auto endTime3 = chrono::high_resolution_clock::now();
    auto elapsedTime3 = chrono::duration_cast<chrono::nanoseconds>(endTime3 - startTime3);

    cout << "Tiempo de ejecución: " << elapsedTime3.count() << " nanosegundos" << endl;
    
    return 0;
}

