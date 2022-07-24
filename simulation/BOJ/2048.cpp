#include <bits/stdc++.h>
using namespace std;

int N;
int board1[22][22];
int board2[22][22];

// 🙌 board2 배열을 시계 방향으로 90도 회전하는 함수
void rotate() { 
	int tmp[22][22] = { 0, };
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			tmp[i][j] = board2[i][j];
		}
			
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board2[i][j] = tmp[N - 1 - j][i];
		}
	}
}


// 🙌 왼쪽으로 게임판 기울이는 함수
void tilt(int dir) {
	while (dir--) rotate();
	for (int i = 0; i < N; i++) {
		int tilted[21] = { }; // 각 행은 독립적
		int idx = 0; // tilted 배열 원소의 위치를 가리킴. 가리키는 곳에 board2[i][j] 값 넣기
		for (int j = 0; j < N; j++) {
			if (board2[i][j] == 0) continue;
			if (tilted[idx] == 0) {
				tilted[idx] = board2[i][j];
			}
			else if (tilted[idx] == board2[i][j]) {
				tilted[idx++] *= 2;
			}
			else {
				tilted[++idx] = board2[i][j];
			}
		}
		for (int j = 0; j < N; j++) { board2[i][j] = tilted[j]; } // 덮어쓰기
	}
}

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board1[i][j];
		}
	}

	int mx = 0;
	for (int num = 0; num < 1024; num++) { // 4^5 = 1024 (전체 경우의 수)
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				board2[i][j] = board1[i][j];
			}
		}
		int brute = num;
		for (int i = 0; i < 5; i++) {
			int dir = brute % 4; // 4진법 이용하여 기울이는 방향 정하기 (0 ~ 3)
			brute /= 4;
			tilt(dir);
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (mx < board2[i][j]) mx = board2[i][j];
			}
		}
	}
	printf("%d\n", mx);
	return 0;
}

// https://www.acmicpc.net/problem/12100