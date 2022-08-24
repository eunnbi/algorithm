#include <bits/stdc++.h>
using namespace std;

int N;
long long nums[100001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int res1 = 1e9 + 1;
    int res2 = 1e9 + 1;
    for (int i = 0; i < N; i++) {
        int idx = lower_bound(nums, nums + N, -nums[i]) - nums;
        // lower_bound의 성질에 따라 nums[idx]는 -nims[i]와 같거나, -nums[i]보다 큰 원소 중에 가장 작은 원소
        // nums[i]와 더했을 때 값이 0과 가까운 원소는 nums[idx + 1] or nums[idx] or nums[idx - 1]

        if (idx + 1 < N && i != idx + 1 && abs(nums[i] + nums[idx + 1]) < abs(res1 + res2)) {
            res1 = nums[i];
            res2 = nums[idx + 1];
        }
        if (idx < N && i != idx && abs(nums[i] + nums[idx]) < abs(res1 + res2)) {
            res1 = nums[i];
            res2 = nums[idx];
        }
        if (idx != 0 && i != idx - 1 && abs(nums[i] + nums[idx - 1]) < abs(res1 + res2)) {
            res1 = nums[i];
            res2 = nums[idx - 1];
        }
        
    }
    if (res1 > res2) swap(res1, res2);
    cout << res1 << ' ' << res2;
    return 0;
}

// https://www.acmicpc.net/problem/2467