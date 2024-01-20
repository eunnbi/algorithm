#include <bits/stdc++.h>
using namespace std;

int dist[100002];
int N, K; // 0 ≤ N, K ≤ 100,000

int main() {
	cin >> N >> K;
    memset(dist, -1, sizeof(dist));
    queue<int> Q;
	dist[N] = 0; // 시작점
	Q.push(N);
	
	while (dist[K] == -1) { // 동생의 위치에 방문할 때까지 반복
		int cur = Q.front(); Q.pop();

        // 자신의 위치(X)를 기준으로 X + 1, X - 1, 2 * X 위치를 탐색하면 된다,
		for (int nxt : {cur - 1, cur + 1, 2 * cur}) {
			if (nxt < 0 || nxt > 100000) continue; // 범위 벗어남
			if (dist[nxt] != -1) continue; // 이미 방문
			dist[nxt] = dist[cur] + 1;
			Q.push(nxt);
		}
	}
	cout << dist[K];
	return 0;
}
