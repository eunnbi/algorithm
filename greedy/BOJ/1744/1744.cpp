#include <iostream>
#include <algorithm>
using namespace std;

int n;
int s[51];
int res;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s, s + n);
    if (n == 1) {
        cout << s[0] << '\n';
        return 0;
    }
    int idx = lower_bound(s, s + n, 0) - s;
    if (s[idx] == 0) {
        int i = n - 1;
        while (i > idx + 1) {
            if (s[i] == 1 || s[i - 1] == 1) {
                res += s[i] + s[i - 1];
            }
            else {
                res += s[i] * s[i - 1];
            }
            i -= 2;
        }
        if ((n - 1 - idx) & 1) {
            res += s[idx + 1];
        }
        i = 0;
        while (i < idx) {
            res += s[i] * s[i + 1];
            i += 2;
        }
    }
    else {
        int i = n - 1;
        while (i > idx) {
            if (s[i] == 1 || s[i - 1] == 1) {
                res += s[i] + s[i - 1];
            }
            else {
                res += s[i] * s[i - 1];
            }
            i -= 2;
        }
        if ((n - idx) & 1) {
            res += s[idx];
        }
        i = 0;
        while (i < idx - 1) {
            res += s[i] * s[i + 1];
            i += 2;
        }
        if (idx & 1) {
            res += s[idx - 1];
        }
    }
    cout << res << '\n';
    return 0;
}
