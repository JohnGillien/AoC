#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

class columna {
public:
    int orden;
    int data;
};

void merge(columna arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;    

    
    columna* leftArr = new columna[n1];
    columna* rightArr = new columna[n2];

    
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[mid + 1 + i];

   
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i].data <= rightArr[j].data) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

   
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

   
    delete[] leftArr;
    delete[] rightArr;
}

// Función recursiva para ordenar el array
void mergeSort(columna arr[], int left, int right) {
    if (left < right) {
       
        int mid = left + (right - left) / 2;

        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        
        merge(arr, left, mid, right);
    }
}

int main() {
    const int MAX_ROW = 1000;
    columna c1[MAX_ROW];
    columna c2[MAX_ROW];   
    string filename = "input";
    ifstream file(filename);     

    if (!file) { 
        cerr << "Error: No se pudo abrir el archivo " << filename << endl;
        return 1;
    }

    string line;
    int col1, col2;
    int row = 0; 
    while (getline(file, line) && row < MAX_ROW) {
        istringstream iss(line);                   
        if (iss >> col1 >> col2) {                  
            c1[row].data = col1;  
            c1[row].orden = row;
            c2[row].data = col2;  
            c2[row].orden = row;    
            row++;                                 
        }
    }
    file.close(); 

    
    ofstream archivo("mi_archivo.txt");
    if (archivo.is_open()) {
        for (int i = 0; i < row; i++) {
            archivo << c1[i].data << "->" << c1[i].orden << " " << c2[i].data << "->" << c2[i].orden << endl;
        }
        archivo.close();
    }  

    // Ordenar y almacenar
    mergeSort(c1, 0, row - 1);
    mergeSort(c2, 0, row - 1);

    ofstream archivo1("Resultados.txt");
    int sol = 0;
    if (archivo1.is_open()) {
        for (int i = 0; i < row; i++) {
            archivo1 << c1[i].data << "->" << c1[i].orden << " " << c2[i].data << "->" << c2[i].orden << endl;
            int aux = abs(c1[i].data- c2[i].data);
            cout<<aux<<endl;
            sol += aux;
        }
        archivo1.close();
    }  

    cout << "Suma de diferencias: " << sol << endl;
    return 0;
}