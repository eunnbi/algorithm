#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> s[100001];
int now = 301;
int res, mx;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        s[i].first = a * 100 + b;
        s[i].second = c * 100 + d;
    }
    sort(s, s + n);
    for (int i = 0; i < n; i++) {
        if (now > 1130) break;
        if (now >= s[i].first) {
            mx = max(mx, s[i].second);
        }
        if (now < s[i].first) {
            if (mx == 0) {
                res = 0;
                break;
            }
            else {
                res++;
                now = mx;
                mx = 0;
                i--;
            }
        }
    }
    if (mx != 0) {
        now = mx;
        res++;
    }
    if (now <= 1130) {
        res = 0;
    }
    cout << res << '\n';
    return 0;
}