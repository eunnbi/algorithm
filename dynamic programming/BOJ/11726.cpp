#include <bits/stdc++.h>
using namespace std;

int N;
int dp[1001]; // dp[i] : 2 x i 크기의 직사각형을 채우는 방법의 수

int main(void) {
	cin >> N;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= N; i++){
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007; // 마지막에 나누지 말고 중간중간에 나머지 연산
	}
	printf("%d\n", dp[N]);
	return 0;
}


// https://www.acmicpc.net/problem/11726