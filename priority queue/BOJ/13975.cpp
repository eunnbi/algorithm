#include <iostream>
#include <queue>
using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, k, num;
    cin >> t;
    while (t--) {
        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> num;
            pq.push(num);
        }
        long long res = 0;
        while (pq.size() > 1) {
            long long a = pq.top(); pq.pop();
            long long b = pq.top(); pq.pop();
            res += a + b;
            pq.push(a + b);
        }
        if (!pq.empty()) pq.pop();
        cout << res << '\n';
    }
    return 0;
}