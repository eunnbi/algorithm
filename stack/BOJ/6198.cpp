#include <bits/stdc++.h>
using namespace std;

int main(void) {
	stack<int> S;
	int N;
	
	long long res = 0; // Integer overflow 주의!!
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		while (!S.empty() && S.top() <= num) S.pop(); 
		res += S.size();
		S.push(num);
	}
	cout << res;
	return 0;
}

/*
💡 문제 재정의하기s
- 이 문제는 자신'이' 볼 수 있는 빌딩의 수의 총합을 구하는 것이다.
- 이를 다르게 생각하면 자신'을' 볼 수 있는 빌딩의 수의 총합을 구하면 된다.
- 그러면 자신을 볼 수 있는 빌딩은 자신보다 왼쪽에 있는 빌딩 중 자신보다 큰 빌딩이다.
- 스택에 숫자 X를 넣는다고 가정하면 X를 넣기 전에 X 이하의 수를 모두 제거하고 X를 넣는다.
*/

// https://www.acmicpc.net/problem/6198