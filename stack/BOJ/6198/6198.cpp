#include <bits/stdc++.h>
using namespace std;

int main(void) {
	stack<int> S;
	int N;
	
	long long res = 0; // Integer overflow 주의!!
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		while (!S.empty() && S.top() <= num) S.pop(); 
		res += S.size();
		S.push(num);
	}
	cout << res;
	return 0;
}
