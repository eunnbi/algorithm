#include <bits/stdc++.h>
using namespace std;

int N, M;
int r, c, d;
int board[51][51]; // 0: 빈칸, 1: 벽
int vis[51][51]; // 0 : 청소 X, 1: 청소 O
// 0: 북, 1: 동, 2 : 남, 3 : 서
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };


int main(void) {
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	queue<tuple<int, int, int, int>> Q;
	vis[r][c] = 1;
	Q.push({ r, c, d, 1 });
	bool isPossible = false;
	int res = 0;

	while (!Q.empty()) {
		int curX, curY, curD, cnt;
		tie(curX, curY, curD, cnt) = Q.front(); Q.pop();
		res = cnt;
		isPossible = false;
		int nextDir = curD;
		for (int i = 0; i < 4; i++) {
			nextDir = (nextDir - 1 + 4) % 4;
			int nx = curX + dx[nextDir];
			int ny = curY + dy[nextDir];
			if (board[nx][ny]) continue; // 벽
			if (vis[nx][ny]) continue; // 이미 청소
			isPossible = true;
			vis[nx][ny] = 1;
			Q.push({ nx, ny, nextDir, cnt + 1 });
			break;
		}
		if (!isPossible) {
			nextDir = (curD - 2 + 4) % 4;
			int nx = curX + dx[nextDir];
			int ny = curY + dy[nextDir];
			if (board[nx][ny]) continue;
			Q.push({ nx, ny, curD, cnt });
		}
	}
	printf("%d\n", res);
	return 0;
}