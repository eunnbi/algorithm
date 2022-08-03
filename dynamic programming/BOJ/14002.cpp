#include <bits/stdc++.h>
using namespace std;

int N;
int nums[1001];
int dp[1001];
int track[1001];

void backtrack(int i) {
    if (i == track[i]) {
        printf("%d ", nums[i]);
        return;
    }
    backtrack(track[i]);
    printf("%d ", nums[i]);
}


int main(void) {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> nums[i];
        dp[i] = 1; // dp 배열 초기화!!
        track[i] = i; // track 배열 초기화!!
    }

    for (int i = 2; i <= N; i++) {
        int mx = dp[i];
        int mxIdx = i;
        for (int j = 1; j < i; j++) {
            if (nums[i] <= nums[j]) continue;
            if (mx < dp[j] + 1) {
                mx = dp[j] + 1;
                mxIdx = j;
            }
        }
        dp[i] = mx;
        track[i] = mxIdx;
    }
    int* res = max_element(dp + 1, dp + N + 1);
    cout << *res << '\n';
    backtrack(res - dp);
    return 0;
}

// https://www.acmicpc.net/problem/14002