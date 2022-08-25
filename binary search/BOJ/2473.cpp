#include <bits/stdc++.h>
using namespace std;

int N;
long long nums[5001];
long long res[3] = { 0x7f7f7f7f7f7f, 0x7f7f7f7f7f7f, 0x7f7f7f7f7f7f };

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    sort(nums, nums + N);

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int idx = lower_bound(nums, nums + N, -nums[i]-nums[j]) - nums;
            // 후보 : idx - 2, idx - 1, idx, idx + 1, idx + 2
            for (int k = -2; k <= 2; k++) {
                if (idx + k == i || idx + k == j) continue;
                if (idx + k < 0 || idx + k >= N) continue;
                if (abs(nums[i] + nums[j] + nums[idx + k]) < abs(res[0] + res[1] + res[2])) {
                    tie(res[0], res[1], res[2]) = { nums[i], nums[j], nums[idx + k] };
                    // tie를 이용해 값 3개를 한번에 assign
                }
            }
        }
    }
    sort(res, res + 3);
    cout << res[0] << " " << res[1] << " " << res[2];
    return 0;
}

// https://www.acmicpc.net/problem/2473