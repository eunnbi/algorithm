#include <bits/stdc++.h>
using namespace std;

int n, k;
int coins[101];
int dp[10002]; // dp[i] : 동전을 사용하여 i원 가치를 얻는 경우의 수


int main(void) {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    // 순서만 다른 것을 없애는 것이 점화식 세우는 데 중요!!
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= k; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }
    cout << dp[k];
    return 0;
}

// https://www.acmicpc.net/problem/2293