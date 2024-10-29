#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

void countingSort(int arr[], int n, long long &moves) {
    moves = 0;
    
    // Encontrar o maior elemento do array
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    // Criar array auxiliar para contar as ocorrências
    int* count = new int[max + 1]();
    int* output = new int[n];

    // Contar ocorrências
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Modificar count[i] para conter a posição real
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Construir o array de saída
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
        moves++;
    }

    // Copiar o array ordenado de volta para arr
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
        moves++;
    }

    // Liberar memória auxiliar
    delete[] count;
    delete[] output;
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
    
    countingSort(arr, n, moves);
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nArray ordenado:" << endl;
    printArray(arr, n);

    cout << "\nEstatisticas da Ordenacao:" << endl;
    cout << "Metodo: Counting Sort" << endl;
    cout << "Quantidade de dados: " << n << endl;
    cout << "Quantidade de movimentacoes: " << moves << endl;
    cout << "Tempo de execucao: " << duration.count() << " microsegundos" << endl;

    // Liberando memoria alocada
    delete[] arr;

    return 0;
}