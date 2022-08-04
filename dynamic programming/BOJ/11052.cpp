#include <bits/stdc++.h>
using namespace std;

int N;
int p[1001];
int dp[1001]; // dp[i] : i개의 카드를 갖기 위해 지불해야 하는 금액의 최댓값


int main(void) {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> p[i];
        dp[i] = p[i];
    }
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            if (dp[i] < dp[i - j] + p[j]) {
                dp[i] = dp[i - j] + p[j];
            }
        }
    }
    cout << dp[N];
    return 0;
}