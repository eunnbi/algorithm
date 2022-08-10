#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int N;
int dp[MAX];

int main(void) {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        dp[i] = MAX;
        for (int j = 1; j * j <= i; j++) {
            if (dp[i] > dp[i - j * j] + 1) {
                dp[i] = dp[i - j * j] + 1;
            }
        }
    }
    cout << dp[N];
    return 0;
}