#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t, n;
    string name, category;
    cin >> t;
    while (t--) {
        unordered_map<string, int> a;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> name >> category;
            a[category]++;
        }
        int res = 1;
        for (auto val: a) res *= val.second + 1;
        cout << res - 1 << '\n';
    }
    return 0;
}