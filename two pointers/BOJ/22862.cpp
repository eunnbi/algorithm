#include <iostream>
using namespace std;

int a[1000003];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int res = 0;
    int i = 0;
    int j = 0;
    int even = 0;
    int odd = 0;
    while (i < n && j < n) {
        if (!(a[j] & 1)) even++;
        else if (j != 0) {
            while (odd >= k) {
                if (!(a[i] & 1)) even--;
                else if (i != 0) odd--;
                i++;
            }
            odd++;
        }
        j++;
        res = max(res, even);
    }
    cout << res;
    return 0;
}