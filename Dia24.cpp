#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

// Nodo para el árbol binario
struct TreeNode {
    std::string id;
    std::string op1;
    std::string op2;
    std::string operation; // Operación asociada (AND, OR, XOR)
    TreeNode* left; // Hijo izquierdo
    TreeNode* right; // Hijo derecho
    int value; // Valor del nodo

    TreeNode(const std::string& id, const std::string& op1, const std::string& op2, const std::string& operation) {
        this->id = id;
        this->op1 = op1;
        this->op2 = op2;
        this->operation = operation;
        this->left = nullptr;
        this->right = nullptr;
        this->value = -1; // Valor inicial inválido
    }
};

TreeNode* raiz = nullptr;
std::string zs = "";

// Función para evaluar una operación lógica
int evaluarOperacion(const std::string& operation, int leftValue, int rightValue) {
    if (operation == "AND") {
        return leftValue && rightValue;
    } else if (operation == "OR") {
        return leftValue || rightValue;
    } else if (operation == "XOR") {
        return leftValue ^ rightValue;
    }
    return -1; // Default case (no debería ocurrir)
}

void insertar(TreeNode* tree, TreeNode** root) {
    if(*root == nullptr) {
        *root = tree;
    } else {
        if ((*root)->id > tree->id) {
            insertar(tree, &(*root)->left);
        } else {
            insertar(tree, &(*root)->right);
        }
    }
}

void procesaLinea(std::string linea) {
    TreeNode* tree;
    if(linea.find("->") != std::string::npos) {
        std::stringstream ss(linea);
        std::string op1, op2, operation, arrow, id;
        ss >> op1 >> operation >> op2 >> arrow >> id;
        tree = new TreeNode(id, op1, op2, operation);
        insertar(tree, &raiz);
    } else {
        std::string id = linea.substr(0,2);
        std::string valor = linea.substr(5);
        tree = new TreeNode(id, "", "", "");
        tree->value = stoi(valor);
        insertar(tree, &raiz);
    }
}

TreeNode* buscar(std::string id, TreeNode* root) {
    if(root == nullptr) {
        return nullptr;
    }
    if(root->id == id) {
        return root;
    } else if(root->id > id) {
            return buscar(id, root->left);
    } else {
        return buscar(id, root->right);
    }
}

void calcularValor(TreeNode* root) {
    if(root->value == -1) {
        TreeNode* x = buscar(root->op1, raiz);
        TreeNode* y = buscar(root->op2, raiz);
        if (x != nullptr && y != nullptr) {
            calcularValor(x);
            calcularValor(y);
            root->value = evaluarOperacion(root->operation, x->value, y->value);
        }
    }
}

void recorreyCalcula(TreeNode* root) {
    if(root != nullptr) {
        recorreyCalcula(root->left);
        recorreyCalcula(root->right);
        calcularValor(root);
    }
}

void buscarZ(TreeNode* root) {
    if(root != nullptr) {
        buscarZ(root->right);
        if (root->id.front() == 'z' && root->value != -1) { // Asegúrate de que el valor sea válido
            zs += std::to_string(root->value);
        }
        buscarZ(root->left);
    }
}

// Función para convertir un número binario (representado como string) a decimal
int binaryToDecimal(const std::string& binary) {
    int decimal = 0;
    for (char bit : binary) {
        decimal = (decimal << 1) + (bit - '0');
    }
    return decimal;
}

int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Error al abrir el archivo input.txt" << std::endl;
        return 1;
    }

    std::string line;

    // Leer el archivo línea por línea
    while (std::getline(inputFile, line)) {
        if (!line.empty()) {
            procesaLinea(line);
        }
    }

    inputFile.close();

    recorreyCalcula(raiz);
    buscarZ(raiz);

    // Imprimir el número binario
    std::cout << "Número binario: " << zs << std::endl;

    // Convertir a decimal y mostrar el resultado
    int decimalResult = binaryToDecimal(zs);
    std::cout << "Número decimal: " << decimalResult << std::endl;

    return 0;
}
