#include <bits/stdc++.h>
using namespace std;

int n, w, L;
deque<int> weight;
deque<pair<int, int>> bridge;

int main(void) {
	cin >> n >> w >> L;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		weight.push_back(num);
	}

	int res = 0;
	while (!weight.empty() || !bridge.empty()) {
		if (!bridge.empty()) {
			for (int i = 0; i < bridge.size(); i++) {
				int weight, time;
				tie(weight, time) = bridge[i];
				bridge[i] = { weight, time - 1 };
			}
			if (bridge.front().second == 0) bridge.pop_front();
		}
		
		int sum = 0; // 현재 다리에 있는 트럭의 무게 합계
		if (!bridge.empty()) {
			for (int i = 0; i < bridge.size(); i++) {
				sum += bridge[i].first;
			}
		}

		if (!weight.empty()) {
			int truck = weight.front();
			if (sum + truck <= L) {
				weight.pop_front();
				bridge.push_back({ truck, w });
			}
		}
		res++;
	}
	printf("%d", res);
	return 0;
}