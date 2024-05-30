#include "structSinhVien.h"
#include "mang.h"
#include "danh_sach_lien_ket_don.h"
#include "danh_sach_lien_ket_kep.h"
#include "danh_sach_lien_ket_vong.h"
#include "checkMaSv.h"
#include "nhapXuat.h"
#include "xoa.h"
#include "lietKe_TinhDiem.h"
#include "TimKiem.h"
#include "lua_chon_sap_xep.h"
#include "stringCompare.h"
#include "selectionSort.h"
#include "insertionSort.h"
#include "quickSort.h"
#include "mergeSort.h"
#include "heapSort.h"
#include "bubbleSort.h"

void menuChoMang(SV listMang[], int &soLuongSinhVien)
{
    string luaChon;
    while (true)
    {
        system("cls");
        cout << "\n\n\t\t=== CHUONG TRINH QUAN LY SINH VIEN BANG DANH SACH MANG ===\n\n";
        cout << "\t======================= MENU =======================";
        cout << "\n\t   1. Xuất danh sách sinh viên";
        cout << "\n\t   2. Tìm kiếm sinh viên";
        cout << "\n\t   3. Thêm mới sinh viên";
        cout << "\n\t   4. Xóa sinh viên";
        cout << "\n\t   5. Liệt kê các sinh viên có điểm thấp nhất";
        cout << "\n\t   6. Liệt kê các sinh viên có điểm cao nhất";
        cout << "\n\t   7. Tính điểm trung bình của lớp";
        cout << "\n\t   8. Sắp xếp danh sách sinh viên";
        cout << "\n\t   9. Quay lai";
        cout << "\n\t   0. Thoát";
        cout << "\n\t======================= END =======================";
        cout << "\n\tVui lòng chọn cách thức lưu trữ(nhập số)";
        cout << "\n\n\t - Nhập lựa chọn: ";
        getline(cin, luaChon);

        regex pattern("[0-9]");
        while (!regex_match(luaChon, pattern))
        {
            cout << "\n Chỉ nhập các số từ 0 -> 9 để chọn: ";
            getline(cin, luaChon);
        }

        if (luaChon == "1")
        {
            cout << "\n\t   1. Xuất danh sách sinh viên \n\n";
            inTieuDe();
            xuatSinhVienMang(listMang, soLuongSinhVien);
        }

        if (luaChon == "2")
        {
            cout << "\n\t   2. Tìm kiếm sinh viên\n\n";
            timKiemSinhVienMang(listMang, soLuongSinhVien);
        }

        if (luaChon == "3")
        {
            cout << "\n\t   3. Thêm mới sinh viên\n\n";
            themSinhVienMang(listMang, soLuongSinhVien, soLuongSinhVien);
            cout << "\n\tTHÊM THÀNH CÔNG !!!\n\n";
        }

        if (luaChon == "4")
        {
            // cin.ignore();
            cout << "\n\t   4. Xóa sinh viên\n\n";
            xoaSVMang(LIST_MANG, soLuongSinhVien);
            cout << "\n\tXÓA THÀNH CÔNG !!!\n\n";
        }

        if (luaChon == "5")
        {
            lietKeSVDiemCaoNhatMang(LIST_MANG, soLuongSinhVien);
        }

        if (luaChon == "6")
        {
            lietKeSVDiemThapNhatMang(LIST_MANG, soLuongSinhVien);
        }

        if (luaChon == "7")
        {

            cout << "\n\t-- Điểm Trung Bình của các sinh viên: " << diemTBMang(LIST_MANG, soLuongSinhVien) << endl;
        }

        if (luaChon == "8")
        {
            system("cls");
            int arrangeType, tieuChi;
            printSortMenu(arrangeType, tieuChi);
            if (arrangeType == 1)
            {
                clock_t start = clock();
				bubbleSortArray(LIST_MANG, tieuChi);
				clock_t end = clock();
				cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
            }
            if (arrangeType == 2)
            {
                clock_t start = clock();
				quickSortArray(LIST_MANG, 0, soLuongSinhVien - 1, tieuChi);
				clock_t end = clock();
				cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
            }
            if (arrangeType == 3)
            {
                clock_t start = clock();
				heapSortArray(LIST_MANG, soLuongSinhVien, tieuChi);
				clock_t end = clock();
				cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
            }
            if (arrangeType == 4)
            {
                clock_t start = clock();
				mergeSortArray(LIST_MANG, tieuChi);
				clock_t end = clock();
				cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
            }
            if (arrangeType == 5)
            {
                clock_t start = clock();
				insertionSortMang(LIST_MANG, tieuChi);
				clock_t end = clock();
				cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
            }
            if (arrangeType == 6)
            {
                clock_t start = clock();
				selectionSortMang(LIST_MANG, tieuChi);
				clock_t end = clock();
				cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
            }
        }

        if (luaChon == "9")
        {
            cin.ignore();
            break;
        }

        if (luaChon == "0")
        {
            cout << "\n\t == KẾT THÚC CHƯƠNG TRÌNH ==\n";
            cin.ignore();
            exit(0);
        }
        system("pause");
    }
}

void menuChoDSLKDon()
{
    string luaChon;
    while (true)
    {
        system("cls");
        cout << "\n\n\t\t=== CHƯƠNG TRÌNH QUẢN LÝ SINH VIÊN BẰNG LIÊN KẾT ĐƠN ===\n\n";
        cout << "\t======================= MENU =======================";
        cout << "\n\t   1. Xuất danh sách sinh viên";
        cout << "\n\t   2. Tìm kiếm sinh viên";
        cout << "\n\t   3. Thêm mới sinh viên";
        cout << "\n\t   4. Xóa sinh viên";
        cout << "\n\t   5. Liệt kê các sinh viên có điểm thấp nhất";
        cout << "\n\t   6. Liệt kê các sinh viên có điểm cao nhất";
        cout << "\n\t   7. Tính điểm trung bình của lớp";
        cout << "\n\t   8. Sắp xếp danh sách sinh viên";
        cout << "\n\t   9. Quay lai";
        cout << "\n\t   0. Thoát";
        cout << "\n\t======================= END =======================";
        cout << "\n\tVui lòng chọn cách thức lưu trữ(nhập số)";
        cout << "\n\n\t - Nhập lựa chọn: ";
        getline(cin, luaChon);

        regex pattern("[0-9]");
        while (!regex_match(luaChon, pattern))
        {
            cout << "\n Chỉ nhập các số từ 0 -> 9 để chọn: ";
            getline(cin, luaChon);
        }

        if (luaChon == "1")
        {
            inTieuDe();
            xuatDSLKDon(listDon);
        }

        if (luaChon == "2")
        {
            timKiemSinhVienDanhSachLkDon(listDon);
        }

        if (luaChon == "3")
        {
            cout << "- Thêm sinh viên tiếp theo: ";
            themSVVaoCuoiDSLKDon(listDon, nhapThongTinSinhVien(2));
            cout << "\n\tTHÊM THÀNH CÔNG !!!\n\n";
        }

        if (luaChon == "4")
        {
            cout << "\n\t   4. Xóa sinh viên\n\n";
            xoaSVDSLKDon(listDon);
            cout << "\n\tXÓA THÀNH CÔNG!!!\n\n";
        }

        if (luaChon == "5")
        {
            lietKeSVDiemCaoNhatDSLKDon(listDon);
        }

        if (luaChon == "6")
        {
            lietKeSVDiemThapNhatDSLKDon(listDon);
        }

        if (luaChon == "7")
        {
            cout << "\n\t-- Điểm Trung Bình của các sinh viên: " << diemTBDSLKDon(listDon) << endl;
        }

        if (luaChon == "8")
        {
            system("cls");
            int arrangeType, tieuChi;
            printSortMenu(arrangeType, tieuChi);
            if (arrangeType == 1)
            {
                clock_t start = clock();
                bubbleSortSinglyLinkedList(listDon, tieuChi);
                clock_t end = clock();
                cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
            }
            if (arrangeType == 2)
            {
                clock_t start = clock();
                quickSortLinkedList(listVong, listDon, listKep, stoi(luaChon), tieuChi, soLuong);
                clock_t end = clock();
                cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
            }
            if (arrangeType == 3)
            {
                clock_t start = clock();
                heapSortLinkedList(listVong, listDon, listKep, LIST_MANG, stoi(luaChon), tieuChi, soLuong);
                clock_t end = clock();
                cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
            }
            if (arrangeType == 4)
            {
                clock_t start = clock();
                mergeSortLinkedList(listVong, listDon, listKep, stoi(luaChon), tieuChi, soLuong);
                clock_t end = clock();
                cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
            }
            if (arrangeType == 5)
            {
                clock_t start = clock();
                insertionSortSinglyLinkedList(listDon, tieuChi);
                clock_t end = clock();
                cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
            }
            if (arrangeType == 6)
            {
                clock_t start = clock();
                selectionSortSinglyLinked(listDon, tieuChi);
                clock_t end = clock();
                cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
            }
        }

        if (luaChon == "9")
        {
            cin.ignore();
            break;
        }
        if (luaChon == "0")
        {
            giaiPhongBoNhoDSLKDon(listDon);
            cout << "\n\t == KẾT THÚC CHƯƠNG TRÌNH ==\n";
            exit(0);
        }
        system("pause");
    }
}

void menuChoDSLKVong(LIST_VONG listVong)
{
    string luaChon;
    while (true)
    {
        system("cls");
        cout << "\n\n\t\t=== CHƯƠNG TRÌNH QUẢN LÝ SINH VIÊN BẰNG DANH SÁCH LIÊN KẾT VÒNG ===\n\n";
        cout << "\t======================= MENU =======================";
        cout << "\n\t   1. Xuất danh sách sinh viên";
        cout << "\n\t   2. Tìm kiếm sinh viên";
        cout << "\n\t   3. Thêm mới sinh viên";
        cout << "\n\t   4. Xóa sinh viên";
        cout << "\n\t   5. Liệt kê các sinh viên có điểm thấp nhất";
        cout << "\n\t   6. Liệt kê các sinh viên có điểm cao nhất";
        cout << "\n\t   7. Tính điểm trung bình của lớp";
        cout << "\n\t   8. Sắp xếp danh sách sinh viên";
        cout << "\n\t   9. Quay lai";
        cout << "\n\t   0. Thoát";
        cout << "\n\t======================= END =======================";
        cout << "\n\tVui lòng chọn cách thức lưu trữ(nhập số)";
        cout << "\n\n\t - Nhập lựa chọn: ";
        getline(cin, luaChon);

        regex pattern("[0-9]");
        while (!regex_match(luaChon, pattern))
        {
            cout << "\n Chỉ nhập các số từ 0 -> 9 để chọn: ";
            getline(cin, luaChon);
        }

        if (luaChon == "1")
        {
            inTieuDe();
            xuatDSLKVong(listVong);
        }

        if (luaChon == "2")
        {
            timKiemSinhVienDanhSachLkVong(listVong);
        }

        if (luaChon == "3")
        {
            cout << "- Thêm sinh viên tiếp theo: ";
            themSVVaoCuoiDSLKVong(listVong, nhapThongTinSinhVien(3));
            cout << "\n\tTHÊM THÀNH CÔNG !!!\n\n";
        }

        if (luaChon == "4")
        {
            cout << "\n\t   4. Xóa sinh viên\n\n";
            xoaSVDSLKVong(listVong);
            cout << "\n\tXÓA THÀNH CÔNG !!!\n\n";
        }

        if (luaChon == "5")
        {
            lietKeSVDiemCaoNhatDSLKVong(listVong);
        }

        if (luaChon == "6")
        {
            lietKeSVDiemThapNhatDSLKVong(listVong);
        }

        if (luaChon == "7")
        {
            cout << "\n\t-- Điểm Trung Bình của các sinh viên: " << diemTBDSLKVong(listVong) << endl;
        }

        if (luaChon == "8")
        {
            system("cls");
            int arrangeType, tieuChi;
            printSortMenu(arrangeType, tieuChi);
            if (arrangeType == 1)
            {
                clock_t start = clock();
                bubbleSortDoublyLinkedList(listKep, tieuChi);
                clock_t end = clock();
                cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
            }
            if (arrangeType == 2)
            {
                clock_t start = clock();
                quickSortLinkedList(listVong, listDon, listKep, stoi(luaChon), tieuChi, soLuong);
                clock_t end = clock();
                cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
            }
            if (arrangeType == 3)
            {
                clock_t start = clock();
                heapSortLinkedList(listVong, listDon, listKep, LIST_MANG, stoi(luaChon), tieuChi, soLuong);
                clock_t end = clock();
                cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
            }
            if (arrangeType == 4)
            {
                clock_t start = clock();
                mergeSortLinkedList(listVong, listDon, listKep, stoi(luaChon), tieuChi, soLuong);
                clock_t end = clock();
                cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
            }
            if (arrangeType == 5)
            {
                clock_t start = clock();
                insertionSortCircularLinkedList(listVong, tieuChi);
                clock_t end = clock();
                cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
            }
            if (arrangeType == 6)
            {
                clock_t start = clock();
                selectionSortCircalLinked(listVong, tieuChi);
                clock_t end = clock();
                cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
            }
        }

        if (luaChon == "9")
        {
            break;
        }
        
        if (luaChon == "0")
        {
            giaiPhongBoNhoDSLKVong(listVong);
            cout << "\n\t == KẾT THÚC CHƯƠNG TRÌNH ==\n";
            exit(0);
        }
        system("pause");
    }
}

void menuChoDSLKKep(LIST_KEP listKep)
{
    string luaChon;
    while (true)
    {
        system("cls");
        cout << "\n\n\t\t=== CHƯƠNG TRÌNH QUẢN LÝ SINH VIÊN BẰNG DANH SÁCH LIÊN KẾT KÉP ===\n\n";
        cout << "\t======================= MENU =======================";
        cout << "\n\t   1. Xuất danh sách sinh viên";
        cout << "\n\t   2. Tìm kiếm sinh viên";
        cout << "\n\t   3. Thêm mới sinh viên";
        cout << "\n\t   4. Xóa sinh viên";
        cout << "\n\t   5. Liệt kê các sinh viên có điểm thấp nhất";
        cout << "\n\t   6. Liệt kê các sinh viên có điểm cao nhất";
        cout << "\n\t   7. Tính điểm trung bình của lớp";
        cout << "\n\t   8. Sắp xếp danh sách sinh viên";
        cout << "\n\t   9. Quay lai";
        cout << "\n\t   0. Thoát";
        cout << "\n\t======================= END =======================";
        cout << "\n\tVui lòng chọn cách thức lưu trữ(nhập số)";
        cout << "\n\n\t - Nhập lựa chọn: ";
        getline(cin, luaChon);

        regex pattern("[0-9]");
        while (!regex_match(luaChon, pattern))
        {
            cout << "\n Chỉ nhập các số từ 0 -> 9 để chọn: ";
            getline(cin, luaChon);
        }

        if (luaChon == "1")
        {
            inTieuDe();
            xuatDSLKKep(listKep);
        }

        if (luaChon == "2")
        {
            timKiemSinhVienDanhSachLKKep(listKep);
        }

        if (luaChon == "3")
        {
            cout << "- Thêm sinh viên tiếp theo: ";
            themSVVaoCuoiDSLKKep(listKep, nhapThongTinSinhVien(4));
            cout << "\n\tTHÊM THÀNH CÔNG !!!\n\n";
        }

        if (luaChon == "4")
        {
            cin.ignore();
            cout << "\n\t   4. Xóa sinh viên\n\n";
            xoaSVDSLKKep(listKep);
            cout << "\n\tXÓA THÀNH CÔNG !!!\n\n";
        }

        if (luaChon == "5")
        {
            lietKeSVDiemCaoNhatDSLKKep(listKep);
        }

        if (luaChon == "6")
        {
            lietKeSVDiemThapNhatDSLKKep(listKep);
        }

        if (luaChon == "7")
        {
            cout << "\n\t-- Điểm Trung Bình của các sinh viên: " << diemTBDSLKKep(listKep) << endl;
        }

        if (luaChon == "8")
        {
            system("cls");
            int arrangeType, tieuChi;
            printSortMenu(arrangeType, tieuChi);
            if (arrangeType == 1)
            {
                clock_t start = clock();
                bubbleSortCircularLinkedList(listVong, tieuChi);
                clock_t end = clock();
                cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
            }
            if (arrangeType == 2)
            {
                clock_t start = clock();
                quickSortLinkedList(listVong, listDon, listKep, stoi(luaChon), tieuChi, soLuong);
                clock_t end = clock();
                cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
            }
            if (arrangeType == 3)
            {
                clock_t start = clock();
                heapSortLinkedList(listVong, listDon, listKep, LIST_MANG, stoi(luaChon), tieuChi, soLuong);
                clock_t end = clock();
                cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
            }
            if (arrangeType == 4)
            {
                clock_t start = clock();
                mergeSortLinkedList(listVong, listDon, listKep, stoi(luaChon), tieuChi, soLuong);
                clock_t end = clock();
                cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
            }
            if (arrangeType == 5)
            {
                clock_t start = clock();
                insertionSortDoubleLinkedList(listKep, tieuChi);
                clock_t end = clock();
                cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
            }
            if (arrangeType == 6)
            {
                clock_t start = clock();
                selectionSortDoubleLinked(listKep, tieuChi);
                clock_t end = clock();
                cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
            }
        }

        if (luaChon == "9")
        {
            cin.ignore();
            break;
        }
        if (luaChon == "0")
        {
            giaiPhongBoNhoDSLKKep(listKep);
            cout << "\n\t == KẾT THÚC CHƯƠNG TRÌNH ==\n";
            exit(0);
        }
        system("pause");
    }
}

static void mainMenu()
{
    string luaChon;
    while (true)
    {
        system("cls");
        cout << "\n\n\t\t=== CHƯƠNG TRÌNH QUẢN LÝ SINH VIÊN ===\n\n";
        cout << "\t======================= MENU =======================";
        cout << "\n\t   1. Lưu trữ bằng danh sách mảng";
        cout << "\n\t   2. Lưu trữ bằng danh sách liên kết đơn";
        cout << "\n\t   3. Lưu trữ bằng danh sách liên kết vòng";
        cout << "\n\t   4. Lưu trữ bằng danh sách liên kết kép";
        cout << "\n\t======================= END =======================";
        cout << "\n\tVui lòng chọn cách thức lưu trữ(nhập số)";
        cout << "\n\n\t - Nhập lựa chọn: ";
        getline(cin, luaChon);

        regex pattern("[1-4]");
        while (!regex_match(luaChon, pattern))
        {
            cout << "\n Chỉ nhập các số từ 1 -> 4 để chọn: ";
            getline(cin, luaChon);
        }

        if (luaChon == "1")
        {
            nhapMang();
            menuChoMang(LIST_MANG, soLuong);
        }

        if (luaChon == "2")
        {

            khoitaoDSLKDon();

            nhapDon();
            menuChoDSLKDon();
        }

        if (luaChon == "3")
        {

            LIST_VONG listVong;
            khoiTaoDSLKVong(listVong);

            nhapVong(listVong);
            menuChoDSLKVong(listVong);
        }

        if (luaChon == "4")
        {

            LIST_KEP listKep;
            khoiTaoDSLKKep(listKep);

            nhapKep(listKep);
            menuChoDSLKKep(listKep);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    SetConsoleOutputCP(CP_UTF8);
    mainMenu();
}