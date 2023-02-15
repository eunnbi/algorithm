#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, k, n;
    char c;
    cin >> t;
    while (t--) {
        multiset<int> a; // ⚠️  local 변수로 선언!
        cin >> k;
        while (k--) {
            cin >> c >> n;
            if (c == 'I') a.insert(n);
            else if (a.empty()) continue;
            else if (n == -1) a.erase(a.begin());
            else a.erase(prev(a.end()));
        }
        if (a.empty()) cout << "EMPTY" << '\n';
        else cout << *prev(a.end()) << ' ' << *a.begin() << '\n';
    }
    return 0;
}