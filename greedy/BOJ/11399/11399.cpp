#include <iostream>
#include <algorithm>
using namespace std;

int n;
int p[1002];
int res;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; i++) {
        p[i] = p[i] + p[i - 1];
        res += p[i];
    }
    cout << res << '\n';
}