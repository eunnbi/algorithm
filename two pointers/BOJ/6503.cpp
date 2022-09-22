#include <bits/stdc++.h>
using namespace std;

int m;
string str;
int used[129];
int mx;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		cin >> m;
		if (m == 0) break;

		cin.ignore(); // 중요: 버퍼 비우기!!
		getline(cin, str); // 공백 있는 문자열 입력받기!!
		int len = str.length();


		for (int i = 0; i < 129; i++) {
			used[i] = 0; // 초기화!
		}
		mx = 0; // 초기화!

		int left = 0;
		int sum = 0;
		for (int right = 0; right < len; right++) {
			if (!used[(int)str[right]]) sum++;
			used[(int)str[right]]++;
			while (sum > m) {
				used[(int)str[left]]--;
				if (!used[(int)str[left]]) sum--;
				left++;
			}
			//printf("%d %d\n", left, right);
			if (mx < (right - left + 1)) mx = right - left + 1;
		}
		cout << mx << '\n';
	}
	
	return 0;
}