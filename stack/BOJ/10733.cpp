#include <bits/stdc++.h>
using namespace std;

int main(void) {
	stack<int> S; // LIFO는 가장 최근 데이터를 가장 먼저 조회할 수 있는 것을 의미하기도 하다.
	int K;
	int total = 0;
	cin >> K;
	while (K--) {
		int number;
		cin >> number;
		if (number == 0) {
			S.pop();
		}
		else {
			S.push(number);
		}
	}
    
	while (!S.empty()) {
		total += S.top();
		S.pop();
	}
	cout << total;
	return 0;
}

// https://www.acmicpc.net/problem/10773