#include <bits/stdc++.h>
using namespace std;

int n, m, k;
string board[1002];
bool vis[1002][1002][12];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
		cin >> board[i];
    
	queue<tuple<int, int, int, int, int>> Q;
	vis[0][0][0] = 1;
	Q.push({ 0, 0, 0, 0, 0 });
	while (!Q.empty()) {
		int x, y, w, t, cnt;
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
			if (board[nx][ny] == '0' and vis[nx][ny][w] == 0) {
				vis[nx][ny][w] = 1;
				Q.push({ nx, ny, w, nt, cnt + 1 });
			}
			if (board[nx][ny] == '1' and w < k and vis[nx][ny][w + 1] == 0) {
				if (t == 0) {
					vis[nx][ny][w + 1] = 1;
					Q.push({ nx, ny, w + 1, nt, cnt + 1 });
				}
				else {
					Q.push({ x, y, w, nt, cnt + 1 });
				}	
			}
		}
	}
	cout << -1;
	return 0;
}