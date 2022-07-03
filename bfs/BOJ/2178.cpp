#include <bits/stdc++.h>
using namespace std;

string board[102];
int dist[102][102]; // 시작점으로부터 거리를 저장하는 배열
int n, m;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> board[i];

    // dist 배열 초기화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist[i][j] = 0;
		}
	}
    
	queue<pair<int, int>> Q;
	Q.push({ 0, 0 });
	dist[0][0] = 1;
	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist[nx][ny] || board[nx][ny] == '0') continue;
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			Q.push({ nx, ny });
		}
	}
	cout << dist[n - 1][m - 1];
	return 0;
}

// https://www.acmicpc.net/problem/2178