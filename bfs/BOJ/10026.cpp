#include <bits/stdc++.h>
using namespace std;

string board[102];
bool vis[102][102];
int n;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> board[i];

	int res1 = 0;
	int res2 = 0;

	// 적록색약이 아닌 사람 BFS
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j]) continue;
			res1++;
			queue<pair<int, int>> Q;
			vis[i][j] = 1;
			Q.push({ i, j });
			while (!Q.empty()) {
				auto cur = Q.front();
				Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (vis[nx][ny] || board[nx][ny] != board[i][j]) continue;
					vis[nx][ny] = 1;
					Q.push({ nx, ny });
				}
			}
		}
	}

	// 배열 초기화!!
	for (int i = 0; i < 102; i++) {
		for (int j = 0; j < 102; j++) {
			vis[i][j] = 0;
		}
	}
	
	// 적록색약인 사람 BFS
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j]) continue;
			res2++;
			queue<pair<int, int>> Q;
			vis[i][j] = 1;
			Q.push({ i, j });
			while (!Q.empty()) {
				auto cur = Q.front();
				Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (vis[nx][ny]) continue;

                    // 문제에 따른 조건 추가
                    if (board[i][j] == 'B' && board[nx][ny] != 'B') continue;
                    if (board[i][j] != 'B' && board[nx][ny] == 'B') continue;
                    
					vis[nx][ny] = 1;
					Q.push({ nx, ny });
				}
			}
		}
	}
	cout << res1 << ' ' << res2;
	return 0;
}

// https://www.acmicpc.net/problem/10026