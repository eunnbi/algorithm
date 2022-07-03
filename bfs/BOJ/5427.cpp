#include <bits/stdc++.h>
using namespace std;

string board[1002];
int dist1[1002][1002]; // 불의 전파 시간
int dist2[1002][1002]; // 사람의 이동 시간
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };


int main() {
	int T;
	cin >> T;
	while (T--) {
		queue<pair<int, int>> Q1;
		queue<pair<int, int>> Q2;
		int w, h;
		cin >> w >> h;

		for (int i = 0; i < h; i++)
			cin >> board[i];

        // 여러 테스트 케이스가 존재하므로 공통으로 사용되는 dist1, dist2 배열 초기화 필수!!
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				dist1[i][j] = -1;
				dist2[i][j] = -1;
			}
		}

        // 시작점 큐에 넣기
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (board[i][j] == '*') { // 불
					dist1[i][j] = 0;
					Q1.push({ i, j });
				}
				if (board[i][j] == '@'){ // 사람
					dist2[i][j] = 0;
					Q2.push({ i, j });
				}
			}
		}


        // 불에 대한 BFS
		while (!Q1.empty()) {
			pair<int, int> cur = Q1.front();
			Q1.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if (dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
				dist1[nx][ny] = dist1[cur.first][cur.second] + 1;
				Q1.push({ nx, ny });
			}
		}

        // 사람에 대한 BFS
		bool escape = false;
		while (!Q2.empty()) {
			pair <int, int> cur = Q2.front();
			Q2.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
					cout << dist2[cur.first][cur.second] + 1 << '\n';
					escape = true;
					break;
				}
				if (dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;

                // 만약 이동하려는 칸에 불이 전파되었고 불의 전파시간이 더 작거나 같으면 그 칸에는 이동하지 못하므로 pass
				if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.first][cur.second] + 1) continue;

				dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
				Q2.push({ nx, ny });
			}
			if (escape) break; //추가된 코드 주의!!
		}
		if (!escape) {
			cout << "IMPOSSIBLE\n";
		}
	}
	return 0;
}

// https://www.acmicpc.net/problem/5427