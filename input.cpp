#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include "input.h"

using namespace std;

// функция для ввода массива с клавиатуры
vector<double> inputFromKeyboard() {
    cout << "Введите числа массива через пробел: ";
    string input;
    getline(cin, input);

    vector<double> arr;
    stringstream ss(input);
    double number;

    while (ss >> number) {
        arr.push_back(number);
    }

    return arr;
}

// функция для загрузки массива из файла
vector<double> loadFromFile() {
    string filename;
    cout << "Введите имя файла: ";
    getline(cin, filename);

    ifstream file(filename);
    vector<double> arr;
    double number;

    if (file.is_open()) {
        while (file >> number) {
            arr.push_back(number);
        }
        file.close();
        cout << "Загружено " << arr.size() << " чисел из файла." << endl;
    }
    else {
        throw runtime_error("Не удалось открыть файл!");
    }

    return arr;
}

// функция для генерации случайных чисел
vector<double> generateRandomNumbers() {
    int n;
    cout << "Введите количество чисел в массиве: ";
    cin >> n;

    srand(time(0));
    vector<double> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i] = rand() / (RAND_MAX + 1.0);
        arr[i] *= 100;
        while (arr[i] / 10 < 1) {
            arr[i] = rand() / (RAND_MAX + 1.0);
            arr[i] *= 100;
        }
    }

    return arr;
}