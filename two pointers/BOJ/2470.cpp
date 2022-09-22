#include <bits/stdc++.h>
using namespace std;

int N;
int nums[100001];
int mn = INT_MAX;
int res[2];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	sort(nums, nums + N);

    // Narrowing two pointers
	int left = 0;
	int right = N - 1;
	while (left < right) {
		int sum = nums[left] + nums[right];
		if (abs(sum) < mn) {
			mn = abs(sum);
			res[0] = nums[left];
			res[1] = nums[right];
		}
		if (sum <= 0) left++;
		else right--;
	}
	cout << res[0] << ' ' << res[1];
	return 0;
}