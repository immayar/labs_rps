#include <iostream>
#include "menu.h"

using namespace std;

// функция для вывода меню и выбора способа ввода
int showMenu() {
    int choice;
    cout << "\nВыберите способ ввода данных:" << endl;
    cout << "1. Ввод с клавиатуры" << endl;
    cout << "2. Загрузка из файла" << endl;
    cout << "3. Генерация случайных чисел" << endl;
    cout << "4. Запустить тесты" << endl;
    cout << "Ваш выбор: ";
    cin >> choice;
    cin.ignore();
    return choice;
}