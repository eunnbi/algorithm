# 좋다 🥇

## 시간초과나는 코드

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int a[2001];
bool good[2001];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int u = upper_bound(a, a + n, a[i] + a[j]) - a;
            int l = lower_bound(a, a + n, a[i] + a[j]) - a;
            // 이미 좋은 수로 판명난 수가 중복해서 나타냄.
            for (int k = l; k < u; k++) {
                if (k != i && k != j) good[k] = true;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += good[i];
    }
    cout << res << '\n';
    return 0;
}
```

- 위 코드에서는 이미 좋은 수로 판명난 수가 중복해서 나타나 연산된다.
- 이 부분이 최적화할 부분이라고 생각했다. 그래서 배열을 순회하며 원소가 좋은 수인지 판단하는 로직으로 수정했다.

<br/>

## 최종 제출 코드

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int a[2001];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int res = 0;
    for (int i = 0; i < n; i++) { // a[i]가 좋은 수인지 판별
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int target = a[i] - a[j];
            int idx = lower_bound(a, a + n, target) - a;
            bool isPossible = false;
            while (idx < n && a[idx] == target) {
                if (idx != i && idx != j) {
                    isPossible = true;
                    res++;
                    break;
                }
                idx++;
            }
            if (isPossible) break;
        }
    }
    cout << res << '\n';
    return 0;
}
```

> [문제 보러가기](https://www.acmicpc.net/problem/1253)
