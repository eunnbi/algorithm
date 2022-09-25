#include <bits/stdc++.h>
using namespace std;

int N;
int dp[1000001]; // dp[i] : i를 1로 만드는데 사용되는 연산의 개수의 최솟값

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	dp[1] = 0;
	for (int i = 2; i <= N; i++) {
		int num = dp[i - 1];
		if (!(i % 3)) {
			num = min(num, dp[i / 3]);
		}
		if (!(i % 2)) {
			num = min(num, dp[i / 2]);
		}
		dp[i] = num + 1;
	}
	cout << dp[N];
	return 0;
}

// https://www.acmicpc.net/problem/1463