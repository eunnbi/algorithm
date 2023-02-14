#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<string, string> a;
unordered_map<string, vector<string>> b;

int main() {
    int n, m, cnt;
    string group, name;
    cin >> n >> m;
    while (n--) {
        cin >> group;
        cin >> cnt;
        for (int i = 0; i < cnt; i++) {
            cin >> name;
            a[name] = group;
            b[group].push_back(name);
        }
        sort(b[group].begin(), b[group].end());
    }
    
    string query;
    int num;
    while (m--) {
        cin >> query;
        cin >> num;
        if (num == 0) {
            for (auto val: b[query]) cout << val << '\n';
        }
        else {
            cout << a[query] << '\n';
        }
    }
    return 0;
}