#include <bits/stdc++.h>
using namespace std;

int K, N;
int nums[10001];


bool isPossible(long long x) {
    long long sum = 0;
    for (int i = 0; i < K; i++) {
        sum += nums[i] / x;
    }
    return sum >= N;
}

int main(void) {
    cin >> K >> N;
    for (int i = 0; i < K; i++) {
        cin >> nums[i];
    }
    long long left = 1;
    long long right = 0x7fffffff;
    long long mid, res;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (isPossible(mid)) {
            res = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    cout << res;
    return 0;
}