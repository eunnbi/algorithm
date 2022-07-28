#include <bits/stdc++.h>
#define MAX 100
#define SUCCESS 1
#define FAIL -1
using namespace std;

int N, M;
string board[12];
pair<int, int> red, blue; // 빨간 구슬, 파란 구슬 위치
 // dist[a][b][c][d] : 빨간 구슬이 (a, b)이고 파란 구슬이 (c, d)에 위치한 상황에 빠져나가기 위한 동작의 횟수
int dist[11][11][11][11];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };


int bfs() {
	queue<tuple<int, int, int, int>> Q;
	Q.push({ red.first, red.second, blue.first, blue.second });
	dist[red.first][red.second][blue.first][blue.second] = 0;
	while (!Q.empty()) {
		int rx, ry, bx, by;
		tie(rx, ry, bx, by) = Q.front();
		Q.pop();
		int cnt = dist[rx][ry][bx][by];
		if (cnt >= 10) return -1; // 10번 넘게 탈출 못하면 -1
		// 4 방향으로 기울이기
		for (int i = 0; i < 4; i++) {
			int nrx = rx, nry = ry, nbx = bx, nby = by;
			// Blue 이동
			while (board[nbx + dx[i]][nby + dy[i]] == '.') {
				nbx += dx[i];
				nby += dy[i];
			}
			// Blue가 탈출했다면 실패
			if (board[nbx + dx[i]][nby + dy[i]] == 'O') continue;

			// Red 이동
			while (board[nrx + dx[i]][nry + dy[i]] == '.') {
				nrx += dx[i];
				nry += dy[i];
			}
			// Red가 탈출했다면 종료
			if (board[nrx + dx[i]][nry + dy[i]] == 'O') return cnt + 1;

			// Red, Blue가 겹쳐진 경우 늦게 출발한 구슬을 한칸 뒤로 이동
			if ((nrx == nbx) && (nry == nby)) {
				if (i == 0)
					ry < by ? nry-- : nby--;
				else if (i == 1)
					rx < bx ? nrx-- : nbx--;
				else if (i == 2)
					ry > by ? nry++ : nby++;
				else
					rx > bx ? nrx++ : nbx++;
			}

			if (dist[nrx][nry][nbx][nby] != -1) continue;
			dist[nrx][nry][nbx][nby] = cnt + 1;
			Q.push({ nrx, nry, nbx, nby });
		}
	}
	return -1;
}




int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> board[i];
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 'B') {
				blue = { i, j };
				board[i][j] = '.';

			}
			else if (board[i][j] == 'R') {
				red = { i, j };
				board[i][j] = '.';
			}
		}
	}

	// 거리 배열 초기화
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				fill(dist[i][j][k], dist[i][j][k] + 10, -1);
			}	
		}
	}
	int res = bfs();
	printf("%d\n", res);
	return 0;
}

// ❣️ 빨간 구슬과 파란 구슬의 좌표를 가지고 4차원에서 BFS를 진행하면 된다.
// https://www.acmicpc.net/problem/13460