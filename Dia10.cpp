#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<vector<int>> a;
vector<pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int buscacamino(int x, int y, vector<vector<int>>& dp) {
    if (x < 0 || y < 0 || x >= a.size() || y >= a[0].size()) {
        return 0;
    }
    if (dp[x][y] > 0) {
        return dp[x][y];
    }
    if (a[x][y] == 9) {
        return dp[x][y] = 1;
    }
    
    int total = 0;
    for (pair<int, int> dir : dirs) {
        int r2 = x + dir.first;
        int c2 = y + dir.second;
        // Verificar que r2 y c2 están dentro de los límites antes de acceder a a[r2][c2]
        if (r2 >= 0 && r2 < a.size() && c2 >= 0 && c2 < a[0].size() && a[r2][c2] == a[x][y] + 1) {
            total += buscacamino(r2, c2, dp);
        }
    }
    return dp[x][y] = total;
}

int main() {
    string nombreArchivo = "data10.txt";

    // Abrir el archivo
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo: " << nombreArchivo << endl;
        return 1;
    }

    // Leer el archivo y llenar la matriz
    string linea;
    while (getline(archivo, linea)) {
        vector<int> fila; // Fila temporal para almacenar los valores de la línea
        for (char c : linea) {
            if (isdigit(c)) { // Verificar que el carácter sea un dígito
                fila.push_back(c - '0'); // Convertir carácter a entero y agregar a la fila
            } else {
                cerr << "Error: Se encontró un carácter no numérico en la línea." << endl;
                return 1;
            }
        }
        a.push_back(fila); // Agregar la fila a la matriz
    }

    archivo.close();

    // Mostrar la matriz leída
    for (const auto& fila : a) {
        for (int valor : fila) {
            cout << valor << " "; // Añadir un espacio para mejor legibilidad
        }
        cout << endl;
    }

    // Inicializar la matriz dp a ceros
    vector<vector<int>> dp(a.size(), vector<int>(a[0].size(), 0));

    int total_score = 0;
    for (int row = 0; row < a.size(); row++) {
        for (int col = 0; col < a[0].size(); col++) {
            if (a[row][col] == 0) {
                total_score += buscacamino(row, col, dp);
            }
        }
    }
    
    cout << total_score << endl;
    return 0;
}