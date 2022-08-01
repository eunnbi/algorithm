#include <bits/stdc++.h>
using namespace std;

int N;
// dp[i][0] : i번째 집까지 칠할 때 드는 비용의 최솟값 (i번째 집은 빨강)
// dp[i][1] : i번째 집까지 칠할 때 드는 비용의 최솟값 (i번째 집은 초록)
// dp[i][2] : i번째 집까지 칠할 때 드는 비용의 최솟값 (i번째 집은 파랑)
int dp[1001][3]; 
int cost[1001][3]; // 0 : R, 1 : G, 2 : B

int main(void) {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> cost[i][j];
		}
	}
	dp[1][0] = cost[1][0];
	dp[1][1] = cost[1][1];
	dp[1][2] = cost[1][2];

	for (int i = 2; i <= N; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
	}
	printf("%d\n", min({ dp[N][0], dp[N][1], dp[N][2] }));
	return 0;
}

// https://www.acmicpc.net/problem/1149