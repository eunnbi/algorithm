#include <iostream>

using namespace std;

int main(void) {
    // "1 ≤ a, b ≤ 10^15" => int형으로 선언하면 integer overflow 발생
    // 모든 변수 long long형으로 선언
	long long a, b;  
	long long min, max, diff;
	cin >> a >> b;
	min = (a > b) ? b : a;
	max = a + b - min;
	if (min == max) {
		cout << 0;
		return 0;
	}
	diff = max - min - 1;
	cout << diff << '\n';
	for (long long i = min + 1; i < max; i++) {
		cout << i << ' ';
	}
	return 0;
}

/*
👉 예외 상황 컨트롤
문제에서 일어날 수 있는 모든 상황들을 파악하여 구현해야 한다.
이 문제에서는 두 수 사이의 수의 개수와 수들을 오름차순으로 출력해야 한다. 
그러면 두 수를 a, b라고 했을 때 다음과 같은 상황들을 고려해야 한다.

- a와 b가 같은 경우
- a가 b보다 큰 경우
- a가 b보다 작은 경우

위의 세가지 상황을 모두 고려하기 위해 우선 두 수 중 최소, 최대를 알아낸다. 
만약 최소와 최대가 같으면 0을 출력하고 종료한다. 
아니라면 for문을 이용하여 최소, 최대 사이의 수를 출력한다.
*/

// https://www.acmicpc.net/problem/10093