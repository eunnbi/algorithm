#include <bits/stdc++.h>
using namespace std;

int T, N, M;
int coins[21];
int dp[10001];

int main(void) {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> coins[i];
        }
        
        cin >> M;
        dp[0] = 1;
        for (int i = 1; i <= M; i++) {
            dp[i] = 0;
        }
        for (int i = 0; i < N; i++) {
            for (int j = coins[i]; j <= M; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }
        cout << dp[M] << '\n';
    }
    return 0;
}