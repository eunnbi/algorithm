#include <iostream>
#include <set>
using namespace std;

set<int> landmark;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q, num, x;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (x) landmark.insert(i);
    }
    int pos = 1;
    while (q--) {
        cin >> num;
        if (num == 1) {
            cin >> x;
            if (landmark.find(x) != landmark.end()) {
                landmark.erase(x);
            }
            else landmark.insert(x);
        }
        else if (num == 2) {
            cin >> x;
            pos = (pos + x - 1) % n + 1;
        }
        else {
            if (landmark.empty()) cout << -1 << '\n';
            else {
                auto it = landmark.lower_bound(pos);
                if (it != landmark.end()) {
                    cout << *it - pos << '\n';
                }
                else {
                    cout << n - pos + *landmark.begin() << '\n';
                }
            }
        }
    }
    return 0;
}
