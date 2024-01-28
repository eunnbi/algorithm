#include <bits/stdc++.h>
using namespace std;

int n, k;
int dist[200002];

int main() {
	cin >> n >> k;
	int MX = 200000;
	fill(dist, dist + MX, -1);
	deque<int> dq; // 0-1 BFS => deque 이용
	dq.push_back(n); // 시작점
	dist[n] = 0;
	while (!dq.empty()) {
		int cur = dq.front(); dq.pop_front(); // 덱의 맨 앞에 위치한 좌표 꺼냄

        // 순간 이동 (가중치 0)
		if (2 * cur <= MX && dist[2 * cur] == -1) { // 인덱스 범위와 방문 여부 체크
			dist[2 * cur] = dist[cur]; // 0초
			dq.push_front(2 * cur); // 덱의 맨 앞에 넣는다.
		}
		for (int nxt : {cur - 1, cur + 1}) { // 걷는 이동 (가중치 1)
			if (nxt < 0 || nxt > MX) continue; // 인덱스 범위 체크
			if (dist[nxt] != -1) continue; // 방문 여부 체크
			dist[nxt] = dist[cur] + 1; // 1초
			dq.push_back(nxt); // 덱의 맨 뒤에 넣는다.
		}
	}
	cout << dist[k];
	return 0;
}
