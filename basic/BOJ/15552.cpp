#include <iostream>

using namespace std;

int main(void) {
	// 빠른 입출력을 위해 아래의 두 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	int a, b;
	cin >> T;
	for (int i = 0; i < T; i++) {
		// 입력과 출력을 번갈아 해도 된다.
		cin >> a >> b;
		cout << a + b << '\n';
	}
	return 0;
}

/*
👉 cin/cout을 이용한 빠른 입출력을 원한다면 "ios::sync_with_stdio(0)"와 "cin.tie(0)" 적용하기
👉 입력을 다 받고 나서야 출력을 할 필요는 없다. 백준에서는 입력 파일과 출력 파일은 분리되어 있다.
*/

// https://www.acmicpc.net/problem/15552