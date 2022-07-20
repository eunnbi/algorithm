#include <bits/stdc++.h>
using namespace std;

int nums[15];
int res[6];
int k;

void sol(int i) {
    if (i == 6) {
        for (int j = 0; j < 6; j++){
            printf("%d ", nums[res[j]]);
        }
        printf("\n");
        return;
    }
    int prev = i > 0 ? res[i - 1] + 1 : 0;
    for (int j = prev; j < k; j++){
        res[i] = j;
        sol(i + 1);
    }
}

int main(void){
    while (true){
        cin >> k;
        if (k == 0) break;
        for (int i = 0; i < k; i++){
            cin >> nums[i];
        }
         sol(0);
         printf("\n");
    }
    return 0;
}

// https://www.acmicpc.net/problem/6603