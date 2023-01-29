#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[51];
int b[51];
int res;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    for (int i = 0; i < n; i++) {
        res += a[i] * b[n - i - 1];
    }
    cout << res << '\n';
}