#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <iostream>
#include <vector>
#include <chrono>
#include <windows.h>
#define max 100
using namespace std;
using namespace std::chrono;

struct node {
    int row;
    int col;
};

int n;
int banCo[max][max] = {0};
vector<node> mov;
int a[8] = {2,  1, -1,-2, -2, -1, 1,  2};
int b[8] = {1,  2,  2, 1, -1,  -2,-2, -1};

//kiem tra vi tri bat dau co hop le khong
void check(int &row, int &col) {
    while (row < 0 || row >= n || col < 0 || col >= n) {
        cout << "Vị trí bắt đầu không hợp lệ\n";
        cout << "Nhập lại hàng: ";
        cin >> row;
        cout << "Nhập lại cột: ";
        cin >> col;
    }
    mov.push_back({row, col});
}

void show() {
    int k = 1;
    for (const auto &m: mov) 
    {
        cout << k++ << ": (" << m.row << ", " << m.col << ")\n";
    }
}

void Try(int n, int row, int col) {

    auto start_processing_time = high_resolution_clock::now();

    banCo[row][col] = 1;
    int count = 1;
    while (count < n*n) {
        int next_row = -1, next_col = -1;
        int min = 3200;
        for (int i = 0; i < 8; ++i) {
             
            int new_row = a[i] + row;
            int new_col = b[i] + col;

            if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < n && banCo[new_row][new_col] == 0) {
                //đếm xem ô mới này có bao nhiêu nước đi 
                int c = 0;
                for (int j = 0; j < 8; j++) {
                    int u = new_row + a[j];
                    int v = new_col + b[j];
                    if(u >= 0 && u < n && v >= 0 && v < n && banCo[u][v] == 0) c++;
                }
                //nếu ô nào có ít nước đi kế tiếp nhất sẽ chọn ô đó
                if (c < min) {
                    min = c;
                    next_row = new_row;
                    next_col = new_col;
                }
            }
        }
        //nếu có thể đi tiếp thì đẩy ô tiếp theo đó vào
        if (next_row >= 0 && next_col >= 0) {
            row = next_row;
            col = next_col;
            mov.push_back({row, col});
            banCo[row][col] = 1;
            ++count;
        }
        else break;

    }
    if (count == n*n) {
        show();
    }
    else cout << "\nKhông thể đi hết bàn cờ\n";
    
    auto end_processing_time = high_resolution_clock::now();
    auto processing_duration = duration_cast<milliseconds>(end_processing_time - start_processing_time);
    cout << "Time: " << processing_duration.count() << " milliseconds" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    SetConsoleOutputCP(CP_UTF8);
    cout << "Nhập kích thước bàn cờ: ";
    cin >> n;
    int row, col;
    cout << "Nhập hàng bắt đầu: ";
    cin >> row;
    cout << "Nhập cột bắt đầu: ";
    cin >> col;
    check(row, col);
    Try(n, row, col);
    system("pause");
}