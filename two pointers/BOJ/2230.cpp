#include <bits/stdc++.h>
using namespace std;

int N, M;
int nums[100001];
int mn;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	mn = INT_MAX;
	sort(nums, nums + N);
	int left = 0, right = 1;
	while (left < N && right < N) {
		int sub = nums[right] - nums[left];
		if (sub < M) right++;
		else {
			if (sub < mn) mn = sub;
			left++;
		}
	}
	cout << mn;
	return 0;
}