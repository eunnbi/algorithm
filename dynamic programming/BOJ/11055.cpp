#include <bits/stdc++.h>
using namespace std;

int N;
int a[1001];
int dp[1001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}

	dp[1] = a[1];
	for (int i = 2; i <= N; i++) {
		dp[i] = a[i];
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i]) {
				dp[i] = max(dp[i], dp[j] + a[i]);
			}
		}
	}
	cout << *max_element(dp + 1, dp + N + 1);
	return 0;
}