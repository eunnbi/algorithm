#include <bits/stdc++.h>
using namespace std;

int board[102][102][102];
int dist[102][102][102];
int dx[6] = { 0, 1, 0, -1 , 0, 0};
int dy[6] = {1, 0, -1, 0, 0, 0};
int dz[6] = { 0, 0, 0, 0, 1, -1 }; // dz 추가

int m, n, h;
queue<tuple<int, int, int>> Q;

int main() {
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				int temp;
				cin >> temp;
				board[i][j][k] = temp;
				if (temp == 1) Q.push({ k, j, i }); // 익은 토마토 == 시작점
				if (temp == 0) dist[i][j][k] = -1; // 안 익은 토마토
			}
		}
	}

	while (!Q.empty()) {
		tuple<int, int, int> cur = Q.front();
		Q.pop();
		int curX, curY, curZ;
		tie(curX, curY, curZ) = cur;
		for (int dir = 0; dir < 6; dir++) {
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];
			int nz = curZ + dz[dir];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h) continue;
			if (dist[nz][ny][nx] >= 0) continue;
			dist[nz][ny][nx] = dist[curZ][curY][curX] + 1;
			Q.push({ nx, ny, nz });
		}
	}

	int ans = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (dist[i][j][k] == -1) {
					cout << -1 << "\n";
					return 0;
				}
				ans = max(ans, dist[i][j][k]);
			}
		}
	}
	cout << ans << '\n';
	return 0;
}


/*
🚀 3차원 배열로 확장
- tuple: 기존의 pair을 확장한 자료형이다.
- tie: pair, tuple로 묶인 값들을 여러 변수에 한 번에 받아올 수 있다.
*/

// https://www.acmicpc.net/problem/7569