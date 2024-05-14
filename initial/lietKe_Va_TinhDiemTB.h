//Tìm sinh viên có điểm cao nhất, thấp nhất và tính điểm trung bình



//------------------dùng cho mảng-----------------

//tìm sinh viên có điểm cao nhất
void findMaxMang(SV danhSach[], int soLuong) {
    if (soLuong == 0) {
        cout << "Danh sach sinh vien rong." << endl;
        return;
    }

    float diemCaoNhat = danhSach[0].diem;

    for (int i = 1; i < soLuong; ++i) {
        if (danhSach[i].diem > diemCaoNhat) {
            diemCaoNhat = danhSach[i].diem;
        }
    }

   for(int i=0;i< soLuong; ++i){
    if(diemCaoNhat == danhSach[i].diem){
        cout << "Sinh vien co diem cao nhat: " << endl;
        cout << "Ho va ten: " << danhSach[i].ho << " " << danhSach[i].ten << endl;
        cout << "Ma sinh vien: " << danhSach[i].maSV << endl;
        cout << "Diem: " << danhSach[i].diem << endl;
        cout << "Lop: " << danhSach[i].lop << endl;
      }
   }
}

void timSinhVienDiemThapNhat(SV danhSach[], int soLuong) {
    if (soLuong == 0) {
        cout << "Danh sach sinh vien rong." << endl;
        return;
    }

    float diemThapNhat = danhSach[0].diem;

    for (int i = 1; i < soLuong; ++i) {
        if (danhSach[i].diem < diemThapNhat) {
            diemThapNhat = danhSach[i].diem;
        }
    }

   for(int i=0;i< soLuong; ++i){
    if(diemThapNhat == danhSach[i].diem){
        cout << "Sinh vien co diem thap nhat: " << endl;
        cout << "Ho va ten: " << danhSach[i].ho << " " << danhSach[i].ten << endl;
        cout << "Ma sinh vien: " << danhSach[i].maSV << endl;
        cout << "Diem: " << danhSach[i].diem << endl;
        cout << "Lop: " << danhSach[i].lop << endl;
      }
   }
}

void tinhDiemTrungBinhLop(SV danhSach[], int soLuong) {
    if (soLuong == 0) {
        cout << "Danh sach sinh vien rong." << endl;
        return;
    }

    float tongDiem = 0;
    for (int i = 0; i < soLuong; ++i) {
        tongDiem += danhSach[i].diem;
    }

    float diemTrungBinh = tongDiem / soLuong;
    cout << "Diem trung binh cua lop la: " << diemTrungBinh << endl;
}



//------------------dùng cho danh sách liên kết đơn----------------

//tìm sinh viên có điểm cao nhất
void findMaxDon(LIST l) {
    pNODE current = l.pHead;
    float maxScore = -1;

    while (current != nullptr) {
        if (current->data.diem > maxScore) {
            maxScore = current->data.diem;
        }
        current = current->pNext;
    }

    current = l.pHead; 
    cout << "Sinh vien co diem cao nhat:\n";
    while (current != nullptr) {
        if (current->data.diem == maxScore) {
            cout << "Ho ten: " << current->data.ho << " " << current->data.ten << endl;
            cout << "Ma SV: " << current->data.maSV << endl;
            cout << "Diem: " << current->data.diem << endl;
            cout << "Lop: " << current->data.lop << endl;
            cout << "---------------------------------------\n";
        }
        current = current->pNext;
    }
}

//Tìm sinh viên có điểm thấp nhất
void findMinDon(LIST l) {
    pNODE current = l.pHead;
    float minScore = 11;

    while (current != nullptr) {
        if (current->data.diem < minScore) {
            minScore = current->data.diem;
        }
        current = current->pNext;
    }

    current = l.pHead; 
    cout << "Sinh vien co diem thap nhat:\n";
    while (current != nullptr) {
        if (current->data.diem == minScore) {
            cout << "Ho ten: " << current->data.ho << " " << current->data.ten << endl;
            cout << "Ma SV: " << current->data.maSV << endl;
            cout << "Diem: " << current->data.diem << endl;
            cout << "Lop: " << current->data.lop << endl;
            cout << "---------------------------------------\n";
        }
        current = current->pNext;
    }
}

//tính điểm trung bình
void classAverageDon(LIST l) {
    if (l.pHead == nullptr) {
        cout << "Danh sach rong.\n";
        return; 
    }

    pNODE current = l.pHead;
    float totalScore = 0.0f;
    int numStudents = 0;

    while (current != nullptr) {
        totalScore += current->data.diem;
        numStudents++;
        current = current->pNext;
    }

    float classAverage = totalScore / numStudents;
    cout << "\nĐiểm trung bình của lớp: " << fixed << setprecision(2) << classAverage << endl; 
}




//------------------dùng cho danh sách liên kết kép----------------
