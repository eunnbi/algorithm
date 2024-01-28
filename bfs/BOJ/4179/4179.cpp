#include <bits/stdc++.h>
using namespace std;

string board[1002];
int dist1[1002][1002]; // 불의 전파 시간
int dist2[1002][1002]; // 지훈이의 이동 시간
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

    // dist1, dist2 배열 초기화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist1[i][j] = -1;
			dist2[i][j] = -1;
		}
	}

	for (int i = 0; i < n; i++) cin >> board[i];

	queue<pair<int, int> > Q1;
	queue<pair<int, int> > Q2;

    // 시작점 큐에 넣기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'F') { // 불
				Q1.push({ i,j });
				dist1[i][j] = 0;
			}
			if (board[i][j] == 'J') { // 지훈
				Q2.push({ i,j });
				dist2[i][j] = 0;
			}
		}
	}
	
    // 먼저, 불의 BFS를 진행하여 전파시간을 구해 배열에 저장한다.
	while (!Q1.empty()) {
		pair<int, int> cur = Q1.front(); Q1.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			dist1[nx][ny] = dist1[cur.first][cur.second] + 1;
			Q1.push({ nx, ny });
		}
	}

    // 다음, 사람의 BFS를 진행한다.
	while (!Q2.empty()) {
		pair<int, int> cur = Q2.front(); Q2.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

            // 만약 배열의 범위를 벗어나면, 그것은 탈출에 성공했다는 의미이므로 탈출 시간을 출력하여 return한다.
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {  // 탈출 성공
				cout << dist2[cur.first][cur.second] + 1;
				return 0;
			}

			if (dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;

			// 불의 전파 시간 조건 추가
            // 만약 이동하려는 칸에 불이 전파되었고 불의 전파시간이 더 작거나 같으면 그 칸에는 이동하지 못하므로 pass
			if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.first][cur.second] + 1) continue;
			dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
			Q2.push({ nx, ny });
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}

/*
👉 시작점이 두 종류이면서 시작점이 여러 개인 경우

💛 문제 해결 방법
- 먼저, 불의 BFS를 진행하여 전파시간을 구해 배열에 저장한다.
- 다음, 사람의 BFS를 진행한다.
    - 만약 배열의 범위를 벗어나면, 그것은 탈출에 성공했다는 의미이므로 탈출 시간을 출력하여 return한다.
    - 만약 불의 전파시간이 더 작거나 같으면 그 칸에는 이동하지 못하므로 pass
⇒ 즉, 먼저 불의 BFS를 진행하여 불의 전파시간을 구해놓고 사람의 BFS를 진행할 때 그에 맞는 조건을 추가하면 된다.

❗생각해야 할 점
- 이 문제에서는 사람의 이동은 불의 전파에 영향을 받지만 불의 전파는 사람의 이동에 영향을 받지 않는다.  그래서 불의 BFS를 따로 수행할 수 있었다.
- 반면, 시작점이 A와 B 두 종류가 있고, A의 전파가 B에 영향을 주고, B의 전파가 A에 영향을 준다고 했을 때 위 방법으로는 이 문제를 해결할 수 없다. (BFS를 동시에 진행해야 함!)
*/
// https://www.acmicpc.net/problem/4179