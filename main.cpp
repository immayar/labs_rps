#include <iostream>
#include <vector>
#include <string>
#include "menu.h"
#include "input.h"
#include "sort.h"
#include "file_operations.h"
#include "test_sort.h"

using namespace std;

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");

    cout << "Лабораторная работа: №2\nВариант:№6 Сортировка расческой\nСтудентка: Абдулгамидова М.А.\nГруппа : 443" << endl;

    try {
        // выбор способа ввода данных
        int choice = showMenu();
        vector<double> arr;

        switch (choice) {
        case 1:
            arr = inputFromKeyboard();
            break;
        case 2:
            arr = loadFromFile();
            break;
        case 3:
            arr = generateRandomNumbers();
            break;
        case 4:
            runAllTests();
            return 0;
        default:
            cout << "Неверный выбор! Используется ввод с клавиатуры." << endl;
            arr = inputFromKeyboard();
            break;
        }

        int n = arr.size();

        if (n == 0) {
            throw runtime_error("Массив пустой!");
        }

        // вывод исходного массива
        cout << "Исходный массив (" << n << " элементов): " << endl;
        for (double d : arr) cout << d << " ";
        cout << endl;

        // СОХРАНЯЕМ копию для демонстрации
        vector<double> originalArr = arr;

        // сортировка расческой с подсчетом операций
        int operations = combSort(arr);

        // вывод количества операций
        cout << "Количество операций (сравнения + обмены): " << operations << endl;

        // вывод отсортированного массива
        cout << "Отсортированный массив: " << endl;
        for (double d : arr) cout << d << " ";
        cout << endl;

        // сохранение результата в файл
        saveToFile(arr);

    }
    catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
        main(argc, argv);
    }
    catch (...) {
        cout << "Неизвестная ошибка!" << endl;
        main(argc, argv);
    }

    return 0;
}