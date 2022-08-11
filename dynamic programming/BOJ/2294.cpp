#include <bits/stdc++.h>
#define MAX 100000
using namespace std;

int n, k;
int coins[101];
int dp[10001]; // dp[i] : i원을 만들기 위해 사용해야 하는 동전의 최소 개수


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
        if (coins[i] <= k) dp[coins[i]] = 1;
    }

    for (int i = 1; i <= k; i++) {
        if (dp[i] == 1) continue;
        int mn = MAX;
        for (int j = 0; j < n; j++) {
            if (i - coins[j] < 0) continue;
            if (dp[i - coins[j]] == 0) continue; // 예외 상황 제외
            if (mn > dp[i - coins[j]] + 1) {
                mn = dp[i - coins[j]] + 1;
            }
        }
        if (mn == MAX) dp[i] = 0;
        else dp[i] = mn;
    }

    if (dp[k] == 0) cout << "-1";
    else cout << dp[k];
    return 0;
}

// https://www.acmicpc.net/problem/2294
