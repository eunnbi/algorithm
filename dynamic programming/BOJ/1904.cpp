#include <bits/stdc++.h>
#define MOD 15746
using namespace std;

int N;
long long dp[1000001];


int main(void) {
    cin >> N;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= N; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }
    cout << dp[N] % MOD;
    return 0;
}