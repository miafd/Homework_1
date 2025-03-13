
#include <iostream>
#include <vector>   
using namespace std;

// Genera una matriz cuadrada de tamaño n x n con valores consecutivos
vector<vector<int>> generar_matriz(int n) {
    if (n <= 1) {
        cerr << "Error: n debe ser mayor que 1." << endl;
        return {};
    }
    
	vector<vector<int>> matriz(n, vector<int>(n));
	int valor = 1;  // Primer número a colocar en la matriz
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = valor++; // Asigna el valor y  lo incrementa
        }
    }
	return matriz;
}

void imprimir_matriz_descendente(const vector<vector<int>>& matriz) {
    int n = matriz.size();
    int totalElementos = n * n;

    cout << "Matriz en orden descendente:" << endl;
    for (int k = totalElementos - 1; k >= 0; k--) {
        int i = k / n;  // Fila
        int j = k % n;  // Columna
        cout << "M[" << i << "][" << j << "] = " << matriz[i][j] << endl;
    }
}


//main para probar la función 
int main() {
    int n;
    cout << "Ingrese el valor de n: ";
    cin >> n;

    vector<vector<int>> matriz = generar_matriz(n);

    // Imprimir la matriz 
    cout << "Matriz:" << endl;
    for (const auto &fila : matriz) {
        for (int num : fila) {
            cout << num << " ";
        }
        cout << endl;
    }

    imprimir_matriz_descendente(matriz);
    
    return 0;
}