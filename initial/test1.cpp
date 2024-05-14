#include "struct_sinh_vien.h"
#include "khoiTao.h"
#include "xuat_danh_sach.h"
#include "lietKe_Va_TinhDiemTB.h"
#include "xoa.h"
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")

bool checkMaSv(string maSv, int luaChon) {
    //neu luu tru kieu mang thi kiem tra
    if (luaChon == 1) {
        for (int i = 0; i < soLuong; i++) {
            if (!stricmp(maSv.c_str(), LIST_MANG[i].maSV.c_str()))
                return false;
        }
    }

    //neu luu tru kieu lien ket don hoac kep thi kiem tra
    if (luaChon == 2 || luaChon == 3) {
        pNODE p = ds.pHead;
        while(p != NULL) {
            if (!stricmp(maSv.c_str(), p->data.maSV.c_str()))
                return false;
            p = p->pNext;
        }
    }

    //neu luu tru kieu lien ket vong thi kiem tra
    if (luaChon == 4) {
        pNODE p = ds.pTail;
        while (p->pNext != ds.pTail) {
            if (!stricmp(maSv.c_str(), p->data.maSV.c_str()))
                return false;
            p = p->pNext;
        }
    }
    
    return true;
}
  

void menu() 
{
    string lc1;
    cout << "\n1. Lưu trữ bằng mảng";
    cout << "\n2. Lưu trữ bằng danh sách liên kết đơn";
    cout << "\n3. Lưu trữ bằng danh sách liên kết kép";
    cout << "\n4. Lưu trữ bằng danh sách liên kết vòng";
    cout << "\nVui lòng chọn cách thức lưu trữ(nhập số): ";
    getline(cin, lc1);

    regex pattern("[1-4]");
    while(!regex_match(lc1, pattern)) 
    {
        cout << "Chỉ nhập số 1->4 để lựa chọn: ";
        getline(cin, lc1);
    }

    if (lc1 == "1") 
        nhapMang();
    if (lc1 == "2") 
        nhapDon(ds);
    if (lc1 == "3")
        nhapKep(ds);
    if (lc1 == "4") 
        nhapVong(ds);

    string lc2;
    while(true) 
    {
        cout << "\n1. Xuất danh sách sinh viên";
        cout << "\n2. Tìm kiếm sinh viên";
        cout << "\n3. Thêm mới sinh viên";
        cout << "\n4. Xóa sinh viên";
        cout << "\n5. Liệt kê các sinh viên có điểm thấp nhất";
        cout << "\n6. Liệt kê các sinh viên có điểm cao nhất";
        cout << "\n7. Tính điểm trung bình của lớp";
        cout << "\n8. Sắp xếp danh sách sinh viên";
        cout << "\n0. Thoát";

        cout << "\nNhập lựa chọn của bạn(chỉ nhập số): ";
        getline(cin ,lc2);

        regex pattern("[0-8]");
        while(!regex_match(lc2, pattern)) 
        {
            cout << "Chỉ nhập số 0->8 để lựa chọn: ";
            getline(cin, lc2);
        }

        if (lc2 == "1") 
        {
            inTieuDe();

            if (lc1 == "1")
                xuatSinhVienMang(LIST_MANG, soLuong);
            if (lc1 == "2")
                xuatDSLKDon(ds);
            if (lc1 == "3")
                xuatDanhSachLKKep(ds);
            if (lc1 == "4") 
                xuatDanhSachLKKep(ds);
        }

        else if (lc2 == "4")
        {
            cout << "\nNhập mã sinh viên cần xóa: ";
            string msv;
            getline(cin, msv);

            if (lc1 == "1")
                xoaMang(soLuong, msv);
            if (lc1 == "2")
                XoaDon(ds, msv);
            if (lc1 == "3")
            {
                pNODE p = findNodeByMaSV(ds, msv);
                xoaKep(ds, p);
            }
            if (lc1 == "4") 
                xoaVong(ds, msv);
        }

        else if (lc2 == "5")
        {
            if (lc1 == "2")
                findMaxDon(ds);
            
        }

        else if (lc2 == "6") 
        {
            if (lc1 == "2")
                findMinDon(ds);
        }

        else if (lc2 == "7") 
        {
            if (lc1 == "2") 
                classAverageDon(ds);
        }


        else break;
    }
}



int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    SetConsoleOutputCP(CP_UTF8);

    menu();
    
}