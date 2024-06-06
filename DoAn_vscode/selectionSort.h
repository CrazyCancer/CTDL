
void selectionSortMang(SV LIST_MANG[], int tieuChi)
{
    int vitrimin;
    int i, j;
    if (tieuChi == 1)
    {
        string min;
        for (i = 0; i < soLuong - 1; i++)
        {
            min = LIST_MANG[i].maSV;
            vitrimin = i;
            for (j = i + 1; j < soLuong; j++)
                if (cmpStr(LIST_MANG[j].maSV, min) < 0)
                {
                    min = LIST_MANG[j].maSV;
                    vitrimin = j;
                }
            // Doi cho 2 phan tu A[i] va A[vitrimin]
            swap(LIST_MANG[vitrimin], LIST_MANG[i]);
        }
    }
    if (tieuChi == 2)
    {
        string min;
        for (i = 0; i < soLuong - 1; i++)
        {
            min = LIST_MANG[i].ten;
            vitrimin = i;
            for (j = i + 1; j < soLuong; j++)
                if (cmpStr(LIST_MANG[j].ten, min) < 0)
                {
                    min = LIST_MANG[j].ten;
                    vitrimin = j;
                }
            // Doi cho 2 phan tu A[i] va A[vitrimin]
            swap(LIST_MANG[vitrimin], LIST_MANG[i]);
        }
    }
    if (tieuChi == 3)
    {
        int min;
        for (i = 0; i < soLuong - 1; i++)
        {
            min = LIST_MANG[i].diem;
            vitrimin = i;
            for (j = i + 1; j < soLuong; j++)
                if (LIST_MANG[j].diem < min)
                {
                    min = LIST_MANG[j].diem;
                    vitrimin = j;
                }
            // Doi cho 2 phan tu A[i] va A[vitrimin]
            swap(LIST_MANG[vitrimin], LIST_MANG[i]);
        }
    }
}
void selectionSortSinglyLinked(LIST_DON& ds, int tieuChi)
{
    pNODE_DON p, q, Min;
    for (p = ds.pHead_Don; p->pNext_Don != NULL; p = p->pNext_Don)
    {
        Min = p;
        for (q = p->pNext_Don; q != NULL; q = q->pNext_Don)
        {
            if (tieuChi == 1)
            {
                if (cmpStr(q->data.maSV, Min->data.maSV) < 0)
                {
                    Min = q;
                }
            }
            if (tieuChi == 2)
            {
                if (cmpStr(q->data.ten, Min->data.ten) < 0)
                {
                    Min = q;
                }
            }
            if (tieuChi == 3)
            {
                if (q->data.diem < Min->data.diem)
                {
                    Min = q;
                }
            }
        }
        swap(p->data,Min->data);
    }
}

void selectionSortDoubleLinked(LIST_KEP& ds, int tieuChi)
{
    pNODE_KEP p, q, Min;
    for (p = ds.pHead_Kep; p->pNext_Kep != NULL; p = p->pNext_Kep)
    {
        Min = p;
        for (q = p->pNext_Kep; q != NULL; q = q->pNext_Kep)
        {
            if (tieuChi == 1)
            {
                if (cmpStr(q->data.maSV, Min->data.maSV) < 0)
                {
                    Min = q;
                }
            }
            if (tieuChi == 2)
            {
                if (cmpStr(q->data.ten, Min->data.ten) < 0)
                {
                    Min = q;
                }
            }
            if (tieuChi == 3)
            {
                if (q->data.diem < Min->data.diem)
                {
                    Min = q;
                }
            }
        }
        swap(p->data, Min->data);
    }
}

void selectionSortCircalLinked(LIST_VONG& ds, int tieuChi)
{
    pNODE_VONG p, q, Min;
    for (p = ds.pTail_Vong->pNext_Vong; p->pNext_Vong != ds.pTail_Vong->pNext_Vong; p = p->pNext_Vong)
    {
        Min = p;
        for (q = p->pNext_Vong; q != ds.pTail_Vong->pNext_Vong; q = q->pNext_Vong)
        {
            if (tieuChi == 1)
            {
                if (cmpStr(q->data.maSV, Min->data.maSV) < 0)
                {
                    Min = q;
                }
            }
            if (tieuChi == 2)
            {
                if (cmpStr(q->data.ten, Min->data.ten) < 0)
                {
                    Min = q;
                }
            }
            if (tieuChi == 3)
            {
                if (q->data.diem < Min->data.diem)
                {
                    Min = q;
                }
            }
        }
        swap(p->data, Min->data);
    }
}