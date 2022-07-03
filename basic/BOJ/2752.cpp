#include <algorithm>
#include <iostream> 

using namespace std;

// 1.
int main(void){
	int a, b, c;   // 입력
	cin >> a >> b >> c;
	int d, e, f;   // 크기 순으로 출력할 세 수
	d = min({a, b, c});
	f = max({a, b, c});
	e = a + b + c - d - f;
	cout << d << ' ' << e << ' ' << f;
}


// 2.
int main(void){
	int a, b, c;   // 입력
	cin >> a >> b >> c;
	int d, e, f;   // 크기 순으로 출력할 세 수
	pair<int, int> mm = minmax({ a, b, c });
    d = mm.first;
	f = mm.second;
	e = a + b + c - d - f;
	cout << d << ' ' << e << ' ' << f;
}

/*
👉 min, max 함수
- algorithm 헤더 파일에 구현되어 있는 함수이다.
- {}을 이용하여 3개 이상의 값들에 대해 최소값, 최대값을 구할 수 있다.

👉 minmax 함수
- pair<int, int> 타입 반환
- first에는 최소값, second에는 최대값이 들어가 있다.
*/

// https://www.acmicpc.net/problem/2752