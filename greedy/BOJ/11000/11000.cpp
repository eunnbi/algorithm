#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, res;
pair<int, int> s[200001];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i].first >> s[i].second;
    }
    sort(s, s + n);
    for (int i = 0; i < n; i++) {
        if (!pq.empty() && pq.top() <= s[i].first) {
            pq.pop();
        }
        else res++;
        pq.push(s[i].second);
    }
    cout << res << '\n';
    return 0;
}