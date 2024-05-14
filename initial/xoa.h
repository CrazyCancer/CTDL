//thực hiện xóa sinh viên

void xoaMang(int& soLuong,string& maSV) {
    bool check = false;
    for (int i = 0; i < soLuong; ++i) {
        if (!stricmp(LIST_MANG[i].maSV.c_str(), maSV.c_str())) {
            check = true;
            for (int j = i; j < soLuong - 1; ++j) {
                LIST_MANG[j] = LIST_MANG[j + 1];
            }
            // Giảm số lượng sinh viên đi 1
            soLuong--;
            cout << "Da xoa sinh vien voi ma so " << maSV << " khoi danh sach." << endl;
            break;
        }
    }
    if (!check) {
        cout << "Khong tim thay sinh vien voi ma so " << maSV << endl;
    }
}

//------------------Xóa sinh viên với danh sách liên kết đơn--------------
void XoaDon(LIST &l, string &maSV) {

    pNODE current = l.pHead;
    pNODE previous = nullptr;

    while (current != nullptr) {
        if (!stricmp(current->data.maSV.c_str(), maSV.c_str())) {
            if (previous == nullptr) {
                l.pHead = current->pNext;
            } else {
                previous->pNext = current->pNext;
            }
            delete current;
            cout << "Da xoa sinh vien co ma SV " << maSV << " khoi danh sach.\n";
            return;
        }
        previous = current;
        current = current->pNext;
    }
    cout << "Khong tim thay sinh vien co ma SV " << maSV << " trong danh sach.\n";
}

//------------------Xóa sinh viên với danh sách liên kết kép-------------
//tìm node chứ thông tin cần xóa
pNODE findNodeByMaSV(LIST& lst, string maSV) {
    if (lst.pHead == nullptr)
        return nullptr;

    pNODE pTemp = lst.pHead;
    do {
        if (!stricmp(pTemp->data.maSV.c_str(), maSV.c_str()))
            return pTemp;
        pTemp = pTemp->pNext;
    } while (pTemp != lst.pHead);

    return nullptr; // Không tìm thấy
}

// Hàm xóa nút khỏi danh sách
void xoaKep(LIST& lst, pNODE pNode) {
    if (pNode == nullptr)
        return;

    if (pNode == lst.pHead) {
        lst.pHead = lst.pHead->pNext;
        lst.pTail->pNext = lst.pHead;
        delete pNode;
        return;
    }

    pNODE pPrev = nullptr;
    pNODE pTemp = lst.pHead;
    do {
        if (pTemp == pNode) {
            pPrev->pNext = pTemp->pNext;
            delete pTemp;
            return;
        }
        pPrev = pTemp;
        pTemp = pTemp->pNext;
    } while (pTemp != lst.pHead);
}


//------------------------Xóa sinh viên với danh sách liên kết vòng-------------------

void xoaVong(LIST &l, string maSV) {
    if (l.pTail == nullptr) {
        cout << "Danh sach rong!" << endl;
        return;
    }

    // case 1 sinh vien
    if (l.pTail->pNext, l.pTail && !stricmp(l.pTail->data.maSV.c_str(), maSV.c_str())) {
        delete l.pTail;
        l.pTail = nullptr;
        cout << "Da xoa sinh vien co maSV = " << maSV << endl;
        return;
    }

    pNODE curNode = l.pTail->pNext; // Bắt đầu từ phần tử đầu tiên
    pNODE prevNode = l.pTail; // Node trước node cần xóa

    // Xác định node trước node cần xóa
    while (curNode != l.pTail && stricmp(curNode->data.maSV.c_str(), maSV.c_str())) {
        prevNode = curNode;
        curNode = curNode->pNext;
    }

    if (!stricmp(curNode->data.maSV.c_str(), maSV.c_str())) {
        prevNode->pNext = curNode->pNext;
        if (curNode == l.pTail) {
            l.pTail = prevNode; // Cập nhật lại pTail nếu node bị xóa là node cuối cùng
        }
        delete curNode;
        cout << "Da xoa sinh vien co maSV = " << maSV << endl;
    } 
    else {
        cout << "Khong tim thay sinh vien co maSV = " << maSV << endl;
    }
}