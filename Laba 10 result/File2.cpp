#include <iostream>
#include <iomanip>
#include "Header.h"
using namespace std;

int main() {

    setlocale(LC_ALL, "rus");

    const int MAX_RECORDS = 100;
    TripSheet tripSheets[MAX_RECORDS];
    int count = 0;
    int choice;

    do {
        cout << "\nМеню:" << endl;
        cout << "1. Добавить запись" << endl;
        cout << "2. Вывести все записи" << endl;
        cout << "3. Изменить запись" << endl;
        cout << "4. Сортировать записи по номеру путевого листа" << endl;
        cout << "5. Записать данные в файл" << endl;
        cout << "6. Считать данные из файла" << endl;
        cout << "7. Выход" << endl;
        cout << "Выберите опцию: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (count < MAX_RECORDS) {
                cout << "\nДобавление новой записи:" << endl;
                inputTripSheet(tripSheets[count]);
                count++;
            }
            else {
                cout << "Достигнуто максимальное количество записей!" << endl;
            }
            break;
        case 2:
            cout << "\nСписок записей:" << endl;
            cout << left<<setw(10) << "Номер" << setw(20) << "Срок действия" << setw(25) << "Оформил"<< setw(20) << "Транспорт" << endl;
            cout << "--------------------------------------------------------" << endl;
            for (int i = 0; i < count; i++) {
                outputTripSheet(tripSheets[i]);
            }
            break;
        case 3: {
            int num;
            cout << "Введите номер путевого листа для изменения: ";
            cin >> num;
            
            bool found = false;
            for (int i = 0; i < count; i++) {
                if (tripSheets[i].sheetNumber == num) {
                    modifyTripSheet(tripSheets[i]);
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Запись с таким номером не найдена." << endl;
            break;
        }
        case 4:
            sortTripSheets(tripSheets, count);
            cout << "Записи отсортированы." << endl;
            break;
        case 5:
            writeTripSheetsToFile(tripSheets, count, "tripsheets.txt");
            break;
        case 6:
            readTripSheetsFromFile(tripSheets, count, "tripsheets.txt");
            break;
        case 7:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Неверный выбор, повторите." << endl;
        }
    } while (choice != 7);

    return 0;
}
