#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int n;
int a[100001];
int res[2];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int mn = 2000000001;
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(a, a + n, -a[i]) - a;
        if (idx < n && i != idx && mn > abs(a[i] + a[idx])) {
            mn = abs(a[i] + a[idx]);
            res[0] = a[i];
            res[1] = a[idx];
        }
        if (idx < n - 1 && i != idx + 1 && mn > abs(a[i] + a[idx + 1])) {
            mn = abs(a[i] + a[idx + 1]);
            res[0] = a[i];
            res[1] = a[idx + 1];
        }
        if (idx != 0 && i != idx - 1 && mn > abs(a[i] + a[idx - 1])) {
            mn = abs(a[i] + a[idx - 1]);
            res[0] = a[i];
            res[1] = a[idx - 1];
        }
    }
    sort(res, res + 2);
    cout << res[0] << ' ' << res[1] << '\n';
    return 0;
}