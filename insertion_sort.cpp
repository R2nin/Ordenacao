#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

void insertionSort(int arr[], int n, long long &moves) {
    moves = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            moves++;
        }
        if (j + 1 != i) {
            arr[j + 1] = key;
            moves++;
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Digite a quantidade de numeros a serem ordenados: ";
    cin >> n;

    // Alocacao dinamica do array
    int* arr = new int[n];

    // Geracao de numeros aleatorios
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;  // Numeros aleatorios entre 0 e 999
    }

    cout << "\nArray original:" << endl;
    printArray(arr, n);

    // Medindo o tempo de execucao
    long long moves = 0;
    auto start = high_resolution_clock::now();
    
    insertionSort(arr, n, moves);
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nArray ordenado:" << endl;
    printArray(arr, n);

    cout << "\nEstatisticas da Ordenacao:" << endl;
    cout << "Metodo: Insertion Sort" << endl;
    cout << "Quantidade de dados: " << n << endl;
    cout << "Quantidade de movimentacoes: " << moves << endl;
    cout << "Tempo de execucao: " << duration.count() << " microsegundos" << endl;

    // Liberando memoria alocada
    delete[] arr;

    return 0;
}