#include <bits/stdc++.h>
using namespace std;

int board[1002][1002];
int dist[1002][1002]; // 0으로 초기화됨
int n, m;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	cin >> m >> n;

	queue<pair<int, int>> Q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) { // 시작점 큐에 넣기
				Q.push({ i, j });
			}
			if (board[i][j] == 0) {
				dist[i][j] = -1;
			}
		}
	}
	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist[nx][ny] >= 0 || board[nx][ny] == -1) continue;
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			Q.push({ nx, ny });
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] == -1) { // 해당 토마토 칸을 방문하지 못한 것 == 익지 않은 토마토 존재
				cout << -1;
				return 0;
			}
			ans = max(ans, dist[i][j]);
		}
	}
	cout << ans;
	return 0;
}

// 시작점이 여러 개 있을 때는 모든 시작점들을 큐에 넣고 BFS를 수행하면 된다.
// https://www.acmicpc.net/problem/7576