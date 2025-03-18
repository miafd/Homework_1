#include <iostream>
#include <string>

using namespace std;

// Función recursiva para comparar dos cadenas
bool recursiveCompare(const string& str1, const string& str2, size_t index = 0) {
    // Caso base: Si llegamos al final de ambas cadenas, son iguales
    if (index == str1.size() && index == str2.size()) {
        return true;
    }
    // Caso base: Si los caracteres en la posición actual no coinciden
    if (index >= str1.size() || index >= str2.size() || str1[index] != str2[index]) {
        return false;
    }
    // Llamada recursiva para comparar el siguiente carácter
    return recursiveCompare(str1, str2, index + 1);
}

int main() {
    string text1 = "Este es un ejemplo con un texto de al menos 64 caracteres...";
    string text2 = "Este es un ejemplo con un texto de al menos 64 caracteres...";
    string text3 = "Texto distinto para comprobar la funcionalidad.";

    // Pruebas
    cout << "Comparación 1: " << recursiveCompare(text1, text2) << endl; // true
    cout << "Comparación 2: " << recursiveCompare(text1, text3) << endl; // false

    return 0;
}