#include <bits/stdc++.h>
using namespace std;

int dist[200000];
int prePos[200000]; //인덱스 별로 그 전에 방문했던 인덱스 값 저장하는 배열

int n, k;
queue<int> Q;

int main() {
	cin >> n >> k;

	dist[n] = 1; // 시작점
	Q.push(n);
	while (!dist[k]) {
		int cur = Q.front(); Q.pop();
		for (int nxt : { cur - 1, cur + 1, 2 * cur}) {
			if (nxt < 0 || nxt > 100000) continue;
			if (dist[nxt]) continue;
			dist[nxt] = dist[cur] + 1;
			prePos[nxt] = cur;  // nxt를 방문하기 전에 cur 방문
			Q.push(nxt);
		}
	}
	cout << dist[k] - 1 << '\n';
	deque<int> track = { k };
	while (track.front() != n) {
		track.push_front(prePos[track.front()]); // 반드시 push_front!!
	}
	for (int p : track) cout << p << ' ';
	return 0;
}

// Backtracking!! => deque 이용
// https://www.acmicpc.net/problem/13913