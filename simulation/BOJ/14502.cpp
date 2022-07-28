#include <bits/stdc++.h>
using namespace std;

int N, M;
int board1[10][10];
int board2[10][10];
int vis[10][10];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int num;


int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board1[i][j];
			if (board1[i][j] == 0) num++;
		}
	}
	int total = N * M;
	int wall[64] = { 0, };
	fill(wall + 3, wall + total, 1);
	int res = 0;
	do {
		int safe = num - 3;
		queue<pair<int, int>> Q;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				board2[i][j] = board1[i][j];
				vis[i][j] = 0;
				if (board1[i][j] == 2) {
					vis[i][j] = 1;
					Q.push({ i, j });
				}
			}
		}

		// 3개의 벽 세우기
		for (int i = 0; i < total; i++) {
			if (wall[i]) continue;
			int x = i / M;
			int y = i % M;
			board2[x][y] = 1;
		}

		while (!Q.empty()) {
			auto cur = Q.front(); Q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
				if (vis[nx][ny] || board2[nx][ny] == 1) continue;
				vis[nx][ny] = 1;
				safe--;
				Q.push({ nx, ny });
			}
		}
		if (res < safe) res = safe;

	} while (next_permutation(wall, wall + total));
	printf("%d\n", res);
	return 0;
}


// https://www.acmicpc.net/problem/14502