#include <bits/stdc++.h>
using namespace std;

string board[1002];
int dist[1002][1002][2]; // 마지막 인덱스 1 => 벽을 부술 수 있다, 0 => 벽을 부술 수 없다
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M;

int bfs() {
	queue <tuple<int, int, int>> Q;
	Q.push({ 0, 0, 1 });
	dist[0][0][1] = 1; 
	while (!Q.empty()) {
		int x, y, block; // block = 0 or 1
		tie(x, y, block) = Q.front(); Q.pop();
		if (x == N - 1 && y == M - 1) return dist[x][y][block];
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

			// 벽이 아니고 방문한적이 없다면
			if (board[nx][ny] == '0' && dist[nx][ny][block] == 0) {
				dist[nx][ny][block] = dist[x][y][block] + 1;
				Q.push({ nx, ny, block });
			}
			
			// 벽인데 아직 벽을 부술 기회가 남아있고 방문한 적이 없다면
			if (block && board[nx][ny] == '1' && dist[nx][ny][block - 1] == 0) { //"block -1"!!
				dist[nx][ny][block - 1] = dist[x][y][block] + 1;
				Q.push({ nx, ny, block - 1 });
			}
		}
	}
	return -1;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> board[i];
	cout << bfs();
	return 0;
}
/*
💜 가중치가 없는 최단 경로를 구하기 위해 BFS를 이용한다.
💜 어떤 칸에 도달했을 때 나는 “벽을 부술 수 있는 상태”일 수도 있고, “벽을 부술 수 없는 상태”일 수도 있다. 
   그래서 이 문제는 BFS의 새로운 테크닉을 요구한다.
💜 좌표만을 큐에 넣어 탐색하는 방식을 넘어, “현재 상태” 자체를 큐에 넣어 문제를 풀어야 한다.  
    즉, “여기까지 오면서 벽을 부순 적이 있는가” 여부를 함께 큐에 넣어 저장한다.
💜 dist[x][y] → dist[x][y][벽을 부순 적이 있는가?]
*/

// https://www.acmicpc.net/problem/2206