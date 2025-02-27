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
        cout << "\n����:" << endl;
        cout << "1. �������� ������" << endl;
        cout << "2. ������� ��� ������" << endl;
        cout << "3. �������� ������" << endl;
        cout << "4. ����������� ������ �� ������ �������� �����" << endl;
        cout << "5. �������� ������ � ����" << endl;
        cout << "6. ������� ������ �� �����" << endl;
        cout << "7. �����" << endl;
        cout << "�������� �����: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (count < MAX_RECORDS) {
                cout << "\n���������� ����� ������:" << endl;
                inputTripSheet(tripSheets[count]);
                count++;
            }
            else {
                cout << "���������� ������������ ���������� �������!" << endl;
            }
            break;
        case 2:
            cout << "\n������ �������:" << endl;
            cout << left<<setw(10) << "�����" << setw(20) << "���� ��������" << setw(25) << "�������"<< setw(20) << "���������" << endl;
            cout << "--------------------------------------------------------" << endl;
            for (int i = 0; i < count; i++) {
                outputTripSheet(tripSheets[i]);
            }
            break;
        case 3: {
            int num;
            cout << "������� ����� �������� ����� ��� ���������: ";
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
                cout << "������ � ����� ������� �� �������." << endl;
            break;
        }
        case 4:
            sortTripSheets(tripSheets, count);
            cout << "������ �������������." << endl;
            break;
        case 5:
            writeTripSheetsToFile(tripSheets, count, "tripsheets.txt");
            break;
        case 6:
            readTripSheetsFromFile(tripSheets, count, "tripsheets.txt");
            break;
        case 7:
            cout << "����� �� ���������." << endl;
            break;
        default:
            cout << "�������� �����, ���������." << endl;
        }
    } while (choice != 7);

    return 0;
}
