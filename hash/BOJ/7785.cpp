#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>
using namespace std;

unordered_set<string> a;
int main() {
    int n;
    string name, status;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name >> status;
        if (status == "enter") a.insert(name);
        else a.erase(name);
    }
    vector<string> res(a.begin(), a.end());
    sort(res.begin(), res.end(), greater<string>());
    for (auto val: res) cout << val << '\n';
    return 0;
}
