
#include <bits/stdc++.h>
using namespace std;

int N, M;
int nums[2002];
int dp[2002][2002]; // dp[i][j] : nums[i]부터 nums[j]까지 수들의 팰린드롬 여부

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> nums[i];
    }
    for (int i = 1; i <= N; i++) {
        dp[i][i] = 1;
        if (nums[i - 1] == nums[i]) dp[i - 1][i] = 1;
    }

    for (int gap = 2; gap < N; gap++) {
        for (int i = 1; i <= N - gap; i++) {
            int s = i;
            int e = i + gap;
            if (nums[s] == nums[e] && dp[s + 1][e - 1]) dp[s][e] = 1;
        }
    }
    
    cin >> M;
    while (M--) {
        int s, e;
        cin >> s >> e;
        cout << dp[s][e] << '\n';
    }
    return 0;
}

// https://www.acmicpc.net/problem/10942