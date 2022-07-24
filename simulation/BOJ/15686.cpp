#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[51][51];
vector<pair<int, int>> chicken;

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				chicken.push_back({ i, j });
			}
		}
	}
	int size = chicken.size();
	int mx = 1000000;
	int brute[15] = {}; // 0: 치킨 폐업 X, 1 : 치킨 폐업 O

	for (int num = 0; num <= M; num++) { // num : 폐업하지 않을 치킨집 개수
		// num 변수에 따라 brute 배열 초기화
		fill(brute, brute + num, 0);
		fill(brute + num, brute + size, 1);
		do {
			// 도시의 치킨 거리 구하기
			int res = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (board[i][j] != 1) continue;
					int value = 1000000; // 각 집의 치킨 거리 구하기
					for (int k = 0; k < size; k++) {
						if (brute[k]) continue;
						int x = chicken[k].first;
						int y = chicken[k].second;
						int tmp = abs(i - x) + abs(j - y);
						if (value > tmp) value = tmp;
					}
					res += value;
				}
			}
			if (mx > res) mx = res; // 최솟값 구하기

		} while (next_permutation(brute, brute + size)); // 조합 시도
	}
	printf("%d", mx);
	return 0;
}


// https://www.acmicpc.net/problem/15686