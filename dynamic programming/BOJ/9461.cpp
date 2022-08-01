#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int T, N;
long long dp[MAX]; // integer overflow 주의!!

int main(void) {
	cin >> T;
	dp[1] = dp[2] = dp[3] = 1;
	dp[4] = dp[5] = 2;
	while (T--) {
		cin >> N;
		for (int i = 6; i <= N; i++) {
			dp[i] = dp[i - 1] + dp[i - 5];
		}
		cout << dp[N] << '\n';
	}
	return 0;
}

// https://www.acmicpc.net/problem/9461