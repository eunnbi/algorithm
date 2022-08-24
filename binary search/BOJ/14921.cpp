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

    long long res = 200000001;
    for (int i = 0; i < N - 1; i++) {
        int idx = lower_bound(nums, nums + N, -nums[i]) - nums;
        if (idx + 1 < N && i != idx + 1 && abs(nums[i] + nums[idx + 1]) < abs(res)) {
            res = nums[i] + nums[idx + 1];
        }
        if (idx < N && i != idx && abs(nums[i] + nums[idx]) < abs(res)) {
            res = nums[i] + nums[idx];
        }
        if (idx != 0 && i != idx - 1 && abs(nums[i] + nums[idx - 1]) < abs(res)) {
            res = nums[i] + nums[idx - 1];
        }
    }
    cout << res;   
    return 0;
}

// https://www.acmicpc.net/problem/14921