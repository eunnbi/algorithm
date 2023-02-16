#include <iostream>
#include <set>
#include <map>
using namespace std;

set<pair<int, int>> a;
int level[100002];

int main() {
    int n, p, l, m;
    string order;
    cin >> n;
    while (n--) {
        cin >> p >> l;
        a.insert({ l, p });
        level[p] = l;
    }
    cin >> m;
    while (m--) {
        cin >> order;
        if (order == "add") {
            cin >> p >> l;
            a.insert({ l, p });
            level[p] = l;
        }
        else if (order == "solved") {
            cin >> p;
            a.erase({ level[p], p });
        }
        else {
            cin >> p;
            if (p == 1) cout << (*prev(a.end())).second << '\n';
            else cout << (*a.begin()).second << '\n';
        }
    }
    return 0;
}
