#include <bits/stdc++.h>
using namespace std;

int M, N;
long long snack[1000001];

bool isPossible(long long x) {
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += snack[i] / x;
    }
    return sum >= M;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        cin >> snack[i];
    }

    long long left = 1;
    long long right = *max_element(snack, snack + N);
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