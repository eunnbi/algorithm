#include <bits/stdc++.h>
#define MOD 1000000009
using namespace std;

int T;
long long dp[1000001];


int main(void) {
    cin >> T;
    int num;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    while (T--) {
        cin >> num;
        for (int i = 4; i <= num; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
        }
        cout << dp[num] % MOD << '\n';
    }   
    return 0;
}