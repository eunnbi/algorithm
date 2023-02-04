#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[500001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    cin >> m;
    while (m--) {
        int num;
        cin >> num;
        cout << upper_bound(a, a + n, num) - lower_bound(a, a + n, num) << ' ';
    }
    return 0;
}