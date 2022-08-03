#include <bits/stdc++.h>
using namespace std;

int N;
int nums[10001];
int dp[10001]; // i번째 잔까지 봤을 때 최대로 먹을 수 있는 포도주 양


int main(void) {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> nums[i];
    }
    dp[1] = nums[1];
    dp[2] = nums[1] + nums[2];

    for (int i = 3; i <= N; i++) {
        // i번째 잔을 먹지 않는 경우도 고려!
        dp[i] = max({ dp[i - 1], dp[i - 2] + nums[i], dp[i - 3] + nums[i - 1] + nums[i] }); 
    }
    cout << dp[N] << '\n';
    return 0;
}


// https://www.acmicpc.net/problem/2156