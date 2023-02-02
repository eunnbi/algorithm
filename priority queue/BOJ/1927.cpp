#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    // ⚠️ 아래 두줄 지우면 시간초과 발생
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    priority_queue<int, vector<int>, greater<int>> pq;
    cin >> n;
    while (n--) {
        cin >> x;
        if (x == 0) {
            if (pq.empty()) cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else {
            pq.push(x);
        }
    }
    return 0;
}