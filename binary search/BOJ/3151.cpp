#include <bits/stdc++.h>
using namespace std;

int N;
int nums[10001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    sort(nums, nums + N); // 필수!!
    long long res = 0;
    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            int sum = nums[i] + nums[j];
            // lower_bound : 찾으려는 값과 같거나 큰 숫자가 몇 번째에서 처음 등장하는지 찾기 위함
            int l = lower_bound(nums + (j + 1), nums + N, -sum) - nums;
            // upper_bound : 찾으려는 값보다 큰 숫자가 몇 번째에서 처음 등장하는지 찾기 위함
            int u = upper_bound(nums + (j + 1), nums + N, -sum) - nums;
            res += (u - l);
        }
    }
    cout << res;
    return 0;
}

// https://www.acmicpc.net/problem/3151