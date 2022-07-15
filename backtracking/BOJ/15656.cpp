#include <bits/stdc++.h>
using namespace std;

int N, M;
int nums[10];
int res[10];

void sol(int i){
    if (i == M){
        for (int j = 0; j < M; j++){
            printf("%d ", nums[res[j]]);
        }
        printf("\n");
        return;
    }

    for (int j = 0; j < N; j++){
        res[i] = j;
        sol(i + 1);
    }
}

int main(void){
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        cin >> nums[i];
    }
    sort(nums, nums + N);
    sol(0);
    return 0;    
}

// https://www.acmicpc.net/problem/15656