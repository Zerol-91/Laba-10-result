#pragma once
#include <string>
using namespace std;

struct TripSheet {
    int sheetNumber;    // (для сортировки)
    string validityPeriod;     // Срок действия
    string owner;        //Обладатель этого листа
    string vehicle;            //Траспорт
};

// Прототипы функций (в VS 2022 работает и без extern);
extern void inputTripSheet(TripSheet& ts);
extern void outputTripSheet(const TripSheet& ts);
extern void modifyTripSheet(TripSheet& ts);
extern void sortTripSheets(TripSheet arr[], int n);

//Работа с файлом
extern void writeTripSheetsToFile(const TripSheet arr[], int n, const string& filename);
extern void readTripSheetsFromFile(TripSheet arr[], int& n, const string& filename);


//Почему-то на на русском слова не возвращает нормально...