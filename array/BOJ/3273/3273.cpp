#include <iostream>
using namespace std;

int number[100001] = { 0, }; // 1 ≤ n ≤ 100000

//두 수의 합을 찾는데 시간 복잡도를 줄여줌. (trade-off)
bool occur[2000001] = { 0, };  //  1 ≤ x ≤ 2000000

int main(void) {
	int n, x;
	int cnt = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> number[i];
	}
	cin >> x;


	for (int i = 0; i < n; i++) {
		if (x - number[i] > 0 // out of bounds가 일어나지 않도록 분기하기
				 && occur[x - number[i]]) {
			cnt++;
		}
		occur[number[i]] = true;
	}
	cout << cnt;
	return 0;
}

/*
💡 배열 안에서 합이 x인 서로 다른 두 원소를 찾을 때 "occur 배열" 이용!
💡 배열의 경우 out of bounds가 일어날 수 있는 경우를 파악하여 조건문으로 분기하기
*/

// https://www.acmicpc.net/problem/3273