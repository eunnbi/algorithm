#include <bits/stdc++.h>
using namespace std;

bool canExtend[1002][1002];
int step[10];
int area[10];
int n, m, p;
queue<tuple<int, int, int>> Q[10]; // 각 플레이어들의 bfs를 위한 queue 배열!!!
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	cin >> n >> m >> p;
	for (int i = 1; i <= p; i++) // 1-based indexing
		cin >> step[i];

	// 게임판 상태에 따라 canExtend 배열 초기화
	// BFS 시작점 큐에 push
	char ch;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ch;
			if (ch == '.') canExtend[i][j] = 1;
			else if (ch == '#') canExtend[i][j] = 0;
			else {
				canExtend[i][j] = 0;
				Q[ch - '0'].push({ i, j, 0 });
				area[ch - '0']++;
			}
		}
	}
	
	while (true) {
		bool isExtend = false; // 게임 종료 여부를 알 수 있는 flag
		for (int i = 1; i <= p; i++) {
			queue<tuple<int, int, int>> nextQ; // 다음 턴 BFS를 위한 큐
			while (!Q[i].empty()) {
				int curX, curY, curStep;
				tie(curX, curY, curStep) = Q[i].front(); Q[i].pop();
				if (curStep >= step[i]) {
					nextQ.push({ curX, curY, 0 }); // 더 이상 움직일 수 없으므로 현재 좌표를 다음 bfs를 위해 push
					continue;
				}
				for (int dir = 0; dir < 4; dir++) {
					int nx = curX + dx[dir];
					int ny = curY + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (!canExtend[nx][ny]) continue;
					isExtend = true;
					canExtend[nx][ny] = 0;
					Q[i].push({ nx, ny, curStep + 1 });
					area[i]++;
				}
			}
			Q[i] = nextQ;
		}
		if (!isExtend) break;
	}
	for (int i = 1; i <= p; i++) {
		cout << area[i] << ' ';
	}
	return 0;
}

// https://www.acmicpc.net/problem/16920