#include <bits/stdc++.h>
#define MOD 10007
using namespace std;

int N;
long long dp[1001][10]; // 


int main(void) {
    ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
			}
		}
	}

	long long res = 0;
	for (int i = 0; i < 10; i++) {
		res += dp[N][i] % MOD;
	}
	cout << res % MOD;
	return 0;
}