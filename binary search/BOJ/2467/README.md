# 용액 🥇

```cpp
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int n;
int a[100001];
int res[2];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int mn = 2000000001;
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(a, a + n, -a[i]) - a;
        if (idx < n && i != idx && mn > abs(a[i] + a[idx])) {
            mn = abs(a[i] + a[idx]);
            res[0] = a[i];
            res[1] = a[idx];
        }
        if (idx < n - 1 && i != idx + 1 && mn > abs(a[i] + a[idx + 1])) {
            mn = abs(a[i] + a[idx + 1]);
            res[0] = a[i];
            res[1] = a[idx + 1];
        }
        if (idx != 0 && i != idx - 1 && mn > abs(a[i] + a[idx - 1])) {
            mn = abs(a[i] + a[idx - 1]);
            res[0] = a[i];
            res[1] = a[idx - 1];
        }
    }
    sort(res, res + 2);
    cout << res[0] << ' ' << res[1] << '\n';
    return 0;
}
```

- `lower_bound` 함수는 이진탐색을 통해 key값과 같거나 크지만 가장 작은 값의 주소값을 반환한다. 하지만, 그런 값이 존재하지 않다면 배열의 크기를 반환한다.
- 그래서, `lower_bound` 함수의 반환값을 `idx`라 가정하면, `nums[idx]`는 `-nums[i]`와 같거나 큰 원소 중에 가장 작은 원소이거나 `idx` 값은 배열의 크기일 것이다.
- 그래서 `nums[i]`와 더했을 때 값이 0과 가까운 원소는 `nums[idx]`, `nums[idx + 1]`, `nums[idx - 1]` 셋 중 하나일 것이다.
