# 공유기 설치 🥇

```cpp
int n, c;
int a[200001];

// 💡 이 문제의 핵심
bool solve(int len) { // len: 가장 인접한 두 공유기 사이의 거리
    int idx = 0, cnt = 0;
    while (idx != n) {
        // a[idx]로부터 len만큼 떨어진 원소를 찾는다.
        idx = lower_bound(a + idx, a + n, a[idx] + len) - a;
        cnt++;
    }
    return cnt >= c;
}

int main() {
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int l = 1;
    int r = a[n - 1] - a[0];
    int mid, res;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (solve(mid)) {
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << res << '\n';
    return 0;
}
```

👉 가장 인접한 두 공유기 사이의 거리를 탐색 범위로 두고 이분 탐색을 수행하여 최대값을 찾는다.

> [문제 보러가기](https://www.acmicpc.net/problem/2110)
