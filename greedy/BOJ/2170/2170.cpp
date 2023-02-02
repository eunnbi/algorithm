#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> s[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i].first >> s[i].second;
    }

    sort(s, s + n);
    int res = s[0].second - s[0].first;
    for (int i = 1; i < n; i++) {
        if (s[i].first < s[i - 1].second) {
            if (s[i].second < s[i - 1].second) {
                s[i].second = s[i - 1].second;
            } else {
                res += s[i].second - s[i - 1].second;
            }
        }
        else {
            res += s[i].second - s[i].first;
        }
    }
    cout << res << '\n';
    return 0;
}

