#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>
#include <functional>

using namespace std;

class GridTraversal {
private:
    // hash personalizado para pares
    struct pair_hash {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const {
            return hash<T1>()(p.first) ^ (hash<T2>()(p.second) << 1);  // calcula el hash para el par
        }
    };

    // direcciones posibles (arriba, derecha, abajo, izquierda)
    vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int H, W;  // altura y ancho de la cuadrícula
    vector<string> a;  // cuadrícula del problema
    unordered_set<pair<int, int>, pair_hash> vis;  // conjunto para posiciones visitadas

public:
    // constructor que recibe la altura y la cuadrícula
    GridTraversal(int height, const vector<string>& matrix) : H(height), a(matrix) {
        W = a[0].length();  // asigna el ancho tomando el tamaño de la primera fila
    }

    // método que realiza el recorrido
    int traverse() {
        pair<int, int> me{-1, -1};  // posición inicial
        int dir = 0;  // dirección de movimiento (empezamos hacia arriba)

        // encontrar la posición inicial
        for (int row = 0; row < H; row++) {
            for (int col = 0; col < W; col++) {
                if (a[row][col] == '^') {  // encontrar el inicio
                    me = {row, col};  // asignar la posición
                    a[row][col] = '.';  // marcar como visitado
                    break;
                }
            }
        }

        // realizar el recorrido mientras sea válido
        while (true) {
            vis.insert(me);  // marcar la posición como visitada
            int r2 = me.first + dirs[dir].first;  // nueva fila según la dirección
            int c2 = me.second + dirs[dir].second;  // nueva columna según la dirección

            if (!(0 <= r2 && r2 < H && 0 <= c2 && c2 < W)) {  // si salimos de la cuadrícula
                break;  // terminar
            }

            if (a[r2][c2] == '.') {  // si el nuevo espacio está vacío
                me = {r2, c2};  // mover a la nueva posición
            } else {  // si encontramos un obstáculo
                dir = (dir + 1) % 4;  // cambiar de dirección
            }
        }

        return vis.size();  // devolver el número de posiciones únicas visitadas
    }
};

int main() {
    int H = 130;  // altura de la cuadrícula
    vector<string> matrix(H);  // crear un vector de strings
    for (int i = 0; i < H; i++) {
        cin >> matrix[i];  // leer cada fila de la cuadrícula
    }

    GridTraversal solver(H, matrix);  // crear un objeto para resolver el problema
    cout << solver.traverse() << "\n";  // llamar al método para recorrer y mostrar resultado
    return 0;  // fin del programa
}
