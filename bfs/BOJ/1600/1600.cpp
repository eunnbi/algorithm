#include <bits/stdc++.h>
using namespace std;

int board[202][202];
bool vis[202][202][32];

int dmx[4] = { 1, 0, -1, 0 };
int dmy[4] = { 0, 1, 0, -1 };
int dkx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dky[8] = { 1, -1, 2, -2, 2, -2, 1, -1 };

queue<tuple<int, int, int, int>> Q;
int k, w, h;

int main() {
	cin >> k >> w >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++){
			cin >> board[i][j];
		}
	}

    // 시작점
	Q.push({0 ,0, 0, 0});
	vis[0][0][0] = 1;
	while (!Q.empty()) {
		int curX, curY; // 좌표
        int curK, cnt; // 각각 능력 사용 횟수, 동작 수
		tie(curX, curY, curK, cnt) = Q.front(); Q.pop();

		if (curX == h - 1 && curY == w - 1) { // 도착!
			cout << cnt;
			return 0;
		}

        // 능력 사용 가능한 경우
		if (curK < k) {
			for (int dir = 0; dir < 8; dir++) {
				int nx = curX + dkx[dir];
				int ny = curY + dky[dir];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if (board[nx][ny]) continue;
				if (vis[nx][ny][curK + 1]) continue;
				vis[nx][ny][curK + 1] = 1;
				Q.push({ nx, ny, curK + 1, cnt + 1 });
			}
		}

        // else X (능력 사용 가능해도 사용하지 않는 경우도 포함해야 함.)
		for (int dir = 0; dir < 4; dir++) {
			int nx = curX + dmx[dir];
			int ny = curY + dmy[dir];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (board[nx][ny]) continue;
			if (vis[nx][ny][curK]) continue;
			vis[nx][ny][curK] = 1;
			Q.push({ nx, ny, curK, cnt + 1 });
		}
	}
	cout << -1;
	return 0;
}

// 💜 “벽 부수고 이동하기” 문제와 비슷한 유형이다. (2206)
// 💜 말처럼 이동한 횟수를 큐에 넣어 각 칸을 방문할 때마다 현재 원숭이가 말처럼 방문할 수 있는지 체크해야 한다.
// https://www.acmicpc.net/problem/1600