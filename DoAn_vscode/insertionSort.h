
void insertionSortMang(SV LIST_MANG[], int tieuchi)
{
    if (tieuchi == 1)
    {
        string x;
        int i, j;
        for (i = 1; i < soLuong; i++)
        {
            x = LIST_MANG[i].maSV;
            for (j = i - 1; j >= 0 && cmpStr(x, LIST_MANG[j].maSV) < 0; j--)
                swap(LIST_MANG[j + 1], LIST_MANG[j]);
            LIST_MANG[j + 1].maSV = x;
        }
    }
    if (tieuchi == 2)
    {
        string x;
        int i, j;
        for (i = 1; i < soLuong; i++)
        {
            x = LIST_MANG[i].ten;
            for (j = i - 1; j >= 0 && cmpStr(x, LIST_MANG[j].ten) < 0; j--)
                swap(LIST_MANG[j + 1], LIST_MANG[j]);
            LIST_MANG[j + 1].ten = x;
        }
    }
    if (tieuchi == 3)
    {
        float x;
        int i, j;
        for (i = 1; i < soLuong; i++)
        {
            x = LIST_MANG[i].diem;
            for (j = i - 1; j >= 0 && x < LIST_MANG[j].diem; j--)
                swap(LIST_MANG[j + 1], LIST_MANG[j]);
            LIST_MANG[j + 1].diem = x;
        }
    }
}

void insertionSortSinglyLinkedList(LIST_DON& ds, int tieuChi)
{
    if (ds.pHead_Don == NULL || ds.pHead_Don->pNext_Don == NULL)
    {
        return;
    }

    pNODE_DON pCurrent = ds.pHead_Don, sorted = NULL;
    while (pCurrent != NULL)
    {
        pNODE_DON pPrev = sorted, pTmp = NULL, nextNode = pCurrent->pNext_Don;
        while (pPrev != NULL)
        {
            if (tieuChi == 1)
            {
                if (cmpStr(pPrev->data.maSV, pCurrent->data.maSV) >= 0)
                    break;
            }
            if (tieuChi == 2)
            {
                if (cmpStr(pPrev->data.ten, pCurrent->data.ten) >= 0)
                    break;
            }
            if (tieuChi == 3)
            {
                if (pPrev->data.diem >= pCurrent->data.diem)
                    break;
            }
            pTmp = pPrev;
            pPrev = pPrev->pNext_Don;
        }

        if (pTmp == NULL)
        {
            pCurrent->pNext_Don = sorted;
            sorted = pCurrent;
        }
        else
        {
            pTmp->pNext_Don = pCurrent;
            pCurrent->pNext_Don = pPrev;
        }
        pCurrent = nextNode;
    }
    ds.pHead_Don = sorted;
}

void insertionSortDoubleLinkedList(LIST_KEP &dsKep, int tieuChi)
{
    
    vector<pNODE_KEP> linkedListPointer;
    pNODE_KEP p = dsKep.pHead_Kep;
    while (p != NULL)
    {
        linkedListPointer.push_back(p);
        p = p->pNext_Kep;
    }

    int i, j;
    for (i = 1; i < soLuong; i++)
    {
        SV key = linkedListPointer[i]->data;
        if (tieuChi == 1)
        {
            for (j = i - 1; j >= 0 && cmpStr(key.maSV, linkedListPointer[j]->data.maSV) < 0; j--)
                linkedListPointer[j + 1]->data = linkedListPointer[j]->data;
        }
        if (tieuChi == 2)
        {
            for (j = i - 1; j >= 0 && cmpStr(key.ten, linkedListPointer[j]->data.ten) < 0; j--)
                linkedListPointer[j + 1]->data = linkedListPointer[j]->data;
        }
        if (tieuChi == 3)
        {
            for (j = i - 1; j >= 0 && key.diem < linkedListPointer[j]->data.diem; j--)
                linkedListPointer[j + 1]->data = linkedListPointer[j]->data;
        }
        linkedListPointer[j + 1]->data = key;
    }
    /*for (int i = 1; i < soLuong; i++)
        cout << linkedListPointer[i]->data.maSV << "\n";*/
    khoiTaoDSLKKep(dsKep);
    for (int i = 0; i < soLuong; i++)
    {
        themVaoCuoiDSLKKep(dsKep, khoiTaoNodeKep(linkedListPointer[i]->data));
    }

    linkedListPointer.clear();
    linkedListPointer.shrink_to_fit();
}

void insertionSortCircularLinkedList(LIST_VONG& dsVong, int tieuChi)
{
    vector<pNODE_VONG> linkedListPointer;
    pNODE_VONG p = dsVong.pTail_Vong->pNext_Vong;
    while (p != dsVong.pTail_Vong)
    {
        linkedListPointer.push_back(p);
        p = p->pNext_Vong;
    }
    linkedListPointer.push_back(p);

    int i, j;
    for (i = 1; i < soLuong; i++)
    {
        SV key = linkedListPointer[i]->data;
        if (tieuChi == 1)
        {
            for (j = i - 1; j >= 0 && cmpStr(key.maSV, linkedListPointer[j]->data.maSV) < 0; j--)
                linkedListPointer[j + 1]->data = linkedListPointer[j]->data;
        }
        if (tieuChi == 2)
        {
            for (j = i - 1; j >= 0 && cmpStr(key.ten, linkedListPointer[j]->data.ten) < 0; j--)
                linkedListPointer[j + 1]->data = linkedListPointer[j]->data;
        }
        if (tieuChi == 3)
        {
            for (j = i - 1; j >= 0 && key.diem < linkedListPointer[j]->data.diem; j--)
                linkedListPointer[j + 1]->data = linkedListPointer[j]->data;
        }
        linkedListPointer[j + 1]->data = key;
    }
    /*for (int i = 1; i < soLuong; i++)
        cout << linkedListPointer[i]->data.maSV << "\n";*/
    khoiTaoDSLKVong(dsVong);
    for (int i = 0; i < soLuong; i++)
        themVaoCuoiDSLKVong(dsVong, khoiTaoNodeVong(linkedListPointer[i]->data));

    linkedListPointer.clear();
    linkedListPointer.shrink_to_fit();
}