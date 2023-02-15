#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

pair<int, int> a[300001];
multiset<int> b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, num;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i].second >> a[i].first;
    }
    for (int i = 0; i < k; i++) {
        cin >> num;
        b.insert(num);
    }
    sort(a, a + n);
    long long res = 0;
    for (int i = n - 1; i >= 0; i--) {
        auto it = b.lower_bound(a[i].second);
        if (it == b.end()) continue;
        b.erase(it);
        res += a[i].first;
    }
    cout << res;
    return 0;
}