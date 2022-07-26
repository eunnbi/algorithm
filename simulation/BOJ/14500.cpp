#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[502][502];
int t[4][4]; // 테트로미노
int x, y; // 테트로미노 시작좌표 ❣️

// 테트로미노를 오른쪽으로 90도 회전하는 함수
void rotate() {
	int tmp[4][4] = { 0, };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			tmp[i][j] = t[i][j];
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			t[i][j] = tmp[3 - j][i];
		}
	}
}


// 테트로미노 시작좌표 찾기
void findStart() {
	int startX = 5;
	int startY = 5;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (!t[i][j]) continue;
			if (startX > i) startX = i;
			if (startY > j) startY = j;
		}
	}
	x = startX;
	y = startY;
}


// 현재 테트로미노를 이용하여 얻을 수 있는 합의 최댓값 구하는 함수
int calculate() {
	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int sum = 0;
			for (int row = x; row < 4; row++) {
				for (int col = y; col < 4; col++) {
					if (!t[row][col]) continue;
                    // 인덱스 주의!! (시작 좌표만큼 빼주기) ❣️
					if ((row + i - x) >= N || (col + j - y) >= M) break; 
					sum += board[row + i - x][col + j - y];
				}
			}
			if (res < sum) res = sum;
		}
	}
	return res;
}



int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	int res = 0;
	for (int i = 0; i < 5; i++) {
		memset(t, 0, sizeof(t));
		x = y = 0; // 시작좌표 초기화
		if (i == 0) {
			t[0][0] = t[0][1] = t[0][2] = t[0][3] = 1;
			for (int j = 0; j < 2; j++) {
				int sum = calculate();
				if (res < sum) res = sum;
				if (j != 1) {
					rotate();
					findStart();
				}
			}
		}
		else if (i == 1) {
			t[0][0] = t[0][1] = t[1][0] = t[1][1] = 1;
			int sum = calculate();
			if (res < sum) res = sum;
		}
		else if (i == 2) {
			t[0][0] = t[1][0] = t[2][0] = t[2][1] = 1;
			for (int j = 0; j < 4; j++) {
				findStart();
				int sum = calculate();
				if (res < sum) res = sum;
				if (j != 3) {
					rotate();
					findStart();
				}
			}

			memset(t, 0, sizeof(t));
			t[0][1] = t[1][1] = t[2][0] = t[2][1] = 1;
			x = y = 0;
			for (int j = 0; j < 4; j++) {
				int sum = calculate();
				if (res < sum) res = sum;
				if (j != 3) {
					rotate();
					findStart();
				}
			}

		}
		else if (i == 3) {
			t[0][0] = t[1][0] = t[1][1] = t[2][1] = 1;
			for (int j = 0; j < 2; j++) {
				int sum = calculate();
				if (res < sum) res = sum;
				if (j != 1) {
					rotate();
					findStart();
				}
			}

			memset(t, 0, sizeof(t));
			t[0][1] = t[1][0] = t[1][1] = t[2][0] = 1;
			x = y = 0;
			for (int j = 0; j < 2; j++) {
				int sum = calculate();
				if (res < sum) res = sum;
				if (j != 1) {
					rotate();
					findStart();
				}
			}

		}
		else if (i == 4) {
			t[0][0] = t[0][1] = t[0][2] = t[1][1] = 1;
			for (int j = 0; j < 4; j++) {
				int sum = calculate();
				if (res < sum) res = sum;
				if (j != 3) {
					rotate();
					findStart();
				}
			}
		}
	}
	printf("%d\n", res);
	return 0;
}