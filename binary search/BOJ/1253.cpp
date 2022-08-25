#include <bits/stdc++.h>
using namespace std;

int N;
long long nums[2001];
bool good[2001];
int res;

bool isAllZero() {
    for (int i = 0; i < N; i++) {
        if (nums[i]) return false;
    }
    return true;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    if (isAllZero()) {
        cout << N;
        return 0;
    }

    sort(nums, nums + N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            int idx = lower_bound(nums, nums + N, nums[i] - nums[j]) - nums;
            if (idx == i || idx == j) continue;
            if (nums[idx] + nums[j] == nums[i]) {
                res++;
                break;
            }
        }
    }
    cout << res;
    return 0;
}

// https://www.acmicpc.net/problem/1253
/* **시간 초과 발생**
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
            int lIdx = lower_bound(nums, nums + N, nums[i] + nums[j]) - nums;
            int uIdx = upper_bound(nums, nums + N, nums[i] + nums[j]) - nums;
            for (int k = lIdx; k < uIdx; k++) {
                if (k == i || k == j) continue;
                good[k] = true;
            }
        }
    }
    long long res = 0;
    for (int i = 0; i < N; i++) {
        res += good[i];
    }
    cout << res;
    return 0;
}
*/

