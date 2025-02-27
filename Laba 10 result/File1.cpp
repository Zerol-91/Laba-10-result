#include "Header.h" 
#include <iostream>
#include <fstream>
#include <limits> // для очистки буфера.
#include<iomanip> /*для setw() - это вместо того, как на С printf("%d %10s %18d %16d %16d", 
data[a].nomer_zakaza, data[a].nazvanie_siriy, data[a].kol_vo, 
data[a].stoimost, data[a].itog_stoimost);
printf("\n")
+ можно ставить \t, но это не оч.
*/
#include<locale.h> 
using namespace std;




void inputTripSheet(TripSheet& ts) {
    cout << "Введите номер путевого листа: ";
    cin >> ts.sheetNumber;
   /* while (!(cin >> ts.sheetNumber) || ts.sheetNumber <= 0) {
        cout << "Номер должен быть положительным целым числом. Повторите ввод: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }*/
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очищаем буфер


    cout << "Введите срок действия путевого листа: ";
    getline(cin, ts.validityPeriod);
    // ПРОВЕРКА, ЧТОБЫ БЫЛО МИНИМУМ 5 ЦИФР (2)
   while (ts.validityPeriod.empty()) {
       cout << "Ошибка! Срок действия не может быть пустым. повторите ввод: ";
        getline(cin, ts.validityPeriod);
    }

    cout << "Введите ФИО лица, оформившего путевой лист: ";
    getline(cin, ts.owner);
    while (ts.owner.empty()) {
        cout << "Ошибка! ФИО не может быть пустым. Повторите ввод: ";
        getline(cin, ts.owner);
    }

    cout << "Введите транспортное средство: ";
    getline(cin, ts.vehicle);
    while (ts.vehicle.empty()) {
        cout << "Ошибка! Транспортное средство не может быть пустым. Повторите ввод: ";
        getline(cin, ts.vehicle);
    }
}

// Функция вывода одного путевого листа (одна запись таблицы)
void outputTripSheet(const TripSheet& ts) {
    cout << left << setw(10) << ts.sheetNumber
         << setw(20) << ts.validityPeriod
        << setw(25) << ts.owner
        << setw(20) << ts.vehicle << endl;
}

// Функция изменения данных одного путевого листа
void modifyTripSheet(TripSheet& ts) {
    int option;
    cout << "Что хотите изменить?" << endl;
    cout << "1. Срок действия путевого листа" << endl;
    cout << "2. ФИО лица" << endl;
    cout << "3. Транспортное средство" << endl;
    cout << "Ваш выбор: ";
    cin >> option;
  
    switch (option) {
    case 1:
        cout << "Введите новый срок действия: ";
        getline(cin, ts.validityPeriod);
        while (ts.validityPeriod.empty() || ts.validityPeriod.length() < 5) {
            cout << "Ошибка! Срок действия не может быть пустым и должен содержать минимум 5 символов. Повторите ввод: ";
            getline(cin, ts.validityPeriod);
        }
        break;
    case 2:
        cout << "Введите новое ФИО лица: ";
        getline(cin, ts.owner);
        while (ts.owner.empty()) {
            cout << "Ошибка! ФИО не может быть пустым. Повторите ввод: ";
            getline(cin, ts.owner);
        }
        break;
    case 3:
        cout << "Введите новое транспортное средство: ";
        getline(cin, ts.vehicle);
        while (ts.vehicle.empty()) {
            cout << "Ошибка! Транспортное средство не может быть пустым. Повторите ввод: ";
            getline(cin, ts.vehicle);
        }
        break;
    default:
        cout << "Неверный выбор." << endl;
    }
}

// Функция сортировки массива путевых листов по номеру (по возрастанию) (метод пузырьковой сортировки)
void sortTripSheets(TripSheet arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].sheetNumber > arr[j + 1].sheetNumber) {
                TripSheet temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Функция записи массива путевых листов в текстовый файл
void writeTripSheetsToFile(const TripSheet arr[], int n, const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cout << "Ошибка открытия файла для записи!" << endl;
        return;
    }
    // Запись заголовка
    outFile << left << setw(10) << "Номер"
        << left << setw(20) << "Срок действия"
        << left << setw(25) << "Оформил"
        << left << setw(20) << "Транспорт" << endl;
    outFile << "--------------------------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        outFile << left << setw(10) << arr[i].sheetNumber
            << left << setw(20) << arr[i].validityPeriod
            << left << setw(25) << arr[i].owner
            << left << setw(20) << arr[i].vehicle << endl;
    }
    outFile.close();
    cout << "Данные записаны в файл " << filename << endl;
}

// Функция чтения путевых листов из текстового файла (упрощённый вариант)
void readTripSheetsFromFile(TripSheet arr[], int& n, const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Ошибка открытия файла для чтения!" << endl;
        return;
    }
    // Пропускаем заголовочные строки
    string dummy;
    getline(inFile, dummy);
    getline(inFile, dummy);

    n = 0;
    while (!inFile.eof() && n < 100) { // максимум 100 записей
        TripSheet ts;
        if (!(inFile >> ts.sheetNumber))
            break;
        inFile >> ts.validityPeriod >> ts.owner >> ts.vehicle;
        arr[n++] = ts;
    }
    inFile.close();
    cout << "Прочитано " << n << " записей из файла " << filename << endl;
}
