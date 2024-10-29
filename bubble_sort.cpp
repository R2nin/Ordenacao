#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

void bubbleSort(int arr[], int n, long long &moves) {
    moves = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                moves++;
            }
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
    
    bubbleSort(arr, n, moves);
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nArray ordenado:" << endl;
    printArray(arr, n);

    cout << "\nEstatisticas da Ordenacao:" << endl;
    cout << "Metodo: Bubble Sort" << endl;
    cout << "Quantidade de dados: " << n << endl;
    cout << "Quantidade de movimentacoes: " << moves << endl;
    cout << "Tempo de execucao: " << duration.count() << " microsegundos" << endl;

    // Liberando memoria alocada
    delete[] arr;

    return 0;
}
