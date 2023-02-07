#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

long long a[5001];
long long res[3];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    long long mn = 3000000002;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int idx = lower_bound(a + j + 1, a + n, -(a[i] + a[j])) - a;

            // 후보: idx-2, idx-1, idx, idx+1, idx+2 위치에 있는 용액
            for (int k = -2; k <= 2; k++) {
                if (i == idx + k || j == idx + k) continue;
                if (idx + k < 0 || idx + k >= n) continue;
                if (mn > abs(a[i] + a[j] + a[idx + k])) {
                    mn = abs(a[i] + a[j] + a[idx + k]);
                    res[0] = a[i];
                    res[1] = a[j];
                    res[2] = a[idx + k];
                }
            }
        }
    }
    sort(res, res + 3);
    for (auto val: res) cout << val << ' ';
    return 0;
}