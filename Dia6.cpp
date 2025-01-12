#include <iostream>
#include <unordered_map>  // tabla hash para el grafo
#include <unordered_set>  // tabla hash para conjuntos
#include <string>
#include <cassert>
using namespace std;

class Queue {
private:
    unordered_map<int, unordered_set<int>> graph;  // grafo como tabla hash
    long long total;  // suma total

public:
    Queue() : total(0) {}  // inicializa la suma en 0

    void processLine(const string& line) {
        if (line.empty() || !isdigit(line[0])) {
            return;  // ignora líneas vacías o inválidas
        }

        int length = static_cast<int>(line.length());
        unordered_set<int> numbers;  // almacena números de la línea
        int currentNumber = -1;
        bool hasPipe = false;

        // extrae números de la línea
        for (int i = 0; i < length; i++) {
            if (isdigit(line[i])) {
                int num = 0;
                while (i < length && isdigit(line[i])) {
                    num = 10 * num + (line[i] - '0');
                    i++;
                }
                if (currentNumber == -1) {
                    currentNumber = num;
                } else {
                    numbers.insert(num);  // agrega a la tabla hash
                }
                if (i < length && line[i] == '|') {
                    hasPipe = true;
                }
            }
        }

        // si hay '|', es una conexión
        if (hasPipe) {
            for (int target : numbers) {
                graph[currentNumber].insert(target);
            }
        } else {  // si no hay '|', procesa los nodos
            unordered_set<int> visited;  // nodos ya visitados
            bool isValid = true;

            for (int node : numbers) {
                if (graph.count(node)) {
                    for (int connectedNode : graph[node]) {
                        if (visited.count(connectedNode)) {
                            isValid = false;
                        }
                    }
                }
                visited.insert(node);
            }

            if (isValid) {
                // encuentra el nodo central
                auto it = numbers.begin();
                advance(it, numbers.size() / 2);  // ir hasta la mitad
                total += *it;
            }
        }
    }

    long long getTotal() const {
        return total;
    }
};

int main() {
    string line;
    Queue q;

    while (getline(cin, line)) {
        q.processLine(line);
    }

    cout << q.getTotal() << "\n";

    return 0;
}
