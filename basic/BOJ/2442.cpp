#include <iostream>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < N - i; j++) {
			cout << ' ';
		}
		for (int j = 0; j < 2 * i - 1; j++) {
			cout << '*';
		}
		cout << '\n';
	}

	return 0;
}

// '*'의 오른쪽 공백은 출력하지 말아야 통과한다. 출력 형식 지키기!!
// https://www.acmicpc.net/problem/2442