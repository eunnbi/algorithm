#include <bits/stdc++.h>
using namespace std;

int N;
int paper[130][130];
int cnt[2]; // 0 : 하얀색 색종이 개수, 1: 파란색 색종이 개수

bool check(int x, int y, int n){
    for (int i = x; i < x + n; i++){
        for (int j = y; j < y + n; j++){
            if (paper[x][y] != paper[i][j])
                return false;
        }
    }
    return true;
}


void sol(int x, int y, int n){
    if (check(x, y, n)) {
        cnt[paper[x][y]] += 1;
        return;
    }
    n /= 2;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            sol(x + i * n, y + j * n, n);
        }
    }
}

int main(void){
    cin >> N;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> paper[i][j];
        }
    }
    sol(0, 0, N);
    cout << cnt[0] << '\n' << cnt[1];
    return 0;
}