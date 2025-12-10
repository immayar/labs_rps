#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include "sort.h"
#include "test_sort.h"

using namespace std;

// Проверка, отсортирован ли массив
bool isSorted(const vector<double>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

// Вывод результата теста
void printTestResult(const string& testName, bool passed) {
    cout << testName << ": " << (passed ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН") << endl;
}

// Тест пустого массива
void testEmptyArray() {
    vector<double> arr;
    combSort(arr);
    bool passed = arr.empty() && isSorted(arr);
    printTestResult("Тест пустого массива", passed);
    assert(passed);
}

// Тест массива с одним элементом
void testSingleElement() {
    vector<double> arr = { 5.0 };
    combSort(arr);
    bool passed = (arr.size() == 1) && (arr[0] == 5.0) && isSorted(arr);
    printTestResult("Тест одного элемента", passed);
    assert(passed);
}

// Тест уже отсортированного массива
void testSortedArray() {
    vector<double> arr = { 1.0, 2.0, 3.0, 4.0, 5.0 };
    vector<double> original = arr;
    combSort(arr);
    bool passed = isSorted(arr) && (arr == original);
    printTestResult("Тест отсортированного массива", passed);
    assert(passed);
}

// Тест массива, отсортированного в обратном порядке
void testReverseSortedArray() {
    vector<double> arr = { 5.0, 4.0, 3.0, 2.0, 1.0 };
    combSort(arr);
    bool passed = isSorted(arr);
    printTestResult("Тест обратно отсортированного массива", passed);
    assert(passed);
}

// Тест случайного массива
void testRandomArray() {
    vector<double> arr = { 3.5, 1.2, 4.8, 2.1, 5.9, 0.5 };
    combSort(arr);
    bool passed = isSorted(arr);
    printTestResult("Тест случайного массива", passed);
    assert(passed);
}

// Тест массива с повторяющимися элементами
void testDuplicateElements() {
    vector<double> arr = { 3.0, 1.0, 2.0, 1.0, 3.0, 2.0, 1.0 };
    combSort(arr);
    bool passed = isSorted(arr);
    printTestResult("Тест с повторяющимися элементами", passed);
    assert(passed);
}

// Тест с отрицательными числами
void testNegativeNumbers() {
    vector<double> arr = { -3.5, -1.2, -4.8, -2.1, -5.9 };
    combSort(arr);
    bool passed = isSorted(arr);
    printTestResult("Тест с отрицательными числами", passed);
    assert(passed);
}

// Тест со смешанными числами
void testMixedNumbers() {
    vector<double> arr = { -3.5, 1.2, -4.8, 0.0, 5.9, -2.1 };
    combSort(arr);
    bool passed = isSorted(arr);
    printTestResult("Тест со смешанными числами", passed);
    assert(passed);
}

// Запуск всех тестов
void runAllTests() {
    cout << "=== ЗАПУСК UNIT-ТЕСТОВ ДЛЯ СОРТИРОВКИ РАСЧЕСКОЙ ===" << endl;
    cout << endl;

    testEmptyArray();
    testSingleElement();
    testSortedArray();
    testReverseSortedArray();
    testRandomArray();
    testDuplicateElements();
    testNegativeNumbers();
    testMixedNumbers();

    cout << endl;
    cout << "=== ВСЕ ТЕСТЫ ПРОЙДЕНЫ УСПЕШНО ===" << endl;
}