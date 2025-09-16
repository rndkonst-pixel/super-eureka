#include <iostream>
#include <vector>
#include <chrono>

// Функция для печати массива
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Пузырьковая сортировка с оптимизацией
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                //swapped = true;
            }
        }
        //if (!swapped) break;
    }
}

// Сортировка вставками
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    const int size = 20;
    int arr1[size] = { 64, 34, 25, 12, 22, 11, 90, 88, 76, 50, 164, 134, 125, 112, 122, 111, 190, 188, 176, 150 };
    int arr2[size] = { 64, 34, 25, 12, 22, 11, 90, 88, 76, 50, 164, 134, 125, 112, 122, 111, 190, 188, 176, 150 };

    std::cout << "Исходный массив: ";
    printArray(arr1, size);

    // Тестируем пузырьковую сортировку
    auto start = std::chrono::high_resolution_clock::now();
    bubbleSort(arr1, size);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    std::cout << "После пузырьковой сортировки: ";
    printArray(arr1, size);
    std::cout << "Время: " << duration1.count() << " микросекунд" << std::endl;

    // Тестируем сортировку вставками
    start = std::chrono::high_resolution_clock::now();
    insertionSort(arr2, size);
    end = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    std::cout << "После сортировки вставками: ";
    printArray(arr2, size);
    std::cout << "Время: " << duration2.count() << " микросекунд" << std::endl;

    return 0;
}