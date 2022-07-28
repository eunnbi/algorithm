#include <bits/stdc++.h>
#define START 0
#define LINK 1
using namespace std;

int N;
int board[21][21];
int brute[21];
int res = 0x7f7f7f7f;

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	fill(brute + N / 2, brute + N, LINK);

	do {
		int sum[2] = { 0, };
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (brute[i] == brute[j]) {
					int team = brute[i];
					sum[team] += board[i][j] + board[j][i];
				}
			}
		}
		int val = abs(sum[0] - sum[1]);
		if (res > val) res = val;

	} while (next_permutation(brute, brute + N));
	printf("%d\n", res);
	return 0;
}

// https://www.acmicpc.net/problem/14889