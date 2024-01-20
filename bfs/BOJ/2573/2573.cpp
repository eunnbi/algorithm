#include <bits/stdc++.h>
using namespace std;

int board[302][302];
bool vis[302][302];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M;

int main(void) {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	
	int year = -1;
	while (true) {
		year++; // 연도 증가
		int num = 0; // 방산 개수
		
		// vis 배열 초기화 겸 빙하가 전부 녹았는지 확인
		bool check = true;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				vis[i][j] = 0;
				if (board[i][j] != 0) check = false;
			}
		}

		// 만약 빙하가 전부 녹았으면 (board값이 전부 0이면)
		if (check) {
			cout << 0;
			break;
		}

		// BFS 수행하여 빙산의 개수 구하기
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] == 0 || vis[i][j]) continue;
				num++;
				queue<pair<int, int>> Q;
				vis[i][j] = 1; // 시작점
				Q.push({ i, j });
				while (!Q.empty()) {
					pair<int, int> cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];
						if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
						if (vis[nx][ny]) continue;
						if (board[nx][ny] == 0) {
                            // 양수인지 확인하고 빙산 녹이기
							if (board[cur.first][cur.second] > 0) board[cur.first][cur.second]--;
							continue;
						}
						vis[nx][ny] = 1;
						Q.push({ nx, ny });
					}
				}
			}
		} 
		if (num >= 2) {  // 빙산이 2개 이상이면
			cout << year;
			break;
		}
	}
	return 0;
}

// https://www.acmicpc.net/problem/2573