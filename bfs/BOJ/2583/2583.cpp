#include <bits/stdc++.h>
using namespace std;

int board[102][102];
bool vis[102][102]; // 방문 여부 체크하는 배열
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int m, n, k;

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j < x2; j++) {
			for (int k = y1; k < y2; k++) {
				board[k][j] = 1;
			}
		}
	}

    // 시작점이 여러개인 BFS
	int num = 0;
	vector<int> area;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1 || vis[i][j]) continue;
			num++;
			queue<pair<int, int>> Q;
			vis[i][j] = 1;  // 시작점 찾았다!
			Q.push({ i, j });
			int res = 0;
			while (!Q.empty()) {
				pair <int, int> cur = Q.front();
				Q.pop();
				res++;
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (vis[nx][ny] || board[nx][ny] == 1) continue;
					vis[nx][ny] = 1;
					Q.push({nx, ny});
				}
			}
			area.push_back(res);
		}
	}
	sort(area.begin(), area.end());
	cout << num << '\n';
	for (int i : area) cout << i << ' ';
	return 0;
}


// https://www.acmicpc.net/problem/2583