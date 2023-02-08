#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
long long a[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    
    long long l = 0;
    long long r = *max_element(a, a + n);
    long long mid, sum, res = 0;
    while (l <= r) {
        mid = l + (r - l) / 2;
        sum = 0;
        for (int i = 0; i < n; i++) {
            sum += min(mid, a[i]);
        }
        if (sum <= m) {
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << res << '\n';
    return 0;
}