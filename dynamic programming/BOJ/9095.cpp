#include <bits/stdc++.h>
using namespace std;

int T, N;
int dp[12];

int main(void) {
	cin >> T;

    // base case
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	while (T--) {
		cin >> N;
		for (int i = 4; i <= N; i++) {
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]; // 점화식
		}
		printf("%d\n", dp[N]); // answer case
	}
	return 0;
}

// https://www.acmicpc.net/problem/9095