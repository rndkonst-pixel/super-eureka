#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>

using namespace std;

// Функция для печати массива
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Пузырьковая сортировка с оптимизацией
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
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

bool isPalindrome(string s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        // Пропускаем небуквенные и нецифровые символы слева
        while (left < right && !isalnum(s[left])) {
            left++;
        }

        // Пропускаем небуквенные и нецифровые символы справа
        while (left < right && !isalnum(s[right])) {
            right--;
        }

        // Сравниваем символы (без учета регистра)
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }

        left++;
        right--;
    }
}

int main() {
    const int size = 20;
    int arr1[size] = { 64, 34, 25, 12, 22, 11, 90, 88, 76, 50, 164, 134, 125, 112, 122, 111, 190, 188, 176, 150 };
    int arr2[size] = { 64, 34, 25, 12, 22, 11, 90, 88, 76, 50, 164, 134, 125, 112, 122, 111, 190, 188, 176, 150 };

    cout << "Исходный массив: ";
    printArray(arr1, size);

    // Тестируем пузырьковую сортировку
    auto start = chrono::high_resolution_clock::now();
    bubbleSort(arr1, size);
    auto end = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<chrono::nanoseconds>(end - start);

    cout << "После пузырьковой сортировки: ";
    printArray(arr1, size);
    cout << "Время: " << duration1.count() << " микросекунд" << endl;

    // Тестируем сортировку вставками
    start = chrono::high_resolution_clock::now();
    insertionSort(arr2, size);
    end = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::nanoseconds>(end - start);

    cout << "После сортировки вставками: ";
    printArray(arr2, size);
    cout << "Время: " << duration2.count() << " микросекунд" << endl;

    string test1 = "A man, a plan, a canal: Panama";
    string test2 = "race a car";
    string test3 = "12321";
    string test4 = "Madam, I0i'm Adam";

    cout << boolalpha;
    start = chrono::high_resolution_clock::now();
    cout << "\"" << test1 << "\" -> " << isPalindrome(test1) << endl;
    end = chrono::high_resolution_clock::now();
    auto duration3 = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "Время isPalindrome: " << duration2.count() << " микросекунд" << endl;

    cout << "\"" << test2 << "\" -> " << isPalindrome(test2) << endl;
    cout << "\"" << test3 << "\" -> " << isPalindrome(test3) << endl;
    cout << "\"" << test4 << "\" -> " << isPalindrome(test4) << endl;
    cout << noboolalpha;

    return 0;
}