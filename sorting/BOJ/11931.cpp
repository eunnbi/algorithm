#include <bits/stdc++.h>
using namespace std;

int N;
int nums[1000001];

bool cmp(int a, int b) {
    return a > b;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    sort(nums, nums + N, cmp);
    for (int i = 0; i < N; i++) {
        printf("%d\n", nums[i]);
    }
    return 0;
}