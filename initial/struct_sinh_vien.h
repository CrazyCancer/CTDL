#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <iomanip>
#include <regex>
using namespace std;

int soLuong = 0; //so luong sinh vien

typedef struct sinhVien
{
    int stt;
    string maSV;
    string ho;
    string ten;
    string lop;
    float diem;
} SINHVIEN;

typedef SINHVIEN SV;

bool checkMaSv(string, int);//kiểm tra mã sinh viên được nhập vào có bị trùng không

SV nhapTTSinhVien(fstream &input, int luaChon) {
    soLuong++;//tang so luong sinh vien
    SV sv;
    string temp;
    
    input >> sv.stt;
    input.ignore();
    getline(input, temp, ',');
    while (!checkMaSv(temp, luaChon)) {
        cout << "\nMa sinh vien " << temp << " da ton tai\nVui long nhap lai ma sinh vien: ";
        getline(cin, temp);
    }
    sv.maSV = temp;
    getline(input, sv.ho, ',');
    getline(input, sv.ten, ',');
    getline(input, sv.lop, ',');
    input >> sv.diem;
    
    return sv;
}