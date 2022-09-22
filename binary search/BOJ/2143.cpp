#include <bits/stdc++.h>
using namespace std;

int T, n, m;
int a[1001];
int b[1001];
int prefixA[1001];
int prefixB[1001];
long long res; // 주의: long long 형으로 선언해야 함!!

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		prefixA[i] = prefixA[i - 1] + a[i];
	}

	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
		prefixB[i] = prefixB[i - 1] + b[i];
	}

	vector<int> bruteA;
	vector<int> bruteB;
	for (int i = 0; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			bruteA.push_back(prefixA[j] - prefixA[i]);
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j <= m; j++) {
			bruteB.push_back(prefixB[j] - prefixB[i]);
		}
	}
	sort(bruteA.begin(), bruteA.end());

	for (int i = 0; i < bruteB.size(); i++) {
        // 찾으려는 원소의 개수를 구하는 방볍!!
		res += upper_bound(bruteA.begin(), bruteA.end(), T - bruteB[i]) - lower_bound(bruteA.begin(), bruteA.end(), T - bruteB[i]);
	}
	cout << res << '\n';
	return 0;
}

// Prefix Sum + Binary Search
// https://www.acmicpc.net/problem/2143