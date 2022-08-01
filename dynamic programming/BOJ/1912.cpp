#include <bits/stdc++.h>
using namespace std;

int N;
int nums[100010];
int dp[100010];

int main(void) {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> nums[i];
		dp[i] = nums[i];
	}
	for (int i = 1; i <= N; i++) {
		dp[i] = max(dp[i], dp[i - 1] + nums[i]); // ✨ 점화식!!
	}
	cout << *max_element(dp + 1, dp + N + 1);
	return 0;
}

// https://www.acmicpc.net/problem/1912