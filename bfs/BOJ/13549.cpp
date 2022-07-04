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


/*
💡 문제의 핵심
- 자신의 위치가 X일 때  '1'초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 '0'초 후에 2X의 위치로 이동하게 된다.
- 순간이동 (0초 소요)은 걷는 이동(1초 소요) 보다 더 빠르기 때문에, "우선순위가 높다."

✔ BFS는 "모든 간선의 가중치가 동일"하다는 전제하의 "최단 경로*"를 구하기 때문에 단순한 BFS를 요구하는 문제가 아니다.

💡 0-1 BFS
- 가중치가 0과 1만 있는 그래프에서 최단 경로를 구하는 방법
- 'deque'를 이용하여 가중치가 0인 간선에 연결된 정점은 큐의 맨 뒤가 아닌 맨 앞에 넣는다.

💡 문제 해결
- 순간 이동을 할 경우 해당 좌표를 덱의 앞에 넣는다.
- 걷는 이동을 할 경우 해당 좌표를 덱의 뒤에 넣는다.
- 덱의 가장 앞쪽에 있는 좌표를 꺼내므로 순간이동의 우선순위를 높게 처리할 수 있다.
*/
// https://www.acmicpc.net/problem/13549