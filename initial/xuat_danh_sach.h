
// Hàm in tiêu đề
void inTieuDe()
{
    cout << left << setw(30) << "| MSSV" << setw(30) << "| Ho va Ten" << setw(20) << "| Lop" << setw(10) << "| Diem" << endl;
    cout << setfill('-') << setw(90) << "" << setfill(' ') << endl;
}

void xuat(SV sv)
{
    cout << left << setw(32) << sv.maSV << setw(30) << sv.ho + " " + sv.ten << setw(20) << sv.lop << setw(10) << sv.diem << endl;
}

void xuatSinhVienMang(SV LIST_MANG[], int &soLuongSinhVienMang)
{
    for (int i = 0; i < soLuongSinhVienMang; i++)
    {
        xuat(LIST_MANG[i]);
        cout << endl;
    }
}

void xuatDSLKDon(LIST listDon)
{
    int index = 0;
    for (pNODE p = listDon.pHead; p != NULL; p = p->pNext)
    {
        xuat(p->data);
    }
}

void xuatDSLKVong(LIST listVong)
{
    if (listVong.pTail != nullptr)
    {
        pNODE p = listVong.pTail->pNext;
        do
        {
            xuat(p->data);
            p = p->pNext;
        } while (p != listVong.pTail->pNext);
    }
}

void xuatDanhSachLKKep(LIST listKep)
{
    for (pNODE p = listKep.pHead; p != NULL; p = p->pNext)
    {
        xuat(p->data);
    }
}