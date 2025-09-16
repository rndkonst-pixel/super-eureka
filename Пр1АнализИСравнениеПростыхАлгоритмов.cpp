#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <set>

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
    return true;
}

bool isPalindrome2(string s) {
    string cleaned;

    // Создаем строку только из букв и цифр
    for (char c : s) {
        if (isalnum(c)) {
            cleaned += tolower(c);
        }
    }

    // Проверяем, является ли очищенная строка палиндромом
    int left = 0;
    int right = cleaned.length() - 1;

    while (left < right) {
        if (cleaned[left] != cleaned[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int countUniqueSorted(vector<int> arr) {
    if (arr.empty()) return 0;

    sort(arr.begin(), arr.end());
    int count = 1;

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] != arr[i - 1]) {
            count++;
        }
    }

    return count;
}

int countUnique(const vector<int>& arr) {
    set<int> uniqueSet(arr.begin(), arr.end());
    return uniqueSet.size();
}


int countUnique2(const vector<int>& arr) {
    unordered_set<int> uniqueSet(arr.begin(), arr.end());
    return uniqueSet.size();
}

int main() {

    // Устанавливаем локаль
    setlocale(LC_ALL, "Russian");
    // или для UTF-8:
    // setlocale(LC_ALL, "ru_RU.UTF-8");

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
    cout << "Время: " << duration1.count() << " наносекунд" << endl;

    // Тестируем сортировку вставками
    start = chrono::high_resolution_clock::now();
    insertionSort(arr2, size);
    end = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::nanoseconds>(end - start);

    cout << "После сортировки вставками: ";
    printArray(arr2, size);
    cout << "Время: " << duration2.count() << " наносекунд" << endl;

    string test1 = "A man, a plan, a canal: Panama";
    string test2 = "race a car";
    string test3 = "12321";
    string test4 = "Madam, I0i'm Adam";

    cout << boolalpha;
    auto start3 = chrono::high_resolution_clock::now();
    cout << "\"" << test1 << "\" -> " << isPalindrome(test1) << endl;
    auto end3 = chrono::high_resolution_clock::now();
    auto duration3 = chrono::duration_cast<chrono::nanoseconds>(end3 - start3);
    cout << "Время isPalindrome: " << duration3.count() << " наносекунд" << endl;

    cout << "\"" << test2 << "\" -> " << isPalindrome(test2) << endl;
    cout << "\"" << test3 << "\" -> " << isPalindrome(test3) << endl;
    cout << "\"" << test4 << "\" -> " << isPalindrome(test4) << endl;
    cout << noboolalpha;

    cout << boolalpha;
    auto start4 = chrono::high_resolution_clock::now();
    cout << "\"" << test1 << "\" -> " << isPalindrome2(test1) << endl;
    auto end4 = chrono::high_resolution_clock::now();
    auto duration4 = chrono::duration_cast<chrono::nanoseconds>(end4 - start4);
    cout << "Время isPalindrome2: " << duration4.count() << " наносекунд" << endl;

    cout << "\"" << test2 << "\" -> " << isPalindrome2(test2) << endl;
    cout << "\"" << test3 << "\" -> " << isPalindrome2(test3) << endl;
    cout << "\"" << test4 << "\" -> " << isPalindrome2(test4) << endl;
    cout << noboolalpha;

    vector<int> arr = { 1, 2, 3, 2, 4, 1, 5, 3, 6 };

    auto start5 = chrono::high_resolution_clock::now();
    int cntu = countUniqueSorted(arr);
    auto end5 = chrono::high_resolution_clock::now();
    auto duration5 = chrono::duration_cast<chrono::nanoseconds>(end5 - start5);
    cout << "Количество уникальных элементов: " << cntu << endl;
    cout << "Время countUniqueSorted: " << duration5.count() << " наносекунд" << endl;


    auto start6 = chrono::high_resolution_clock::now();
    int cntu2 = countUnique(arr);
    auto end6 = chrono::high_resolution_clock::now();
    auto duration6 = chrono::duration_cast<chrono::nanoseconds>(end6 - start6);
    cout << "Количество уникальных элементов: " << cntu2 << endl;
    cout << "Время countUnique: " << duration6.count() << " наносекунд" << endl;

    auto start7 = chrono::high_resolution_clock::now();
    int cntu3 = countUnique2(arr);
    auto end7 = chrono::high_resolution_clock::now();
    auto duration7 = chrono::duration_cast<chrono::nanoseconds>(end7 - start7);
    cout << "Количество уникальных элементов: " << cntu3 << endl;
    cout << "Время countUnique: " << duration7.count() << " наносекунд" << endl;

    return 0;
}