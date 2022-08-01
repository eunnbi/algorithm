#include <bits/stdc++.h>
using namespace std;

int N;
int dp[301]; // i번째 계단까지 올랐을 때 점수의 최대값
int score[301];

int main(void) {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> score[i];
	}
	dp[1] = score[1];
	if (N > 1) dp[2] = score[1] + score[2];
	if (N > 2) dp[3]= score[3] + max(score[1], score[2]);


	for (int i = 4; i <= N; i++) {
        // 계단을 3개 연속으로 밟으면 안된다는 조건!!!
		dp[i] = score[i] + max(dp[i - 2], dp[i - 3] + score[i - 1]);
	}
	printf("%d\n", dp[N]);
	return 0;
}

// https://www.acmicpc.net/problem/2579