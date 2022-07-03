#include <bits/stdc++.h>
using namespace std;

int dist[302][302];

// 기초 BFS에서 응용된 부분
int dx[8] = { 1, 1, -1,-1, 2,  2, -2, -2 };
int dy[8] = { 2, -2, 2, -2, 1, -1, 1, -1 };

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		int x, y;
		int rx, ry;
		cin >> n;  // 체스판 크기(n x n)
		cin >> x >> y; // 현재 있는 칸
		cin >> rx >> ry; // 이동하려고 하는 칸

        // dist 배열 초기화 필수!! (여러 테스트 케이스 존재)
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist[i][j] = -1;
			}
		}

		queue<pair<int, int>> Q;
		dist[x][y] = 0;  // 시작점
		Q.push({ x, y });
		while (dist[rx][ry] == -1) { // 이동하려는 칸에 방문하기 전 동안 bfs 수행
			pair <int, int> cur = Q.front();
			Q.pop();
			for (int dir = 0; dir < 8; dir++) {
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (dist[nx][ny] >= 0) continue;
				dist[nx][ny] = dist[cur.first][cur.second] + 1;
				Q.push({ nx, ny });
			}
		}
		cout << dist[rx][ry] << '\n';
	}
	return 0;
}

// https://www.acmicpc.net/problem/7562