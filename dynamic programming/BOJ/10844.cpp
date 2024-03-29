#include <bits/stdc++.h>
#define MOD 1000000000
using namespace std;

int N;
long long dp[101][10];

int main(void) {
    ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	dp[1][0] = 0;
	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			dp[i][j] = ((j == 0 ? 0 : dp[i - 1][j - 1]) + (j == 9 ? 0 : dp[i - 1][j + 1])) % MOD;
		}
	}

	long long res = 0;
	for (int i = 0; i < 10; i++) {
		res += dp[N][i] % MOD;
	}
	cout << res % MOD;
	return 0;
}