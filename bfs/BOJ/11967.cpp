#include <bits/stdc++.h>
using namespace std;

// **WRONG**
// 무한 루프 걸림
bool rooms[102][102]; // 방에 불이 켜져 있는지 여부를 저장하는 배열
vector<pair<int, int>> canVisit[1002][1002]; // 각 칸에서 불을 컬 수 있는 칸 좌표를 저장하는 배열
queue<pair<int, int>> Q;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int n, m;

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		canVisit[x - 1][y - 1].push_back({ a - 1, b - 1 });
	}

	rooms[0][0] = 1; // 시작점
	Q.push({ 0, 0 });
	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		for (pair<int, int> room : canVisit[cur.first][cur.second]) {
			rooms[room.first][room.second] = 1;
		}
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (!rooms[nx][ny]) continue;
			Q.push({ nx, ny });
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans += rooms[i][j];
		}
	}
	cout << ans;
	return 0;
}

/*
❤️ 위 코드의 문제점
- 이미 방문했던 방을 계속 방문하게 되면서 무한루프가 발생한다.
- 하지만 새로 불켜진 방을 방문하기 위해서는 이미 방문했던 방을 지나가야 하는 경우가 생긴다.

❤️ 해결방법
- 방문 기록을 저장하는 배열을 이용하여 이미 방문했던 방을 방문하지 않도록 하여 무한 루프가 발생하지 않도록 한다.
- 새롭게 불켜진 방에 대해서는 해당 방이 방문 가능한 곳인지 확인하고 방문이 가능하면 큐에 넣는다.
*/


// **CORRECT**
bool rooms[102][102]; // 방에 불이 켜져 있는지 여부를 저장하는 배열
bool vis[102][102]; // 방문 여부를 저장하는 배열
vector<pair<int, int>> canVisit[102][102]; // 각 칸에서 불을 컬 수 있는 칸 좌표를 저장하는 배열
int n, m;
queue<pair<int, int>> Q;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

// 새롭게 불켜진 방에 방문 가능한지 확인
bool is_conn(pair<int, int> nxt) {
	for (int dir = 0; dir < 4; dir++) {
		int nx = nxt.first + dx[dir];
		int ny = nxt.second + dy[dir];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (vis[nx][ny]) return 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		canVisit[x - 1][y - 1].push_back({ a - 1, b - 1 });
	}
	vis[0][0] = 1;
	rooms[0][0] = 1;
	Q.push({ 0, 0 });

	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		for (pair<int, int> room : canVisit[cur.first][cur.second]) {
			if (vis[room.first][room.second]) continue;
			if (is_conn(room)) {
				vis[room.first][room.second] = 1;
				Q.push({ room.first ,room.second });
			}
			rooms[room.first][room.second] = 1;

		}
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (vis[nx][ny] || rooms[nx][ny] == 0) continue;
			vis[nx][ny] = 1;
			Q.push({ nx, ny });
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans += rooms[i][j];
		}
	}
	cout << ans;
	return 0;
}