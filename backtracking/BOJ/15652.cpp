#include <bits/stdc++.h>
using namespace std;

int N, M;
int res[10];

void sol(int i){
    if (i == M){
        for (int j = 0; j < M; j++){
            printf("%d ", res[j]);
        }
        printf("\n");
        return;
    }

    int prev = i > 0 ? res[i - 1] : 1;
    for (int j = prev; j <= N; j++){
        res[i] = j;
        sol(i + 1);
    }
}

int main(void){
    cin >> N >> M;
    sol(0);
    return 0;
}

// https://www.acmicpc.net/problem/15652