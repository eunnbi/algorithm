#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
long long s[1001];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    while (m--) {
        sort(s, s + n);
        long long a = s[0];
        long long b = s[1];
        s[0] += b;
        s[1] += a;
    }

    long long res = 0;
    for (int i = 0; i < n; i++) {
        res += s[i];
    }
    cout << res << '\n';
    return 0;
}