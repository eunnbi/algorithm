# 카드 정렬하기 🥇

```cpp
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
```

👉 비교 횟수를 구할 때, 카드의 개수가 누적하여 더해진다. 그래서, 최소 비교 횟수를 구하기 위해서 카드가 한 묶음이 될 때까지, 가장 작은 수와 그 다음으로 작은 수 2개를 계속 더하는 전략을 취한다.

> 가장 작은 수와 그 다음으로 작은 수를 쉽게 구하기 위해서 **최소힙**을 사용했다. 최소힙은 수가 작을수록 우선순위가 높고, 우선순위가 높은 순대로 수를 확인할 수 있기 때문이다.
