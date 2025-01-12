#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int id = 1000;
vector<vector<int>> a;
vector<pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<bool>> vis;

int W, H;
class pu{
    public:
    int pt;//salidas posibles
    int id;//id del camino
};
int buscacamino(int x, int y, vector<vector<pu>>& dp) {

    if (x < 0 || y < 0 || x >= a.size() || y >= a[0].size()) { // se comprueba que no se salga de la matriz
        return 0;
    }
    if (dp[x][y].pt > 0) { // si la casilla ya fue visitada
        return dp[x][y].pt;
    }
    if (a[x][y] == 9) {// si la casilla es 9 se sumara 1 al camino
        dp[x][y].pt=1;
        dp[x][y].id= id; // cada camino tiene un id diferente
        id--; 
        cout << id << endl;
        return dp[x][y].pt;
    }
    
    int total = 0;
    int id1, id2, id3, id4;
    int v1=0, v2=0, v3=0, v4=0;
    int i=0;
    for (pair<int, int> dir : dirs) { // se recorre en las 4 direcciones
        int r2 = x + dir.first;
        int c2 = y + dir.second;
        // Verificar que r2 y c2 están dentro de los límites antes de acceder a a[r2][c2]
        if (r2 >= 0 && r2 < a.size() && c2 >= 0 && c2 < a[0].size() && a[r2][c2] == a[x][y] + 1) {
            switch(i){
                case 0:
                    v1=buscacamino(r2, c2, dp);
                    id1=dp[r2][c2].id;
                    dp[x][y].id=id1;
                    total+=v1;
                    break;
                case 1:
                    v2=buscacamino(r2, c2, dp);
                    id2=dp[r2][c2].id;
                    dp[x][y].id=id2;
                    total+=v2;
                    break;
                case 2:
                    v3=buscacamino(r2, c2, dp);
                    id3=dp[r2][c2].id;
                    dp[x][y].id=id3;
                    total+=v3;
                    break;
                case 3:
                    v4=buscacamino(r2, c2, dp);
                    id4=dp[r2][c2].id;
                    dp[x][y].id=id4;
                    total+=v4;
                    break;
            }
        }
        i++;
    }
    if( id1==id2 || id1==id3 || id1==id4){ // comprobamos si son caminos diferentes que se uenen o son el mismo pero dividido
            total-=v1;
        }
        else if( id2==id3 || id2==id4){
            total-=v2;
        }
        else if( id3==id4){
            total-=v3;
        }
    dp[x][y].pt = total;
    return dp[x][y].pt;
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
    vector<vector<pu>> dp(a.size(), vector<pu>(a[0].size(), {0, 0}));

    int total_score = 0;
    for (int row = 0; row < a.size(); row++) { // buscamos 0 para iniciar el camino
        for (int col = 0; col < a[0].size(); col++) {
            if (a[row][col] == 0) {
                total_score += buscacamino(row, col, dp);
            }
        }
    }
    
    cout << total_score << endl;
    return 0;
}
