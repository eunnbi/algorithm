#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

pair<int, int> a[500001];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    
    sort(a, a + n, greater<pair<int, int>>());
    multiset<int> group;
    for (int i = 0; i < n; i++) {
        auto itr = group.lower_bound(a[i].second);
        if (itr == group.begin()) group.insert(1);
        else {
            int size = *prev(itr);
            group.erase(prev(itr));
            group.insert(size + 1);
        }
    }
    cout<< group.size();
    return 0;
}