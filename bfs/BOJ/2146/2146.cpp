#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N;
int board[102][102];
bool vis[102][102]; // 대륙을 분류하는 첫 번째 bfs에서 사용
int dist[102][102]; // 다리의 길이를 구하는 두 번째 bfs에서 사용

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

// 대륙별로 번호를 붙여 분류하기 (시작점이 여러 개인 BFS)
void island() {
	int label = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 0 || vis[i][j]) continue;
			queue<pair<int, int>> Q;
			vis[i][j] = 1;
			board[i][j] = label;
			Q.push({ i, j });
			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (vis[nx][ny] || board[nx][ny] == 0) continue;
					vis[nx][ny] = 1;
					board[nx][ny] = label;
					Q.push({ nx, ny });
				}
			}
			label++;
		}
	}
}


int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			dist[i][j] = -1;
		}
	}

	island();

    // 서로 다른 대륙 사이의 거리를 구하는 BFS
	queue<pair<int, int>> Q;
	for (int i = 0; i < N; i++) { // 시작점 큐에 넣기
		for (int j = 0; j < N; j++) { 
			if (board[i][j] != 0) {
				dist[i][j] = 0;
				Q.push({ i, j });
			}
		}
	}

	int res = 1000000;
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (board[nx][ny] == board[cur.X][cur.Y]) continue; // 같은 섬일 경우
			if (board[nx][ny] != 0) { // 다른 섬일 경우
				res = min(res, dist[nx][ny] + dist[cur.X][cur.Y]);
			}
			else { // 바다일 경우
				board[nx][ny] = board[cur.X][cur.Y]; // 대륙으로 확장
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				Q.push({ nx, ny });
			}
		}
	}
	cout << res;
	return 0;
}
