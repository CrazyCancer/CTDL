// Convert to linked list
void convertToSinglyLinkedList(LIST_DON &dsDon, SV a[])
{
    khoitaoDSLKDon();
    for (int i = 0; i < soLuong; i++)
        themVaoCuoiDSLKDon(dsDon, khoiTaoNodeDon(a[i]));
}

void convertToDoublyLinkedList(LIST_KEP &dsKep, SV a[])
{
    khoiTaoDSLKKep(dsKep);
    for (int i = 0; i < soLuong; i++)
        themVaoCuoiDSLKKep(dsKep, khoiTaoNodeKep(a[i]));
}

void convertToCircularLinkedList(LIST_VONG &dsVong, SV a[])
{
    khoiTaoDSLKVong(dsVong);
    for (int i = 0; i < soLuong; i++)
        themVaoCuoiDSLKVong(dsVong, khoiTaoNodeVong(a[i]));
}

// HeapSort
void initHeapTree(SV LIST_MANG[], int n, int i, int tieuChi)
{
    int L = 2 * i + 1, R = 2 * i, Max;
    if (tieuChi == 1)
    {
        if (L < n && cmpStr(LIST_MANG[L].maSV, LIST_MANG[i].maSV) > 0)
            Max = L;
        else
            Max = i;
        if (R < n && cmpStr(LIST_MANG[R].maSV, LIST_MANG[Max].maSV) > 0)
            Max = R;
    }
    if (tieuChi == 2)
    {
        if (L < n && cmpStr(LIST_MANG[L].ten, LIST_MANG[i].ten) > 0)
            Max = L;
        else
            Max = i;
        if (R < n && cmpStr(LIST_MANG[R].ten, LIST_MANG[Max].ten) > 0)
            Max = R;
    }
    if (tieuChi == 3)
    {
        if (L < n && LIST_MANG[L].diem > LIST_MANG[i].diem)
            Max = L;
        else
            Max = i;
        if (R < n && LIST_MANG[R].diem > LIST_MANG[Max].diem)
            Max = R;
    }
    if (i != Max)
    {
        swap(LIST_MANG[i], LIST_MANG[Max]);
        initHeapTree(LIST_MANG, n, Max, tieuChi);
    }
}

void heapSortArray(SV LIST_MANG[], int n, int tieuChi)
{
    // tạo lại cây heap
    for (int i = n / 2 - 1; i >= 0; i--)
        initHeapTree(LIST_MANG, n, i, tieuChi);
    // Đưa nút lớn nhất về gốc
    for (int i = n - 1; i >= 0; i--)
    {
        swap(LIST_MANG[0], LIST_MANG[i]);
        initHeapTree(LIST_MANG, i, 0, tieuChi);
    }
}

void heapSortLinkedList(LIST_VONG &dsVong, LIST_DON &dsDon, LIST_KEP &dsKep, SV a[], int kieuDL, int tieuChi, int n)
{
    //cout << kieuDL;
    if (kieuDL == 2)
    {
        //xuatDSLKDon(listDon);
        int k = 0;
        pNODE_DON i = dsDon.pHead_Don;
        while (i != NULL)
        {
            a[k] = i->data;
            k++;
            i = i->pNext_Don;
        }
        giaiPhongBoNhoDSLKDon(dsDon);
    }
    if (kieuDL == 3)
    {
        int k = 0;
        pNODE_VONG p = dsVong.pTail_Vong->pNext_Vong;
        while (p != dsVong.pTail_Vong)
        {
            a[k] = p->data;
            k++;
            p = p->pNext_Vong;
        }
        a[n - 1] = p->data;
        giaiPhongBoNhoDSLKVong(dsVong);
    }
    if (kieuDL == 4)
    {
        int k = 0;
        pNODE_KEP i = dsKep.pHead_Kep;
        while (i != NULL)
        {
            a[k] = i->data;
            k++;
            i = i->pNext_Kep;
        }
        giaiPhongBoNhoDSLKKep(dsKep);
    }
    
    //xuatSinhVienMang(a, n);
    heapSortArray(a, n, tieuChi);
    
    if (kieuDL == 2)
    {
        convertToSinglyLinkedList(dsDon, a);
    }
    if (kieuDL == 3)
    {
        convertToCircularLinkedList(dsVong, a);
    }
    if (kieuDL == 4)
    {
        convertToDoublyLinkedList(dsKep, a);
    }
}
