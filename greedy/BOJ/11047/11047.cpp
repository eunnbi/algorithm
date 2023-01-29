#include <iostream>
using namespace std;

int n, k;
int coin[11];
int res;
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        if (k < coin[i]) continue;
        int num = k / coin[i];
        res += num;
        k -= coin[i] * num;
        if (k == 0) break;
    }
    cout << res << '\n';
}