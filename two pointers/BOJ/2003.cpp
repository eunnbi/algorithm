#include <bits/stdc++.h>
using namespace std;

int N, M;
int nums[10001];
int res;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	int sum = 0;
	int left = 0, right = 0;
	sum += nums[right];
	while (left < N && right < N) {
		if (sum == M) {
			res++;
			sum -= nums[left++];
		}
		else if (sum > M) {
			sum -= nums[left++];
		}
		else {
			sum += nums[++right];
		}
	}
	cout << res;
	return 0;
}