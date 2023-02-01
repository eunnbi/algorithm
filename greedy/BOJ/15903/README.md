# 카드 합체 놀이

## 배열과 정렬 이용

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
long long s[1001]; // ⚠️ 자료형 주의!!

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    while (m--) {
        sort(s, s + n);
        long long a = s[0];  // ⚠️ 자료형 주의!!
        long long b = s[1];
        s[0] += b;
        s[1] += a;
    }

    long long res = 0;  // ⚠️ 자료형 주의!!
    for (int i = 0; i < n; i++) {
        res += s[i];
    }
    cout << res << '\n';
    return 0;
}
```

- 정렬한 뒤, 가장 작은 원소와 그 다음으로 작은 원소끼리 서로의 값을 더하는 작업을 m번 동안 수행한다.
- 이때, 원소의 범위가 1부터 1,000,000까지라서 `int`형 대신 `long long`형을 사용해야 한다.
- 시간복잡도가 `O(N^2logN)`이고 `N`은 1000이하라서 다행히 시간초과가 발생하지 않았다. 하지만, N이 더 커지면 시간초과가 발생할 것이다.
- 시간복잡도를 줄이기 위해 배열 대신 **최소힙**을 사용하여 최적화할 수 있다.

<br/>

## 우선순위 큐 이용

```cpp
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
priority_queue<long long, vector<long long>, greater<long long>> pq;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        pq.push(num);
    }

    while (m--) {
        long long a = pq.top(); pq.pop();
        long long b = pq.top(); pq.pop();
        pq.push(a + b);
        pq.push(a + b);
    }

    long long res = 0;
    while (!pq.empty()) {
        res += pq.top();
        pq.pop();
    }
    cout << res << '\n';
    return 0;
}
```

- 배열을 이용했을 때 최솟값을 확인하는데 시간복잡도가 `O(NlogN)`이지만, 우선순위 큐를 사용하면 시간복잡도가 `O(1)`이다.
- 물론, 우선순위 큐에 원소를 넣는데 시간복잡도가 `O(logN)`이지만, 두 개의 시간복잡도를 합쳐도 `O(NlogN)`보다는 작다.

> [문제 보러가기](https://www.acmicpc.net/problem/15903)
