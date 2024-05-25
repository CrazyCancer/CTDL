// Lua chon kieu sap xep
int selectArrangeType(string s)
{
	regex pattern("[1-6]");
	while (!regex_match(s, pattern))
	{
		cout << "Vui long nhap lai (lua chon kieu sap xep tu 1->6)\n";
		getline(cin, s);
	}
	return stoi(s);
}

// Lua chon tieu chi sap xep
int selectCriterion(string s)
{
	regex pattern("[1-3]");
	while (!regex_match(s, pattern))
	{
		cout << "Vui long nhap lai (lua chon tieu chi sap xep tu 1->3)\n";
		getline(cin, s);
	}
	return stoi(s);
}

void printSortMenu(int &arrangeType, int& tieuChi)
{
	cout << "\n\n\t\t=== SAP XEP SINH VIEN BANG DANH SACH MANG ===\n\n";
    cout << "\tChon kieu sap xep: ";
    cout << "\n\t   1. BubbleSort";
    cout << "\n\t   2. QuickSort";
    cout << "\n\t   3. HeapSort";
    cout << "\n\t   4. MergeSort";
    cout << "\n\t   5. InsertionSort";
    cout << "\n\t   6. SelectionSort";

	string s;

    getline(cin,s);
    arrangeType = selectArrangeType(s);

    cout << "\tChon tieu chi sap xep: ";
    cout << "\n\t   1. Sap xep theo MSSV";
    cout << "\n\t   2. Sap xep theo ten";
    cout << "\n\t   3. Sap xep theo diem";
    getline(cin, s);
	tieuChi = selectCriterion(s);
}