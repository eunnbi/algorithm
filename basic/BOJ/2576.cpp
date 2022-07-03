#include <iostream>

using namespace std;

int main(void) {
	int number;   // 입력 받은 수를 저장하는 변수
	int odd = 0;  // 홀수 개수
	int sum = 0;  // 홀수 전체 합
	int min = 100;  // 주어지는 자연수는 100보다 작다고 했으므로 100으로  min 변수 초기화

	for (int i = 0; i < 7; i++) {
		cin >> number;
		if (number & 1) { // 홀수이면
			odd += 1;
			sum += number;
			if (number < min){ // min 변수 업데이트
				min = number;
			}
		}
	}
	if (odd) {
		cout << sum << '\n' << min;
	}
	else{
		cout << -1;
	}
	return 0;
}

/*
1.  홀짝 판별
- If x & 1 == 1, x is odd
- If x & 1 == 0, x is even

2. 최대값, 최소값 구하기
- 값들을 차례대로 입력 받는다면 굳이 배열을 이용하지 않아도 최댓값 혹은 최솟값을 구할 수 있다.
- 이때 최댓값과 최솟값을 담을 변수 (max, min)를 초기화해야 하는데 max는 "입력될 수 있는 값 중 최솟값"으로 초기화하고 min은 "입력될 수 있는 값 중 최댓값"으로 초기화한다.
*/


// https://www.acmicpc.net/problem/2576