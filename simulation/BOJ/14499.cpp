#include <bits/stdc++.h>
using namespace std;

int N, M;
int x, y;
int K;
int board[22][22];
int cmd[1001];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int dice[6];

void roll(int dir) {
	int temp[6];
	for (int i = 0; i < 6; i++) temp[i] = dice[i];

	if (dir == 0) { // 동
		dice[0] = temp[3];
		dice[2] = temp[0];
		dice[3] = temp[5];
		dice[5] = temp[2];
	}
	else if (dir == 1) { // 서
		dice[0] = temp[2];
		dice[2] = temp[5];
		dice[3] = temp[0];
		dice[5] = temp[3];
	}
	else if (dir == 2) { // 북
		dice[0] = temp[4];
		dice[1] = temp[0];
		dice[4] = temp[5];
		dice[5] = temp[1];
	}
	else { // 남
		dice[0] = temp[1];
		dice[1] = temp[5];
		dice[4] = temp[0];
		dice[5] = temp[4];
	}
}

int main(void) {
	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		cin >> cmd[i]; // 1 ~ 4 (동, 서, 북, 남)
	}

	int curX = x;
	int curY = y;
	for (int i = 0; i < K; i++) {
		int dir = cmd[i];
		int nx = curX + dx[dir - 1];
		int ny = curY + dy[dir - 1];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
		curX = nx;
		curY = ny;
		roll(dir - 1);
		if (board[curX][curY] == 0) {
			board[curX][curY] = dice[5];
		}
		else {
			dice[5] = board[curX][curY];
			board[curX][curY] = 0;
		}
		printf("%d\n", dice[0]);
		
	}
	return 0;
}