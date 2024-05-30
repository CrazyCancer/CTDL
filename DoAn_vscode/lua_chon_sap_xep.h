// Lua chon kieu sap xep
int selectArrangeType(string s)
{
	regex pattern("[1-6]");
	while (!regex_match(s, pattern))
	{
		cout << "Vui lòng nhập lại (lựa chọn kiểu sắp xếp từ 1->6)\n";
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
		cout << "Vui lòng nhập lại (lựa chọn kiểu sắp xếp từ 1->3)\n";
		getline(cin, s);
	}
	return stoi(s);
}

void printSortMenu(int &arrangeType, int& tieuChi)
{
	cout << "\n\n\t\t=== SẮP XẾP SINH VIÊN ===\n\n";
    cout << "\tChọn kiểu sắp xếp: ";
    cout << "\n\t   1. BubbleSort";
    cout << "\n\t   2. QuickSort";
    cout << "\n\t   3. HeapSort";
    cout << "\n\t   4. MergeSort";
    cout << "\n\t   5. InsertionSort";
    cout << "\n\t   6. SelectionSort\n";
	cout << "\n\t   Nhập lựa chọn: ";

	string s;

    getline(cin,s);
    arrangeType = selectArrangeType(s);

    cout << "\n\tChọn tiêu chí sắp xếp: ";
    cout << "\n\t   1. Sắp xếp theo MSSV";
    cout << "\n\t   2. Sắp xếp theo tên";
    cout << "\n\t   3. Sắp xếp theo điểm\n";
	cout << "\n\t   Nhập lựa chọn: ";

    getline(cin, s);
	tieuChi = selectCriterion(s);
}