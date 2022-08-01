#include <bits/stdc++.h>
using namespace std;

int N, M;
int nums[100001];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> nums[i];
        nums[i] += nums[i - 1];
    }
    int left, right;
    while (M--) {
        cin >> left >> right;
        printf("%d\n", nums[right] - nums[left - 1]); // 구간합 이용
    }
    return 0;
}

// https://www.acmicpc.net/problem/11659