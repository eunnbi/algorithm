#include <iostream>
using namespace std;

int a[1000001];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int res = 0;
    int l = 1;
    int r = 1000000000;
    long long mid;
    int cnt = 0;
    while (l <= r) {
        mid = l + (r - l) / 2;
        cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += a[i] / mid;
        }
        if (cnt >= m) {
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
        
    }
    cout << res << '\n';
    return 0;
}