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
๐ STL deque member function
- front(): ์ฒซ๋ฒ์งธ ์์ ๋ฐํ
- back(): ๋ง์ง๋ง ์์ ๋ฐํ
- push_front(value): deque ๋งจ ์์ ์์ ์ฝ์
- push_back(value): deque ๋งจ ๋ค์ ์์ ์ฝ์
- pop_front(): deque์ ๋งจ ์์ ์์ ์ ๊ฑฐ
- pop_back(): deque์ ๋งจ ๋ค์ ์์ ์ ๊ฑฐ
- begin(): ์ฒซ๋ฒ์งธ ์์๋ฅผ ๊ฐ๋ฆฌํค๋ iterator ๋ฐํ
- end(): ๋ง์ง๋ง ์์์ ๋ค์์ ๊ฐ๋ฆฌํค๋ iterator ๋ฐํ
- size(): deque์ ์ฌ์ด์ฆ ๋ฐํ
- empty(): deque๊ฐ ๋น์ด์๋ค๋ฉด true ๋ฐํ, ์๋๋ฉด false ๋ฐํ
- at(idx): idx๋ฒ์งธ ์์ ๋ฐํ
- insert(idx, value): idx๋ฒ์งธ ์์น์ value ์ฝ์, ์ฝ์ํ ๊ณณ์ iterator ๋ฐํ
- insert(idx, n, value): idx๋ฒ์งธ ์์น์ n๊ฐ์ value ์ฝ์
- erase(iter): iterator๊ฐ ๊ฐ๋ฆฌํค๋ ์์ ์ ๊ฑฐ, ์ ๊ฑฐํ ๊ณณ์ iterator ๋ฐํ
*/

// https://www.acmicpc.net/problem/10866