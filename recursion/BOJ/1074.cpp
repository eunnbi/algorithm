#include <bits/stdc++.h>
using namespace std;


int sol(int n, int r, int c){
    if (n == 0) return 0;
    int half = 1 << (n - 1);
    if (r < half && c < half) return sol(n - 1, r, c);
    if (r < half && c >= half) return sol(n - 1, r, c - half) + half * half;
    if (r >= half && c < half) return sol(n - 1, r - half, c) + 2 * half * half;
    return sol(n - 1, r - half, c - half) + 3 * half * half;
}

int main(void){
    int n, r, c;
    cin >> n >> r >> c;
    cout << sol(n, r, c);
    return 0;
}

// https://www.acmicpc.net/problem/1074