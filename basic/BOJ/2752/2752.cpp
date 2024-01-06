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
