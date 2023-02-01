# 강의실 배정 🥇

## 시간초과나는 코드

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
pair<int, int> s[200001];
int res;
vector<int> room; // 강의가 끝나는 시간 저장
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i].first >> s[i].second;
    }
    sort(s, s + n); // 강의가 시작하는 순대로, 시작 시간이 같다면 끝나는 순대로 정렬

    for (int i = 0; i < n; i++) {
        int isPossible = 0;

        // ⚠️ 벡터를 순회하는 부분 때문에 시간초과 발생 => 최적화 필요
        for (int j = 0; j < room.size(); j++) {
            if (room[j] <= s[i].first) { // 시작시간보다 작거나 같다면
                room[j] = s[i].second;
                isPossible = 1;
                break;
            }
        }
        res += 1 - isPossible;
        if (!isPossible) {
            room.push_back(s[i].second);
        }
    }
    cout << res << '\n';
    return 0;
}
```

> `82%`에서 시간초과가 발생했다. `vector`를 순회하는 부분 때문에 시간초과가 발생했다고 결론을 내렸고, 이 부분을 최적화하기로 했다.

- `vector` 순회의 목적: 현재 시작시간보다 작거나 같은 원소를 찾기 위해
- 만약 `vector`의 원소 중 최솟값만 봐도 된다면? 최솟값이 현재 시작시간보다 작거나 같다면 강의실 개수를 유지하고, 크다면 강의실 개수 하나 증가시킨다. => **greedy**
- 최솟값을 확인하는 데 가장 최적의 자료구조는 **heap**이므로, `vector` 대신 `heap`을 사용해보자.

<br/>

## 최종 제출 코드

> **greedy**한 접근법과 **priority queue**를 사용하여 최적화에 성공했다.

```cpp
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, res;
pair<int, int> s[200001];
priority_queue<int, vector<int>, greater<int>> pq; // 강의가 끝나는 시간을 저장하는 최소힙

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i].first >> s[i].second;
    }
    sort(s, s + n); // 강의가 시작하는 순대로 정렬
    for (int i = 0; i < n; i++) {
        if (!pq.empty() && pq.top() <= s[i].first) { // 최솟값이 현재 시작시간보다 작거나 같다면
            pq.pop();
        }
        else res++;
        pq.push(s[i].second);
    }
    cout << res << '\n';
    return 0;
}
```

> [문제 보러가기](https://www.acmicpc.net/problem/11000)
