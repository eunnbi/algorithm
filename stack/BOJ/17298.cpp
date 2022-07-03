#include<bits/stdc++.h>
using namespace std;


int N; // 1 ≤ N ≤ 1,000,000
int seq[1000001];
int res[1000001];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) // 수열 입력받기
		cin >> seq[i];
    
	stack<int> s;
	for (int i = N - 1; i >= 0; i--){
		while (!s.empty() && s.top() <= seq[i])
			s.pop();

		if (s.empty()) res[i] = -1;
		else res[i] = s.top();

		s.push(seq[i]);
	}
	
	// 정답 출력
	for (int i = 0; i < N; i++)
		cout << res[i] << " ";
}

/*
💡 문제 파악
- 자신의 오른쪽에 있는 수 중 자신보다 높고 가장 가까이에 있는 수를 찾는 문제이다. 
- 탑 문제와 비슷한 문제이다. (2493)
- 탑 문제와 달리 오른쪽 수 중에서 정답을 찾는 것이므로 수열의 마지막 수부터 스택에 넣는다.
*/

// https://www.acmicpc.net/problem/17298