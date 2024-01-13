#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<int> Q;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string order;
		cin >> order;
		if (order == "push") {
			int X;
			cin >> X;
			Q.push(X);
		}
		else if (order == "pop") {
			if (Q.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << Q.front() << '\n';
				Q.pop();
			}
		}
		else if (order == "size") {
			cout << Q.size() << '\n';
		}
		else if (order == "empty") {
			cout << Q.empty() << '\n';
		}
		else if (order == "front") {
			if (Q.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << Q.front() << '\n';
			}
		}
		else {
			if (Q.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << Q.back() << '\n';
			}
		}
	}
}

/*
💙 STL queue member function
- front(): queue의 첫번째 원소 반환. queue가 비어있다면 오류 발생
- back(): queue의 마지막 원소 반환. queue가 비어있다면 오류 발생
- empty(): queue가 비어있다면 true 반환, 아니면 false 반환
- size(): queue의 사이즈 반환
- push(value): queue의 맨 뒤에 데이터 삽입
- pop(): queue의 맨 앞의 데이터 삭제. 이때 삭제된 데이터를 반환하지 않음. return type이 void이므로 맨 앞의 원소를 참조하려면 front 이용
*/

// https://www.acmicpc.net/problem/10845