# 가운데를 말해요 🥇

## 시간초과나는 코드

```cpp
#include <iostream>
#include <set>
using namespace std;

multiset<int> a;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, num;
    cin >> n;
    while (n--) {
        cin >> num;
        a.insert(num);
        auto iter = a.begin();
        int size = a.size();
        advance(iter, size / 2);
        if (size & 1) cout << *iter << '\n';
        else cout << min(*iter, *prev(iter)) << '\n';
    }
    return 0;
}
```

수들이 정렬된 상태에서 가운데 값을 고르면 중간값을 구할 수 있다. 하지만, 값을 하나씩 입력받을 때마다 정렬하면 시간초과가 되니 이진 검색 트리를 이용했다. 하지만, 시간 제한이 0.1초라서 시간초과가 발생했다. 그래서, 이진 검색 트리 대신 우선순위 큐를 이용해야 한다.

<br/>

## 최종 제출 코드

```cpp
#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, num;
    cin >> n;
    while (n--) {
        cin >> num;
        if (maxHeap.size() <= minHeap.size()) maxHeap.push(num);
        else minHeap.push(num);
        if (!minHeap.empty() && minHeap.top() < maxHeap.top()) {
            minHeap.push(maxHeap.top()); maxHeap.pop();
            maxHeap.push(minHeap.top()); minHeap.pop();
        }
        cout << maxHeap.top() << '\n';
    }
    return 0;
}
```

👉 가장 작은 원소부터 pop되는 최소힙, 가장 큰 원소부터 pop되는 최대힙 두 개를 준비하고 원소들의 큰 쪽 절반은 최소힙에 저장되고 작은 쪽 절반은 최대힙에 저장되도록 관리한다.
