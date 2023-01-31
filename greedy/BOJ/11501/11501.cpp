#include <iostream>
#include <algorithm>
using namespace std;

int t, n;
int s[1000001];
long long res;
int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        int start = 0;
        res = 0;
        while (true) {
            int idx = max_element(s + start, s + n) - s;
            for (int i = start; i < idx; i++) {
                res -= s[i];
            }
            res += s[idx] * (idx - start);
            start = idx + 1;
            if (idx == 0 || idx >= n - 2) break;
        }
        cout << res << '\n';
    }
}