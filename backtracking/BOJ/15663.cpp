#include <bits/stdc++.h>
using namespace std;

int N, M;
int nums[10];
int res[10];
int used[10];
int usedNum[10]; // 중복 수열 발생을 확인하기 위핸 배열

void sol(int i){
    if (i == M) {
        for (int j = 0; j < M; j++){
            printf("%d ", nums[res[j]]);
        }
        printf("\n");
        return;
    }

    for (int j = 0; j < N; j++){
        if (used[j]) continue;
        if (usedNum[i] == nums[j]) continue;
        used[j] = 1;
        res[i] = j;
        usedNum[i] = nums[j];
        sol(i + 1);
        used[j] = 0;
    }
    usedNum[i] = 0;
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

// https://www.acmicpc.net/problem/15663