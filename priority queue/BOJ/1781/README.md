# 컵라면 🥇

## 오답 코드

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> a[200001];

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
    long long res = 0;
    int deadline = a[0].first;
    for (int i = 0; i < n; i++) {
        if (deadline > a[i].first) continue;
        res += a[i].second;
        deadline++;
    }
    cout << res;
    return 0;
}
```

- 먼저 데드라인 기준으로 오름차순, 컵라면 기준 내림차순으로 정렬한 다음, 문제의 데드라인이 지나지 않았다면 해당 문제의 컵라면 개수를 더하여 답을 구한다.
- 하지만, 데드라인이 지나지 않았다고 무조건 선택하면 최대의 컵라면 개수를 구할 수 없는 경우도 있다. 데드라인이 더 긴 경우 더 많은 컵라면을 얻을 수 있는 경우가 있다.
  > ```
  > 입력
  > 3
  > 1 25
  > 2 50
  > 2 100
  >
  > - 출력: 125 (25 + 100)
  > - 정답: 150 (50 + 100)
  > ```
- 데드라인이 지나지 않았지만, 안 고르는 것이 최대가 될 수 있기 때문에, 우선순위 큐를 하나 추가하여 이 문제를 해결해보았다.

<br/>

## 최종 제출 코드

```cpp
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

pair<int, int> a[200001];
priority_queue<int, vector<int>, greater<int>> pq; // 최소힙

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
        if (deadline <= a[i].first) { // 데드라인이 지나지 않았다면
            pq.push(a[i].second);
            deadline++;
        }
        else if (pq.top() < a[i].second) { // 데드라인이 지났는데 지금까지 선택한 문제의 컵라면 개수 중 최소값보다 현재 문제의 컵라면 개수가 더 크다면
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
```

👉 데드라인이 지나지 않았다면 우선순위 큐에 컵라면 개수를 삽입한다. 만약 데드라인이 지났는데 지금까지 선택한 문제의 컵라면 개수 중 최소값보다 현재 문제의 컵라면 개수가 더 크다면 최소값을 제거하고, 현재 컵라면 개수를 추가한다. 마지막에 우선순위 큐에 남은 컵라면 개수의 총합이 정답이다.
