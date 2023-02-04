# 멀티버스 II

## 오답 코드

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int m, n;
vector<pair<int, int>> s[101];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            s[i].push_back({ num, j });
        }
    }
    for (int i = 0; i < m; i++) {
        sort(s[i].begin(), s[i].end());
    }
    int res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            bool isPossible = true;
            for (int k = 0; k < n; k++) {
                if (s[i][k].second != s[j][k].second) {
                    isPossible = false;
                    break;
                }
            }
            if (isPossible) res++;
        }
    }
    cout << res << '\n';
    return 0;
}
```

- 각 우주를 정렬하고, 두 우주를 비교했을 때 모든 요소의 원래 인덱스 값이 동일하다면 균등한 우주로 판단한다.
- 하지만, 배열에 중복 요소가 있는 경우에 답을 출력하지 못한다.

> **반례**
>
> ```
> 입력
> 2 3
> 40 10 10
> 30 10 20
>
> 출력: 1
> 답: 0
> ```

<br/>

## 최종 제출 코드

💡 **두 우주를 좌표압축했을 때 동일하면 균등한 우주이다.**

- 요소의 원래 인덱스를 비교하는 대신, 요소의 정렬순위를 비교하면 된다. 만약 같은 원소가 있다면 두 원소의 정렬 순위는 동일해야 한다.
- 정렬 순위를 구하기 위해서 좌표압축을 실행하면 된다.

> 원래 두 우주를 비교할 때 배열의 값 대소비교를 하기 때문에, 인덱스보다는 정렬 순위를 비교하는 것이 더 적합하다.

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int m, n;
int s[101][10001];

void compress(int* a) {
    vector<int> v(a, a + n);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
        }
        compress(s[i]);
    }

    int res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            bool isPossible = true;
            for (int k = 0; k < n; k++) {
                if (s[i][k] != s[j][k]) {
                    isPossible = false;
                    break;
                }
            }
            if (isPossible) res++;
        }
    }
    cout << res << '\n';
    return 0;
}
```

> [문제 보러가기](https://www.acmicpc.net/problem/18869)
