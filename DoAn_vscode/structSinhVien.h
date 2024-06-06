#pragma once

#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
#include <stdexcept> // thư viện dùng cho template
#include <algorithm>
#include <time.h>
#include <chrono>
#include <windows.h>
#include <fstream>
#include <vector>
#include <regex>
#include <sstream>

using namespace std;

int soLuong = 0; //so luong sinh vien
int kieuDL;

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