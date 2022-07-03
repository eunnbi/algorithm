#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int T;
	cin >> T; // 케이스 개수

	for (int i = 0; i < T; i++) { 
		string str;
		cin >> str;

		list<char> pwd = {}; // list 초기화
		auto cursor = pwd.begin();
		for (auto c : str) { // str 순회
			if (c == '>') {
				if (cursor != pwd.end()) cursor++;
			}
			else if (c == '<') {
				if (cursor != pwd.begin()) cursor--;
			}
			else if (c == '-') {
				if (cursor != pwd.begin()) {
					cursor--;
					cursor = pwd.erase(cursor);
				}
			}
			else {
				pwd.insert(cursor, c);
			}
		}
		for (auto c : pwd) {
			cout << c;
		}
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/5397