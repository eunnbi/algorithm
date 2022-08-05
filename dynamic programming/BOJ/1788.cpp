#include <bits/stdc++.h>
#define BASE 1000000
#define MOD 1000000000
using namespace std;

int N;
long long dp[2000001][2];


int main(void) {
    cin >> N;
    dp[0 + BASE][0] = dp[0 + BASE][1] = 0;
    dp[1 + BASE][0] = dp[1 + BASE][1] = 1;
    if (N >= 0) {
        for (int i = 2; i <= N; i++) {
            dp[i + BASE][0] = (dp[i - 1 + BASE][0] + dp[i - 2 + BASE][0]) % MOD;
            dp[i + BASE][1] = 1;
        }   
    }
    else {
        for (int i = -1; i >= N; i--) {
            long long num1 = dp[i + 2 + BASE][0];
            long long num2 = dp[i + 1 + BASE][0];
            if (dp[i + 2 + BASE][1] == -1) {
                num1 = -num1;
            }
            if (dp[i + 1 + BASE][1] == -1) {
                num2 = -num2;
            }
            if (num1 > num2) {
                dp[i + BASE][1] = 1;
            }
            else if (num1 == num2) {
                dp[i + BASE][1] = 0;
            }
            else dp[i + BASE][1] = -1;
            dp[i + BASE][0] = abs(num1 - num2) % MOD;
        }
        
    }
    cout << dp[N + BASE][1] << '\n';
    cout << abs(dp[N + BASE][0]) % MOD;
    return 0;
}