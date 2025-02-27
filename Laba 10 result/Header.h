#pragma once
#include <string>
using namespace std;

struct TripSheet {
    int sheetNumber;    // (��� ����������)
    string validityPeriod;     // ���� ��������
    string owner;        //���������� ����� �����
    string vehicle;            //��������
};

// ��������� ������� (� VS 2022 �������� � ��� extern);
extern void inputTripSheet(TripSheet& ts);
extern void outputTripSheet(const TripSheet& ts);
extern void modifyTripSheet(TripSheet& ts);
extern void sortTripSheets(TripSheet arr[], int n);

//������ � ������
extern void writeTripSheetsToFile(const TripSheet arr[], int n, const string& filename);
extern void readTripSheetsFromFile(TripSheet arr[], int& n, const string& filename);


//������-�� �� �� ������� ����� �� ���������� ���������...