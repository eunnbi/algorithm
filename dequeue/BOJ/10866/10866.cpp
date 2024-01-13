#include <bits/stdc++.h>
using namespace std;

int main(void) {
	deque<int> DQ;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string order;
		cin >> order;
		if (order == "push_back") {
			int X;
			cin >> X;
			DQ.push_back(X);
			continue;
		}
		else if (order == "push_front") {
			int X;
			cin >> X;
			DQ.push_front(X);
			continue;
		}
		else if (order == "pop_front") {
			if (DQ.empty()) {
				cout << -1;
			}
			else {
				cout << DQ.front();
				DQ.pop_front();
			}
		}
		else if (order == "pop_back") {
			if (DQ.empty()) {
				cout << -1;
			}
			else {
				cout << DQ.back();
				DQ.pop_back();
			}
		}
		else if (order == "size") {
			cout << DQ.size();
		}
		else if (order == "empty") {
			cout << DQ.empty();
		}
		else if (order == "front") {
			if (DQ.empty()) {
				cout << -1;
			}
			else {
				cout << DQ.front();
			}
		}
		else {
			if (DQ.empty()) {
				cout << -1;
			}
			else {
				cout << DQ.back();
			}
		}
		cout << '\n';
	}
}

/*
💛 STL deque member function
- front(): 첫번째 원소 반환
- back(): 마지막 원소 반환
- push_front(value): deque 맨 앞에 원소 삽입
- push_back(value): deque 맨 뒤에 원소 삽입
- pop_front(): deque의 맨 앞의 원소 제거
- pop_back(): deque의 맨 뒤의 원소 제거
- begin(): 첫번째 원소를 가리키는 iterator 반환
- end(): 마지막 원소의 다음을 가리키는 iterator 반환
- size(): deque의 사이즈 반환
- empty(): deque가 비어있다면 true 반환, 아니면 false 반환
- at(idx): idx번째 원소 반환
- insert(idx, value): idx번째 위치에 value 삽입, 삽입한 곳의 iterator 반환
- insert(idx, n, value): idx번째 위치에 n개의 value 삽입
- erase(iter): iterator가 가리키는 원소 제거, 제거한 곳의 iterator 반환
*/

// https://www.acmicpc.net/problem/10866