#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

unordered_map<string, int> a;
bool compare(pair<string, int> a, pair<string, int> b) {
    return a.second < b.second;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k, l;
    string name;
    cin >> k >> l;
    for (int i = 0; i < l; i++) {
        cin >> name;
        a[name] = i;
    }
    vector<pair<string, int>> v(a.begin(), a.end());
    sort(v.begin(), v.end(), compare);
    int num = 0;
    for (auto val: v) {
        if (num >= k) break;
        cout << val.first << '\n';
        num++;
    }
    return 0;
}
