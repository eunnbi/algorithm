#include <iostream>
using namespace std;

int n;
int res;
int s[101];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = n - 2; i >= 0; i--) {
        if (s[i + 1] > s[i]) continue;
        res += s[i] - s[i + 1] + 1;
        s[i] = s[i + 1] - 1;
    }
    cout << res << '\n';
    return 0;
}
