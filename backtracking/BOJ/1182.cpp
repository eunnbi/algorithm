#include <bits/stdc++.h>
using namespace std;


int N, S;
int nums[22];
int cnt = 0;

void sol(int i, int total){
    if (i == N){
        if (total == S) cnt++;
        return;
    }
    sol(i + 1, total);
    sol(i + 1, total + nums[i]);
}


int main(void){
    cin >> N >> S;
    for (int i = 0; i < N; i++){
        cin >> nums[i];
    }
    sol(0, 0);
    if (S == 0) cnt -= 1; // 빈 수열일 때 더해진 cnt값 빼기!! (문제 조건이 있음.)
    cout << cnt << '\n';
    return 0;
}


// https://www.acmicpc.net/problem/1182