#include <bits/stdc++.h>
using namespace std;

int N, S;
int nums[100001];
int mn;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	mn = N + 1;
	int left = 0, right = 0;
	int sum = nums[0];
	while (left <= right && right < N) {
		if (sum < S) {
			sum += nums[++right];
		}
		else {
			if (mn > (right - left + 1)) mn = right - left + 1;
			sum -= nums[left++];
		}
	}
	if (mn == N + 1) {
		cout << 0;
	}
	else {
		cout << mn;
	}
	return 0;
}