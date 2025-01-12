#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cassert>
using namespace std;

// clase que representa la cola y procesa el grafo
class Cola {
private:
    map<int, vector<int>> edges;  // mapa que guarda las aristas
    long long answer;  // variable que guarda el resultado final

public:
    // constructor de la clase, inicializa answer a 0
    Cola() : answer(0) {}

    // funcion que procesa una línea
    void procesarLinea(const string& s) {
        if (s.empty() || !isdigit(s[0])) {
            return;  // si la línea está vacía o no comienza con un número, la ignoramos
        }

        int len = static_cast<int>(s.length());  // obtener la longitud de la línea
        vector<int> v;  // vector donde se guardarán los números extraídos de la línea
        bool was_pipe = false;  // indica si la línea contiene el símbolo '|'

        // recorrer cada caracter de la línea
        for (int i = 0; i < len; i++) {
            if (isdigit(s[i])) {  // si es un número
                int x = 0;
                while (i < len && isdigit(s[i])) {  // formar el número completo
                    x = 10 * x + (s[i] - '0');
                    i++;
                }
                v.push_back(x);  // almacenar el número en el vector
                if (i < len && s[i] == '|') {
                    was_pipe = true;  // si encontramos '|', marcar como encontrado
                }
                // asegurarnos de que el siguiente carácter es válido
                assert(i == len || s[i] == ',' || s[i] == '|' || s[i] == '\n' || s[i] == '\0');
            }
        }

        // si la línea contiene '|', agregar arista entre dos nodos
        if (was_pipe) {
            edges[v[0]].push_back(v[1]);  // agregar la conexión entre el nodo v[0] y v[1]
        } else {
            set<int> earlier;  // conjunto de nodos procesados
            bool ok = true;    // indica si la línea es válida (sin conflictos)

            // revisar si algún nodo de la línea ya tiene una conexión previa que cause conflicto
            for (int i = 0; i < static_cast<int>(v.size()); i++) {
                int x = v[i];  // nodo actual
                for (int y : edges[x]) {  // revisar conexiones de cada nodo
                    if (earlier.count(y)) {
                        ok = false;  // si ya se procesó el nodo, hay conflicto
                    }
                }
                earlier.insert(x);  // marcar el nodo como procesado
            }

            // si no hubo conflictos, agregar el valor del nodo central a la respuesta
            if (ok) {
                answer += v[v.size() / 2];
            }
        }
    }

    // obtener el resultado final
    long long obtenerRespuesta() const {
        return answer;
    }
};


int main() {
    string s;  // cadena para leer cada línea
    Cola cola;  // crear una instancia de la clase Cola

    // leer las líneas de entrada
    while (getline(cin, s)) {
        cola.procesarLinea(s);  // procesar la línea
    }

    // imprimir la respuesta final
    cout << cola.obtenerRespuesta() << "\n";

    return 0;  // fin del programa
}
