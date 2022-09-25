#include <bits/stdc++.h>
#define MOD 10007
using namespace std;

int N, K;
int dp[1001][1001];



int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		dp[i][0] = 1;
		dp[i][i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
		}
	}

	cout << dp[N][K];

	return 0;
}