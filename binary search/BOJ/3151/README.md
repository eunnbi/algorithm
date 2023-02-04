# 합이 0 🥇

## 오답 코드

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[10002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    long long res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (binary_search(a + j + 1, a + n, -(a[i] + a[j]))) res++;
        }
    }
    cout << res << '\n';
    return 0;
}
```

- 두명을 선택하고, 나머지 한 명을 이분탐색으로 찾는다.
- 하지만, **나머지 한 명을 찾을 때 여러 명이 가능한 경우를 고려해지 못했다.**
- 여러 명이 가능한 경우를 고려해 `upper_bound`와 `lower_bound`를 사용해야 한다.

> ⚠️ 정답값을 담는 변수를 `long long`형으로 선언하지 않으면 `interger overflow` 발생!

<br/>

## 최종 제출 코드

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[10005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    long long res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = a[i] + a[j];
            // lower_bound : 찾으려는 값과 같거나 큰 숫자가 몇 번째에서 처음 등장하는지 찾기 위함
            int l = lower_bound(a + (j + 1), a + n, -sum) - a;
            // upper_bound : 찾으려는 값보다 큰 숫자가 몇 번째에서 처음 등장하는지 찾기 위함
            int u = upper_bound(a + (j + 1), a + n, -sum) - a;
            res += (u - l);
        }
    }
    cout << res;
    return 0;
}
```
