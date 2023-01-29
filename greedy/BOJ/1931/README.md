# 회의실 배정 🥈

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> s[100001]; // end time, start time (정렬을 위해 pair 사용)
int endTime, res;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i].second >> s[i].first;
    }
    // 회의가 끝나는 시간을 기준을 오름차순 정렬. 만약 회의가 끝나는 시간이 같다면 회의 시작 시간 기준으로 오름차순 정렬
    sort(s, s + n);

    for (int i = 0; i < n; i++) {
        if (s[i].second >= endTime) {
            endTime = s[i].first;
            res++;
        }
    }
    cout << res << '\n';
}
```

👉 빨리 끝나는 회의를 먼저 배정하는 전략을 취한다. 회의가 빨리 끝날수록 많은 회의를 배정할 수 있기 때문이다.

- 회의를 배정할 수 있는 총 시간을 `T`라고 하고, `e1`, `e2`를 각각 회의가 끝나는 시간이라고 하자. (`e1 < e2`)
- `e1`을 선택했을 때 남는 시간 = `T - e1`
- `e2`를 선택했을 때 남는 시간 = `T - e2`
- 이때 `e1`을 선택하는 경우, `e2`를 선택하는 것보다 `e2 - e1` 만큼의 시간이 더 있다. 이 시간에 진행가능한 회의가 존재할지도 모른다.
- 결국 `e1`을 선택하는 것이 `e2`를 선택하는 것보다 반드시 **배정할 수 있는 회의의 수가 같거나 큰 값을 가질 수 밖에 없다.**

> [문제 보러가기](https://www.acmicpc.net/problem/1931)
