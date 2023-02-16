#include <iostream>
#include <set>
#include <map>
using namespace std;

pair<int, int> problem[100002];
set<pair<int, int>> a[102];
map<int, set<int>> b;
set<pair<int, int>> c;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, p, l, g, m;
    string order;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p >> l >> g;
        a[g].insert({ l, p });
        b[l].insert(p);
        c.insert({ l, p });
        problem[p] = { l, g };
    }
    cin >> m;
    while (m--) {
        cin >> order;
        if (order == "add") {
            cin >> p >> l >> g;
            a[g].insert({ l, p });
            b[l].insert(p);
            c.insert({ l, p });
            problem[p] = { l, g };
        }
        else if (order == "solved") {
            cin >> p;
            a[problem[p].second].erase({ problem[p].first, p });
            b[problem[p].first].erase(p);
            c.erase({ problem[p].first, p });
        }
        else if (order == "recommend") {
            cin >> g >> p;
            if (p == 1) cout << (*prev(a[g].end())).second << '\n';
            else cout << (*a[g].begin()).second << '\n';
        }
        else if (order == "recommend2") {
            cin >> p;
            if (p == 1) cout << (*prev(c.end())).second << '\n';
            else cout << (*c.begin()).second << '\n';
        }
        else {
            cin >> p >> l;
            auto itr = b.lower_bound(l);
            if (itr == b.end() || (*itr).second.empty()) cout << -1 << '\n';
            else if (p == 1) cout << *((*itr).second.begin()) << '\n';
            else if (itr == b.begin() || (*prev(itr)).second.empty()) cout << -1 << '\n';
            else cout << *prev((*prev(itr)).second.end()) << '\n';
        }
    }
    return 0;
}