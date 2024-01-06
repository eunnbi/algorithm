#include <iostream>

using namespace std;

int main(void) {
	int number[4];
	int occur[2] = { 0, };
	int result[3];
	for (int i = 0; i < 3; i++) {
		memset(occur, 0, sizeof(occur)); // 초기화!!
		for (int j = 0; j < 4; j++) {
			cin >> number[i];
			occur[number[i]] += 1;
		}
		if (occur[0] == 0) {
			result[i] = 4;
		}
		else {
			result[i] = occur[0] - 1;
		}
		
	}
	for (int i = 0; i < 3; i++) {
		cout << char(result[i] + 'A') << "\n";  // 형변환
	}
	return 0;
}
/*
👉 배열 초기화: 여러 테스트 케이스가 주어지는 경우 배열 초기화를 해야 하는 경우가 많다.
*/
// https://www.acmicpc.net/problem/2490