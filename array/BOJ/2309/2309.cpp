#include <iostream>
#include <algorithm>

using namespace std;

int occur[101] = { 0, }; // 주어지는 키는 100을 넘지 않는 자연수

int main(void) {
	int height[9];
	int fake[2];
	int sum = 0;

	for (int i = 0; i < 9; i++) {
		cin >> height[i];
		sum += height[i];
	}

	int diff = sum - 100; // 배열 안에서 합이 diff인 서로 다른 두 원소를 찾는 문제
	for (int i = 0; i < 9; i++) {
		if (diff - height[i] >= 0 && occur[diff - height[i]]) {
			fake[0] = height[i];
			fake[1] = diff - height[i];
            break;
		}
		occur[height[i]] = 1;
	}

	sort(height, height + 9);  // 오름차순으로 출력 => sort 함수 이용

	for (int i = 0; i < 9; i++) {
		if (fake[0] == height[i] || fake[1] == height[i]) {
			continue;
		}
		cout << height[i] << '\n';
	}
	return 0;
}

// 두 수의 합 문제(3273) 응용 버전
// https://www.acmicpc.net/problem/2309