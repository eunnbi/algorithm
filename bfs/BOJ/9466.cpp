#include <bits/stdc++.h>
using namespace std;

int arr[100002]; // 각 정점이 가리키는 대상
int state[100002]; // 정점의 상태 정보 
const int NOT_VISITED = 0; // 방문하지 앟은 상태
const int CYCLED_IN = -1; // 사이클에 포함된 상태

void run(int i) {
	int cur = i; // 시작점의 인덱스
	while (true) {
		state[cur] = i; // 이번에 방문한 정점임을 표시
		cur = arr[cur];

		// 이번에 방문한 정점에 도달했을 경우 => 즉 사이클 발견
		if (state[cur] == i) {
            // state 배열 값을 CYCLED_IN으로 변경
			while (state[cur] != CYCLED_IN) {
				state[cur] = CYCLED_IN;
				cur = arr[cur];
			}
			return;
		}

		// 이미 이전에 방문했던 정점에 도달했을 경우
		else if (state[cur] != NOT_VISITED) return;
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n; // 정점 개수
		cin >> n;
		fill(state + 1, state + n + 1, 0); // state 배열 초기화 (1-based indexing)

		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			if (arr[i] == i) state[i] = CYCLED_IN; // 자기 자신 선택한 경우
		}

		for (int i = 1; i <= n; i++) {
			if (state[i] == NOT_VISITED) run(i); // 아직 방문하지 않은 정점에 대해 run 함수 실행
		}


        // 사이클에 포함되지 않은 정점 개수 세기
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (state[i] != CYCLED_IN) cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}
/*
💡 문제 파악 => 방향 그래프에서 사이클에 포함되지 않는 정점의 개수를 구하는 문제이다.
1. 사이클을 어떻게 발견하는가?
    - 현재 진행되고 있는 탐색에서 지나간 정점에 도달했을 때 사이클이 형성된다.
    - 🚀 이때 이전에 방문했던 정점과 현재 진행되고 있는 탐색에서 방문했던 정점을 구분해야 한다.
2. 정점의 상태 구분
    - 방문하지 않은 정점 => !방문하지 않은 정점 == 이미 방문한 정점
    - 사이클에 포함된 정점 => !사이클에 포함된 정점 == 사이클에 포함되지 않은 정점


💜 정점의 방문 상태를 체크할 뿐만 아니라 사이클 포함 여부에 대한 정보도 같이 저장하는 배열을 이용해야 한다.
*/


// https://www.acmicpc.net/problem/9466