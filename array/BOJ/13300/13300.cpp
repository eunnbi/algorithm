#include <iostream>
using namespace std;

// 2차원 배열 이용
// 전역변수라서 0으로 초기화됨.
int stu[2][7] = {};

int main(void) {
	int N, K;
	int S, Y; // 각각 성별과 학년을 나타내는 변수
	int room = 0;

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> S >> Y;
		stu[S][Y] += 1;
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 7; j++) {
			if (stu[i][j] == 0) {
				continue;
			}
			room += stu[i][j] / K;
            if (stu[i][j] % K) room++;
		}
	}
	cout << room;

	return 0;
}

/*
💡 2차원 배열의 필요성
- 학생들을 성별과 학년별로 구별해야 하기 때문에 2차원 배열을 이용하여 학생 수를 저장한다.
- 1차원 배열을 활용하는 것도 중요하지만 2차원 배열 등 다차원 배열의 활용성도 고려해야 한다.
*/

// https://www.acmicpc.net/problem/13300