// #MergeSort dslk đơn
void mergeSinglyLinkedListPointer(vector<pNODE_DON> &linkedListPointer, int left, int mid, int right, int tieuChi)
{
    int u, v, i = 0, j = 0, k = 0;
    u = mid - left + 1;
    v = right - mid;
    SV leftArray[MAX], rightArray[MAX];

    // Tách thành 2 mảng trái/phải
    for (i = 0; i < u; i++)
        leftArray[i] = linkedListPointer[left + i]->data;
    for (j = 0; j < v; j++)
        rightArray[j] = linkedListPointer[mid + j + 1]->data;
    i = 0;
    j = 0;
    k = left; // bắt đầu từ vị trí lưu lần trước

    // gộp mảng 2 trái/phải vào a với điều kiện phần tử bên trái < phần tử bên phải
    while (i < u && j < v)
    {
        if (tieuChi == 1)
        {
            if (cmpStr(leftArray[i].maSV, rightArray[j].maSV) <= 0)
            {
                linkedListPointer[k++]->data = leftArray[i++];
            }
            else
            {
                linkedListPointer[k++]->data = rightArray[j++];
            }
        }
        if (tieuChi == 2)
        {
            if (cmpStr(leftArray[i].ten, rightArray[j].ten) <= 0)
            {
                linkedListPointer[k++]->data = leftArray[i++];
            }
            else
            {
                linkedListPointer[k++]->data = rightArray[j++];
            }
        }
        if (tieuChi == 3)
        {
            if (leftArray[i].diem <= rightArray[j].diem)
            {
                linkedListPointer[k++]->data = leftArray[i++];
            }
            else
            {
                linkedListPointer[k++]->data = rightArray[j++];
            }
        }
    }
    // Thêm những ptu còn lại cảu 2 mảng trái/phải vào a
    while (i < u)
    {
        linkedListPointer[k++]->data = leftArray[i++];
    }
    while (j < v)
    {
        linkedListPointer[k++]->data = rightArray[j++];
    }
}

void mergeSortSinglyLinkedList(vector<pNODE_DON>& linkedListPointer, int left, int right, int tieuChi)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2; // (left+right)/2
        // gọi đệ quy chia đôi mảng
        mergeSortSinglyLinkedList(linkedListPointer, left, mid, tieuChi);
        mergeSortSinglyLinkedList(linkedListPointer, mid + 1, right, tieuChi);

        mergeSinglyLinkedListPointer(linkedListPointer, left, mid, right, tieuChi);
    }
    else
        return;
}

// #MergeSort dslk vong
void mergeCircularLinkedListPointer(vector<pNODE_VONG> &linkedListPointer, int left, int mid, int right, int tieuChi)
{
    int u, v, i = 0, j = 0, k = 0;
    u = mid - left + 1;
    v = right - mid;
    SV leftArray[MAX], rightArray[MAX];

    // Tách thành 2 mảng trái/phải
    for (i = 0; i < u; i++)
        leftArray[i] = linkedListPointer[left + i]->data;
    for (j = 0; j < v; j++)
        rightArray[j] = linkedListPointer[mid + j + 1]->data;
    i = 0;
    j = 0;
    k = left; // bắt đầu từ vị trí lưu lần trước

    // gộp mảng 2 trái/phải vào a với điều kiện phần tử bên trái < phần tử bên phải
    while (i < u && j < v)
    {
        if (tieuChi == 1)
        {
            if (cmpStr(leftArray[i].maSV, rightArray[j].maSV) <= 0)
            {
                linkedListPointer[k++]->data = leftArray[i++];
            }
            else
            {
                linkedListPointer[k++]->data = rightArray[j++];
            }
        }
        if (tieuChi == 2)
        {
            if (cmpStr(leftArray[i].ten, rightArray[j].ten) <= 0)
            {
                linkedListPointer[k++]->data = leftArray[i++];
            }
            else
            {
                linkedListPointer[k++]->data = rightArray[j++];
            }
        }
        if (tieuChi == 3)
        {
            if (leftArray[i].diem <= rightArray[j].diem)
            {
                linkedListPointer[k++]->data = leftArray[i++];
            }
            else
            {
                linkedListPointer[k++]->data = rightArray[j++];
            }
        }
    }
    // Thêm những ptu còn lại cảu 2 mảng trái/phải vào a
    while (i < u)
    {
        linkedListPointer[k++]->data = leftArray[i++];
    }
    while (j < v)
    {
        linkedListPointer[k++]->data = rightArray[j++];
    }
}

void mergeSortCircularLinkedList(vector<pNODE_VONG> &linkedListPointer, int left, int right, int tieuChi)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2; // (left+right)/2
        // gọi đệ quy chia đôi mảng
        mergeSortCircularLinkedList(linkedListPointer, left, mid, tieuChi);
        mergeSortCircularLinkedList(linkedListPointer, mid + 1, right, tieuChi);

        mergeCircularLinkedListPointer(linkedListPointer, left, mid, right, tieuChi);
    }
    else
        return;
}

// #MergeSort dslk kep
void mergeDoublyLinkedListPointer(vector<pNODE_KEP> &linkedListPointer, int left, int mid, int right, int tieuChi)
{
    int u, v, i = 0, j = 0, k = 0;
    u = mid - left + 1;
    v = right - mid;
    SV leftArray[MAX], rightArray[MAX];

    // Tách thành 2 mảng trái/phải
    for (i = 0; i < u; i++)
        leftArray[i] = linkedListPointer[left + i]->data;
    for (j = 0; j < v; j++)
        rightArray[j] = linkedListPointer[mid + j + 1]->data;
    i = 0;
    j = 0;
    k = left; // bắt đầu từ vị trí lưu lần trước

    // gộp mảng 2 trái/phải vào a với điều kiện phần tử bên trái < phần tử bên phải
    while (i < u && j < v)
    {
        if (tieuChi == 1)
        {
            if (cmpStr(leftArray[i].maSV, rightArray[j].maSV) <= 0)
            {
                linkedListPointer[k++]->data = leftArray[i++];
            }
            else
            {
                linkedListPointer[k++]->data = rightArray[j++];
            }
        }
        if (tieuChi == 2)
        {
            if (cmpStr(leftArray[i].ten, rightArray[j].ten) <= 0)
            {
                linkedListPointer[k++]->data = leftArray[i++];
            }
            else
            {
                linkedListPointer[k++]->data = rightArray[j++];
            }
        }
        if (tieuChi == 3)
        {
            if (leftArray[i].diem <= rightArray[j].diem)
            {
                linkedListPointer[k++]->data = leftArray[i++];
            }
            else
            {
                linkedListPointer[k++]->data = rightArray[j++];
            }
        }
    }
    // Thêm những ptu còn lại cảu 2 mảng trái/phải vào a
    while (i < u)
    {
        linkedListPointer[k++]->data = leftArray[i++];
    }
    while (j < v)
    {
        linkedListPointer[k++]->data = rightArray[j++];
    }
}

void mergeSortDoublyLinkedList(vector<pNODE_KEP> &linkedListPointer, int left, int right, int tieuChi)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2; // (left+right)/2
        // gọi đệ quy chia đôi mảng
        mergeSortDoublyLinkedList(linkedListPointer, left, mid, tieuChi);
        mergeSortDoublyLinkedList(linkedListPointer, mid + 1, right, tieuChi);

        mergeDoublyLinkedListPointer(linkedListPointer, left, mid, right, tieuChi);
    }
    else
        return;
}

// #MergeSort dslk

void mergeSortLinkedList(LIST_VONG &dsVong, LIST_DON &dsDon, LIST_KEP &dsKep, int kieuDL, int tieuChi, int n)
{
    if (kieuDL == 2)
    {
        vector<pNODE_DON> linkedListPointer;
        for (pNODE_DON p = dsDon.pHead_Don; p != NULL; p = p->pNext_Don)
            linkedListPointer.push_back(p);

        mergeSortSinglyLinkedList(linkedListPointer, 0, n - 1, tieuChi);

        khoitaoDSLKDon();
        for (int i = 0; i < n; i++)
            themVaoCuoiDSLKDon(dsDon, khoiTaoNodeDon(linkedListPointer[i]->data));

        linkedListPointer.clear();
        linkedListPointer.shrink_to_fit();
    }
    if (kieuDL == 3)
    {
        vector<pNODE_VONG> linkedListPointer;
        pNODE_VONG p = dsVong.pTail_Vong->pNext_Vong;
        while (p != dsVong.pTail_Vong)
        {
            linkedListPointer.push_back(p);
            p = p->pNext_Vong;
        }
        linkedListPointer.push_back(p);

        mergeSortCircularLinkedList(linkedListPointer, 0, n - 1, tieuChi);
        khoiTaoDSLKVong(dsVong);
        for (int i = 0; i < n; i++)
            themVaoCuoiDSLKVong(dsVong, khoiTaoNodeVong(linkedListPointer[i]->data));

        linkedListPointer.clear();
        linkedListPointer.shrink_to_fit();
    }
    if (kieuDL == 4)
    {
        vector<pNODE_KEP> linkedListPointer;
        pNODE_KEP p = dsKep.pHead_Kep;
        while (p != NULL)
        {
            linkedListPointer.push_back(p);
            p = p->pNext_Kep;
        }
        
        mergeSortDoublyLinkedList(linkedListPointer, 0, n - 1, tieuChi);

        khoiTaoDSLKKep(dsKep);
        for (int i = 0; i < n; i++)
        {
            themVaoCuoiDSLKKep(dsKep, khoiTaoNodeKep(linkedListPointer[i]->data));
        }

        linkedListPointer.clear();
        linkedListPointer.shrink_to_fit();
    }
}
void mergeSortArray(SV LIST_MANG[], int tieuChi)
{
    int i, j, k, low1, up1, low2, up2, size;
    size = 1;
    if (tieuChi == 1)
    {
        while (size < soLuong)
        {
            SV dstam[MAX];
            low1 = 0;
            k = 0;
            while (low1 + size < soLuong)
            {
                up1 = low1 + size - 1;
                low2 = up1 + 1;
                up2 = (low2 + size - 1 < soLuong) ? low2 + size - 1 : soLuong - 1;
                for (i = low1, j = low2; i <= up1 && j <= up2; k++)
                    if (LIST_MANG[i].maSV <= LIST_MANG[j].maSV)
                        dstam[k] = LIST_MANG[i++];
                    else
                        dstam[k] = LIST_MANG[j++];
                for (; i <= up1; k++)
                    dstam[k] = LIST_MANG[i++];
                for (; j <= up2; k++)
                    dstam[k] = LIST_MANG[j++];
                low1 = up2 + 1;
            }
            for (i = low1; k < soLuong; i++)
                dstam[k++] = LIST_MANG[i];
            for (i = 0; i < soLuong; i++) // gan nguoc tra lai cho A
                LIST_MANG[i] = dstam[i];
            size *= 2;
        }
    }
    if (tieuChi == 2)
    {
        while (size < soLuong)
        {
            SV dstam[MAX];
            low1 = 0;
            k = 0;
            while (low1 + size < soLuong)
            {
                up1 = low1 + size - 1;
                low2 = up1 + 1;
                up2 = (low2 + size - 1 < soLuong) ? low2 + size - 1 : soLuong - 1;
                for (i = low1, j = low2; i <= up1 && j <= up2; k++)
                    if (cmpStr(LIST_MANG[i].ten, LIST_MANG[j].ten) <=0)
                        dstam[k] = LIST_MANG[i++];
                    else
                        dstam[k] = LIST_MANG[j++];
                for (; i <= up1; k++)
                    dstam[k] = LIST_MANG[i++];
                for (; j <= up2; k++)
                    dstam[k] = LIST_MANG[j++];
                low1 = up2 + 1;
            }
            for (i = low1; k < soLuong; i++)
                dstam[k++] = LIST_MANG[i];
            for (i = 0; i < soLuong; i++) // gan nguoc tra lai cho A
                LIST_MANG[i] = dstam[i];
            size *= 2;
        }
    }
    if (tieuChi == 3)
    {
        while (size < soLuong)
        {
            SV dstam[MAX];
            low1 = 0;
            k = 0;
            while (low1 + size < soLuong)
            {
                up1 = low1 + size - 1;
                low2 = up1 + 1;
                up2 = (low2 + size - 1 < soLuong) ? low2 + size - 1 : soLuong - 1;
                for (i = low1, j = low2; i <= up1 && j <= up2; k++)
                    if (LIST_MANG[i].diem <= LIST_MANG[j].diem)
                        dstam[k] = LIST_MANG[i++];
                    else
                        dstam[k] = LIST_MANG[j++];
                for (; i <= up1; k++)
                    dstam[k] = LIST_MANG[i++];
                for (; j <= up2; k++)
                    dstam[k] = LIST_MANG[j++];
                low1 = up2 + 1;
            }
            for (i = low1; k < soLuong; i++)
                dstam[k++] = LIST_MANG[i];
            for (i = 0; i < soLuong; i++) // gan nguoc tra lai cho A
                LIST_MANG[i] = dstam[i];
            size *= 2;
        }
    }
}
