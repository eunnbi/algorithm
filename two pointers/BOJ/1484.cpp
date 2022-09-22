#include <bits/stdc++.h>
using namespace std;

int G;
vector<int> res;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> G;

	int left = 1;
	int right = 2;
	while (left <= G && right <= G) {
		int weight = (right * right) - (left * left);
		if (weight < G) {
			right++;
		}
		else if (weight == G) {
			res.push_back(right);
			left++;
		}
		else {
			left++;
		}
	}
	if (res.size() == 0) {
		cout << -1;
	}
	else {
		sort(res.begin(), res.end());
		for (int item : res) {
			cout << item << '\n';
		}
	}
	return 0;
}