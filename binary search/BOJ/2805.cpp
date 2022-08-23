#include <bits/stdc++.h>
using namespace std;

long long M, N;
long long trees[1000001];

bool isPossible(long long x) {
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        if (trees[i] <= x) continue;
        sum += trees[i] - x;
    }
    return sum >= M;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> trees[i];
    }

    long long left = 1;
    long long right = *max_element(trees, trees + N);
    long long mid, res = 0;
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
}