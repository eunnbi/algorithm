# N번째 큰 수 🥈

```cpp
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
```

👉 문제의 메모리 제한을 고려해 우선순위 큐에 상위 N개의 값만 가지고 있는다.
