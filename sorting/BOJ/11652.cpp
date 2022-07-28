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

    sort(nums, nums + N);
    int sum = 1;
    int mx = 0;
    long long cmp = nums[0];
    long long res = cmp;

    for (int i = 1; i < N; i++) {
        if (nums[i] == cmp) sum++;
        else {
            if (sum > mx) {
                mx = sum;
                res = cmp;
            }
            sum = 1;
            cmp = nums[i];
        }
    }
    if (sum > mx) res = cmp; // 👀 마지막 수 별도로 확인!!!
    cout << res;
    return 0;
}

// https://www.acmicpc.net/problem/11652