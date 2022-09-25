#include <bits/stdc++.h>
using namespace std;

int T, N;
int stickers[2][100003];
int dp[2][100003];
// dp[i][j]: i행 j열 스티커를 붙일 때 스티커 점수의 최대값
// dp[0][j] = max({ dp[1][j - 1], dp[0][j - 2], dp[1][j - 2] }) + stickers[0][j];
// dp[1][j] = max({ dp[0][j - 1], dp[0][j - 2], dp[1][j - 2] }) + stickers[1][j];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < 2; i++) {
			for (int j = 2; j < N + 2; j++) {
				cin >> stickers[i][j];
				dp[i][j] = 0;
			}
		}

		for (int i = 2; i < N + 2; i++) {
			dp[0][i] = max({ dp[1][i - 1], dp[0][i - 2], dp[1][i - 2] }) + stickers[0][i];
			dp[1][i] = max({ dp[0][i - 1], dp[0][i - 2], dp[1][i - 2] }) + stickers[1][i];
		}

		cout << max(dp[0][N + 1], dp[1][N + 1]) << '\n';
	}
	return 0;
}