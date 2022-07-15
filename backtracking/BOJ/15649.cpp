#include <bits/stdc++.h>
using namespace std;

int N, M;
int res[10];
int used[10];

void sol(int i){
    if (i == M) {
        for (int i = 0; i < M; i++){
            cout << res[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int j = 1; j <= N; j++){
        if (used[j]) continue;
        used[j] = 1;
        res[i] = j;
        sol(i + 1);
        used[j] = 0;
    }
}

int main(void){
    cin >> N >> M;
    sol(0);
    return 0;
}

// https://www.acmicpc.net/problem/15649