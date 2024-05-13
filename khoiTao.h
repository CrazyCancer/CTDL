
#define max 10000

typedef struct node
{
    SV data;
    node* pNext;
    node* pPrev;
} NODE;
typedef NODE* pNODE;

typedef struct list
{
    pNODE pHead;
    pNODE pTail;
} LIST;

LIST ds;

void khoiTao(LIST& list) {
    list.pHead = NULL;
    list.pTail = NULL;
}

pNODE khoiTaoNodeDon(SV sv) {
    pNODE p = new NODE;
    if (p == NULL)
    {
        exit(1);
    }
    p->data = sv;
    p->pNext = NULL;

    return p;
}

pNODE khoiTaoNodeKep(SV sv)
{
    pNODE p = new NODE;
    if (p == NULL)
    {
        exit(1);
    }
    p->data = sv;
    p->pNext = NULL;
    p->pPrev = NULL;

    return p;
}

// Ham them vao cuoi danh sach lien ket don
void themVaoCuoiDon(LIST& list, pNODE p)
{
    if (list.pHead == NULL)
    {
        list.pHead = p;
    }
    else
    {
        pNODE temp = list.pHead;
        while (temp->pNext != NULL)
        {
            temp = temp->pNext;
        }
        temp->pNext = p;
    }
}

void themVaoCuoiVong(LIST& list, pNODE p)
{
    // Danh sach rong
    if (list.pTail == NULL)
    {
        list.pTail = p;
        p->pNext = p; // Khi danh sách rỗng, pNext của phần tử đầu tiên trỏ lại chính nó
    }
    else
    {
        p->pNext = list.pTail->pNext; // Liên kết phần tử mới với phần tử đầu tiên
        list.pTail->pNext = p; // Liên kết phần tử cuối cùng với phần tử mới
        list.pTail = p; // Cập nhật pTail để trỏ đến phần tử mới
    }
}

// Ham them vao cuoi danh sach lien ket kep
void themVaoCuoiKep(LIST& list, pNODE p)
{
    // Danh sach rong
    if (list.pHead == NULL)
    {
        list.pHead = list.pTail = p;
    }
    else
    {
        list.pTail->pNext = p;
        p->pPrev = list.pTail;
        list.pTail = p;
    }
}

//doc vao danh sach lien ket don
void nhapDon(LIST& list) {
    fstream input("DSSV.csv", ios::in | ios::out);
    
    if (!input.is_open()) {
        cout << "\nMo file khong thanh cong\n";
        return;
    }

    //Đọc dòng tiêu đề
    string temp;
    getline(input, temp);

    while (!input.eof()) {
        SV sv = nhapTTSinhVien(input, 2);
        pNODE p = khoiTaoNodeDon(sv);
        themVaoCuoiDon(list, p);
    }
}

//doc vao danh sach lien ket kep
void nhapKep(LIST& list)
{
    fstream input("DSSV.csv", ios::in | ios::out);
    
    if (!input.is_open()) {
        cout << "\nMo file khong thanh cong\n";
        return;
    }

    //Đọc dòng tiêu đề
    string temp;
    getline(input, temp);

    while (!input.eof()) {
        SV sv = nhapTTSinhVien(input, 3);
        pNODE p = khoiTaoNodeKep(sv);
        themVaoCuoiKep(list, p);
    }
}

//doc vao danh sach lien ket vong
void nhapVong(LIST& list)
{
    fstream input("DSSV.csv", ios::in | ios::out);
    
    if (!input.is_open()) {
        cout << "\nMo file khong thanh cong\n";
        return;
    }
        
    //Đọc dòng tiêu đề
    string temp;
    getline(input, temp);

    while (!input.eof()) {
        SV sv = nhapTTSinhVien(input, 3);
        pNODE p = new NODE;
        p->data = sv;
        p->pNext = NULL;
        themVaoCuoiVong(list, p);
    }   
}

//Mang
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
        LIST_MANG[i] = nhapTTSinhVien(input, 1);
        i++;
    }

    input.close();
}