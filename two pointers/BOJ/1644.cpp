#include <bits/stdc++.h>
using namespace std;

int N;
int res;
bool isPrime[4000001];
vector<int> prime;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	
	for (int i = 2; i <= N; i++) {
		isPrime[i] = true;
	}

	for (int i = 2; i <= N; i++) {
		if (isPrime[i]) {
			prime.push_back(i);
			for (int j = 2 * i; j <= N; j += i) {
				isPrime[j] = false;
			}
		}
	}

	if (prime.size() == 0) {
		cout << 0;
		return 0;
	}
	
	int left = 0, right = 0;
	int sum = prime[right];
	int size = prime.size();
	while (left < size && right < size) {
		if (sum == N) {
			res++;
			sum -= prime[left++];
		}
		else if (sum < N && (right != size - 1)) {
			sum += prime[++right];
		}
		else {
			sum -= prime[left++];
		}
	}
	cout << res;
	return 0;
}