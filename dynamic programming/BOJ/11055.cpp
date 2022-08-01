#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int N;
int nums[MAX];
int dp[MAX];

int main(void) {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> nums[i];
		dp[i] = nums[i];
	}
	for (int i = 1; i <= N; i++) {
		int mx = dp[i];
		for (int j = 1; j < i; j++) {
			if (nums[i] <= nums[j]) continue;
			if (mx < dp[i] + dp[j]) {
				mx = dp[i] + dp[j];
			}
		}
		dp[i] = mx;
	}
	cout << *max_element(dp + 1, dp + N + 1);
	return 0;
}