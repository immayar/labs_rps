#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "file_operations.h"

using namespace std;

// сохранение результата в файл
void saveToFile(const vector<double>& arr) {
    char save;
    cout << "Сохранить результат в файл? (y/n): ";
    cin >> save;

    if (save == 'y' || save == 'Y') {
        string filename;
        cout << "Введите имя файла для сохранения: ";
        cin >> filename;

        ofstream outFile(filename);
        if (outFile.is_open()) {
            for (double d : arr) {
                outFile << d << " ";
            }
            outFile.close();
            cout << "Результат сохранен в файл: " << filename << endl;
        }
        else {
            cout << "Не удалось сохранить файл!" << endl;
        }
    }
}