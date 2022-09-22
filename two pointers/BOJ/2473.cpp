#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
ll nums[5001];
ll res[3] = { INT_MAX, INT_MAX, INT_MAX };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	sort(nums, nums + N);
	for (int i = 0; i < N; i++) {
        // Narrowing two pointers
		int left = i + 1;
		int right = N - 1;
		while (left < right) {
			ll sum = nums[left] + nums[right] + nums[i];
			if (abs(sum) < abs(res[0] + res[1] + res[2])) {
				res[0] = nums[left];
				res[1] = nums[right];
				res[2] = nums[i];
			}
			if (sum <= 0) left++;
			else right--;
		}
	}
	sort(res, res + 3);
	cout << res[0] << ' ' << res[1] << ' ' << res[2];
	return 0;
}