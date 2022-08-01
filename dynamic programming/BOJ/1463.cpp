#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

int N;
int dp[MAX]; // dp[i] : i를 1로 만드는데 사용되는 연산의 개수의 최솟값

int main(void) {
	cin >> N;
	dp[0] = dp[1] = 0; // base case
	for (int i = 2; i <= N; i++) {
		int num = MAX;
		if (!(i % 3)) {
			int tmp = i / 3;
			if (num > dp[tmp] + 1) num = dp[tmp] + 1;
		}
		if (!(i % 2)) {
			int tmp = i / 2;
			if (num > dp[tmp] + 1) num = dp[tmp] + 1;

		}
		if (num > dp[i - 1] + 1) num = dp[i - 1] + 1;
		dp[i] = num;
	}
	printf("%d\n", dp[N]); // answer case
	return 0;
}

// https://www.acmicpc.net/problem/1463