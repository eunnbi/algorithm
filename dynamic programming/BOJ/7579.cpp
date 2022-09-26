#include <bits/stdc++.h>
using namespace std;

int N, M;
int bite[101];
int cost[101];
int dp[101][10001]; // dp[i][j]: i번째 앱까지 탐색했을 때 비용 j로 확보할 수 있는 최대 메모리

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> bite[i];
	}

	int sum = 0;
	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
		sum += cost[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= sum; j++) {
			if ((j - cost[i]) >= 0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + bite[i]);
			}
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}

	int mn = sum;
	for (int i = 0; i <= sum; i++) {
		if (dp[N][i] >= M) mn = min(mn, i);
	}
	cout << mn;
	return 0;
}