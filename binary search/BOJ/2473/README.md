# 세 용액 🥇

## 오답 코드

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int a[5001];
int res[3];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    long long mn = 3000000002;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int idx = lower_bound(a + j + 1, a + n, -(a[i] + a[j])) - a;
            for (int k = -2; k <= 2; k++) {
                if (i == idx + k || j == idx + k) continue;
                if (idx + k < 0 || idx + k >= n) continue;
                if (mn > abs(a[i] + a[j] + a[idx + k])) {
                    mn = abs(a[i] + a[j] + a[idx + k]);
                    res[0] = a[i];
                    res[1] = a[j];
                    res[2] = a[idx + k];
                }
            }
        }
    }
    sort(res, res + 3);
    for (int val: res) cout << val << ' ';
    return 0;
}
```

- 위 코드는 `interger overflow`가 발생한다.
- 세 용액을 합하는 문제이고, 용액은 -10억부터 10억까지의 값을 갖는다. 그래서 세 용액을 합하면 최대 30억이므로 이는 `int`형 자료형을 넘어서 `long long` 자료형의 범위에 속한다.
- `abs(a[i] + a[j] + a[idx + k])` 에서 배열의 원소는 `int`형이고 원소들을 합해도 `int`형이기 때문에 `interger overflow`가 발생한다. 그래서 배열의 원소 자료형을 `long long`으로 선언해야 한다!

> **abs 함수**
>
> ```
> 헤더파일 : <cstdlib>
> 함수원형1 : int abs(int num);
> 함수원형2 : long int abs(long int num);
> 함수원형3 : long long int abs(long long int num);
> ```

<br/>

## 최종 제출 코드

```cpp
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

long long a[5001];
long long res[3];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    long long mn = 3000000002;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int idx = lower_bound(a + j + 1, a + n, -(a[i] + a[j])) - a;
            for (int k = -2; k <= 2; k++) {
                if (i == idx + k || j == idx + k) continue;
                if (idx + k < 0 || idx + k >= n) continue;
                if (mn > abs(a[i] + a[j] + a[idx + k])) {
                    mn = abs(a[i] + a[j] + a[idx + k]);
                    res[0] = a[i];
                    res[1] = a[j];
                    res[2] = a[idx + k];
                }
            }
        }
    }
    sort(res, res + 3);
    for (auto val: res) cout << val << ' ';
    return 0;
}
```

> [문제 보러가기](https://www.acmicpc.net/problem/2473)
