#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n, num;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        pq.push(num);
    }
    
    int res = 0;
    while (pq.size() >= 2) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        res += a + b;
        pq.push(a + b);
    }
    cout << res << '\n';
    return 0;
}