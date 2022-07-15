#include <bits/stdc++.h>
using namespace std;

int N;
int col[15];
int d1[35];
int d2[35];
int cnt = 0;


void sol(int i){
    if (i == N) {
        cnt++;
        return;
    }
    for (int j = 0; j < N; j++){
        if (col[j] || d1[i + j] || d2[i - j + N]) continue;
        col[j] = d1[i + j] = d2[i - j + N] = 1;
        sol(i + 1);
        col[j] = d1[i + j] = d2[i - j + N] = 0;
    }
}

int main(void){
    cin >> N;
    sol(0);
    cout << cnt;
    return 0;
}

// https://www.acmicpc.net/problem/9663