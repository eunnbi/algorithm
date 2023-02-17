#include <iostream>
#include <set>
using namespace std;

set<int> a;
int height[250002];
long long res;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, key;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> key;
        auto itr = a.lower_bound(key);
        long long left = 0;
        long long right = 0;
        if (itr != a.begin()) left = height[*prev(itr)];
        if (itr != a.end()) right = height[*itr];
        height[key] = max(left, right) + 1;
        res += height[key];
        a.insert(key);
    }
    cout << res;
    return 0;
}