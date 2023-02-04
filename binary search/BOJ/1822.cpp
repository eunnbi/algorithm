#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[500001];
int b[500001];
vector<int> res;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    
    sort(a, a + n);
    sort(b, b + m);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!binary_search(b, b + m, a[i])) {
            res.push_back(a[i]);
        }
    }
    cout << res.size() << '\n';
    for (int val: res) {
        cout << val << ' ';
    }
    return 0;
}