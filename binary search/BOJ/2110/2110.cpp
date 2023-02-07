#include <iostream>
#include <algorithm>
using namespace std;

int n, c;
int a[200001];

bool solve(int len) {
    int idx = 0, cnt = 0;
    while (idx != n) {
        idx = lower_bound(a + idx, a + n, a[idx] + len) - a;
        cnt++;
    }
    return cnt >= c;
}

int main()
{
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