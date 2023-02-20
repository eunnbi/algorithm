#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

pair<int, int> a[200001];
priority_queue<int, vector<int>, greater<int>> pq;

bool compare(pair<int, int>& a, pair<int, int>& b) {
    if (a.first != b.first) return a.first < b.first;
    else return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n, compare);
    int deadline = 1;
    for (int i = 0; i < n; i++) {
        if (deadline <= a[i].first) {
            pq.push(a[i].second);
            deadline++;
        }
        else if (pq.top() < a[i].second) {
            pq.pop();
            pq.push(a[i].second);
        }
    }
    long long res = 0;
    while (!pq.empty()) {
        res += pq.top();
        pq.pop();
    }
    cout << res;
    return 0;
}