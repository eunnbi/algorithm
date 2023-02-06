#include <iostream>
#include <algorithm>
using namespace std;

int a[2001];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int target = a[i] - a[j];
            int idx = lower_bound(a, a + n, target) - a;
            bool isPossible = false;
            while (idx < n && a[idx] == target) {
                if (idx != i && idx != j) {
                    isPossible = true;
                    res++;
                    break;
                }
                idx++;
            }
            if (isPossible) break;
        }
    }
    cout << res << '\n';
    return 0;
}