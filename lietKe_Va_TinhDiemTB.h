
void findMaxCore(LIST l) {
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

void findMinCore(LIST l) {
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

float classAverage(LIST l) {
    if (l.pHead == nullptr) {
        cout << "Danh sach rong.\n";
        return 0.0f; 
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
    return classAverage;
}