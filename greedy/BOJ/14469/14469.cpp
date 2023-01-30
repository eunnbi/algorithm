#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> s[101];
int res;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i].first >> s[i].second;
    }
    sort(s, s + n);
    for (int i = 0; i < n; i++) {
        if (res >= s[i].first) {
            res += s[i].second;
        }
        else {
            res = s[i].first + s[i].second;
        } 
    }
    cout << res << '\n';
}