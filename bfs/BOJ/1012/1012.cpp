#include <bits/stdc++.h>
using namespace std;

int board[52][52];
bool vis[52][52];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		int k, x, y;
		cin >> m >> n >> k;

		// 배열 초기화!!
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				board[i][j] = 0;
				vis[i][j] = 0;
			}
		}

		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			board[y][x] = 1;
		}


        // 시작점이 여러개인 BFS
		int num = 0;
		queue < pair<int, int>> Q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 0 || vis[i][j]) continue;
				num++;
				vis[i][j] = 1;
				Q.push({i, j});
				while (!Q.empty()) {
					pair<int, int> cur = Q.front();
					Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (vis[nx][ny] || board[nx][ny] == 0) continue;
						vis[nx][ny] = 1;
						Q.push({ nx, ny });
					}
				}
			}
		}
		cout << num << '\n';
	}
	return 0;
}
