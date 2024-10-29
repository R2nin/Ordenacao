#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Função para trocar dois elementos
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Função que toma o último elemento como pivô,
// coloca o pivô em sua posição correta no array ordenado,
// e coloca todos os menores à esquerda do pivô e todos os maiores à direita
int partition(int arr[], int low, int high, long long &moves) {
    int pivot = arr[high];    // pivô
    int i = (low - 1);  // Índice do menor elemento
  
    for (int j = low; j <= high - 1; j++) {
        // Se o elemento atual é menor que o pivô
        if (arr[j] <= pivot) {
            i++;    // incrementa índice do menor elemento
            swap(&arr[i], &arr[j]);
            moves++;
        }
    }
    swap(&arr[i + 1], &arr[high]);
    moves++;
    return (i + 1);
}

// Função principal que implementa o QuickSort
void quickSortHelper(int arr[], int low, int high, long long &moves) {
    if (low < high) {
        // pi é o índice de particionamento
        int pi = partition(arr, low, high, moves);
  
        // Ordena os elementos separadamente antes e depois da partição
        quickSortHelper(arr, low, pi - 1, moves);
        quickSortHelper(arr, pi + 1, high, moves);
    }
}

void quickSort(int arr[], int n, long long &moves) {
    moves = 0;
    quickSortHelper(arr, 0, n-1, moves);
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
    
    quickSort(arr, n, moves);
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nArray ordenado:" << endl;
    printArray(arr, n);

    cout << "\nEstatisticas da Ordenacao:" << endl;
    cout << "Metodo: Quick Sort" << endl;
    cout << "Quantidade de dados: " << n << endl;
    cout << "Quantidade de movimentacoes: " << moves << endl;
    cout << "Tempo de execucao: " << duration.count() << " microsegundos" << endl;

    // Liberando memoria alocada
    delete[] arr;

    return 0;
}