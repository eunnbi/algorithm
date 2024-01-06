#include <iostream>
using namespace std;

int main(void) {
	int N;
	string a, b;
	int i, j;
	cin >> N;
	for (i = 0; i < N; i++) {
		int eng[26] = { 0, }; // 변수 초기화 위치 중요!

        	cin >> a >> b;
		bool IsPossible = true;
		for (j = 0; j < a.length(); j++) {
			eng[a[j] - 'a']++;
		}
		for (j = 0; j < b.length(); j++) {
			eng[b[j] - 'a']--;
		}
		for (j = 0; j < 26; j++) {
			if (eng[j] != 0) { // 0이 아닌 배열의 요소가 있을 경우, 개수가 다른 문자가 존재하므로 false
				IsPossible = false;
				break;
			}
		}

		if (IsPossible) {
			cout << "Possible" << '\n';
		}
		else {
			cout << "Impossible" << '\n';
		}
	}
	return 0;
}

/*
💡 문제 파악 중요!!!
- 알파벳 개수가 동일한지 파악해야 함!!
- 정확히 이해할 수 있도록 문제를 재정의해야 한다.
- 문제를 파악할 때 예제에 의존해선 안된다!!
*/

// 
// https://www.acmicpc.net/problem/11328
