#include "dslk.h"
#define max 10000

SV LIST_MANG[max];

void nhapMang() {
    fstream input("DSSV.csv", ios::in | ios::out);
    
    if (!input.is_open()) {
        cout << "\nMo file khong thanh cong\n";
        return;
    }

    //Đọc dòng tiêu đề
    string temp;
    getline(input, temp);

    int i = 0;
    while (!input.eof()) {
        soLuong = i + 1;
        LIST_MANG[i] = nhapTTSinhVien(input, 1);
        i++;
    }

    input.close();
}