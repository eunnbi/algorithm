#include <bits/stdc++.h>
using namespace std;

int N, M;
int res[10];


// 1. backtracking
void sol(int i){
    if (i == M){
        for (int j = 0; j < M; j++){
            printf("%d ", res[j]);
        }
        printf("\n");
        return;
    }

    int prev = i > 0 ? res[i - 1] : 0;
    for (int j = prev + 1; j <= N; j++){
        res[i] = j;
        sol(i + 1);
    }
}

int main(void){
    cin >> N >> M;
    sol(0);
    return 0;
}


// 2. next_permutation (combination)
int main(void){
    cin >> N >> M;

    for (int i = M + 1; i <= N; i++){
        res[i] = 1;
    }

    do {
        for (int i = 1; i <= N; i++) {
            if (!res[i]){
                printf("%d ", i);
            }
        }
        printf("\n");
    } while(next_permutation(res + 1, res + N + 1)); // 1-based indexing
    return 0;
}

// https://www.acmicpc.net/problem/15650