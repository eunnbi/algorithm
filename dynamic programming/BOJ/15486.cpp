#include <bits/stdc++.h>
#define MAX 1500001
using namespace std;

int N;
int t[MAX];
int p[MAX];
int dp[MAX]; // i번째 일에 상담을 시작했을 때 얻을 수 있는 최대 수익

int main(void) {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> t[i] >> p[i];
	}
	int res = 0;
	for (int i = N; i >= 1; i--) {
		if (i + t[i] <= N + 1) { // i번째 일에 상담을 할 수 있을 경우
			// i번째 일에 상담을 했을 때와 상담을 하지 않았을 때 얻을 수 있는 수익 중 최대 수익을 취함
			dp[i] = max(dp[i + t[i]] + p[i], dp[i + 1]);
		}
		else dp[i] = dp[i + 1];
	}
	cout << *max_element(dp + 1, dp + N + 1);
	return 0;
}