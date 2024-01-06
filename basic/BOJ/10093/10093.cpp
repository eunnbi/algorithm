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
