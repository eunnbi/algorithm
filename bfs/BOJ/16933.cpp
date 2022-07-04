#include <bits/stdc++.h>
using namespace std;

int n, m, k;
string board[1002];
bool vis[1002][1002][12][2]; // 마지막 인덱스 -> 0 : 낮, 1 : 밤
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
		cin >> board[i];
    
	queue<tuple<int, int, int, int, int>> Q;
	vis[0][0][0][0] = 1;
	Q.push({ 0, 0, 0, 0, 0 });
	while (!Q.empty()) {
		int x, y; // 배열 좌표
        int w, t, cnt; // 각각 벽 부수기 능력 사용 수, 밤낮 여부, 이동 횟수
		tie(x, y, w, t, cnt) = Q.front(); Q.pop();

		if (x == n - 1 && y == m - 1) {
			cout << cnt + 1;
			return 0;
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			int nt = 1 - t; // 밤(1) -> 낮(0), 낮(0) -> 밤(1)
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == '0') { // 벽 X
				if (vis[nx][ny][w][nt]) continue; // 이미 방문
				vis[nx][ny][w][nt] = 1;
				Q.push({ nx, ny, w, nt, cnt + 1 });
			}
			else { // 벽 O
				if (w == k) continue; // 벽 부술 수 없음
				if (t == 0) { // 현재 낮 => 벽 부수기 가능
					if (vis[nx][ny][w + 1][nt]) continue; // 이미 방문
					vis[nx][ny][w + 1][nt] = 1;
					Q.push({ nx, ny, w + 1, nt, cnt + 1 });
				}
				else { // 밤이라면 낮이 올 때까지 현재 방문한 칸에서 기다리기 가능
					if (vis[x][y][w][nt]) continue;
					vis[x][y][w][nt] = 1;
					Q.push({ x, y, w, nt, cnt + 1 });
				}
			}		
		}
	}
	cout << -1;
	return 0;
}

/*
❣️ BFS를 수행할 때 큐에는 좌표뿐만 아니라 다양한 정보를 넣을 수 있다. 
   다만, 다음 칸을 방문할 때 큐에 넣은 정보들을 정확히 업데이트해야 한다.
*/

// https://www.acmicpc.net/problem/16933