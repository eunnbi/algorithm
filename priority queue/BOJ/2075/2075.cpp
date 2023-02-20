#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n;
    for (int i = 0; i < n * n; i++) {
        cin >> x;
        pq.push(x);
        while (pq.size() > n) pq.pop();
    }
    
    cout << pq.top() << '\n';
    return 0;
}