# 선 긋기 🥇

## 오답 코드

시간초과가 발생하고, 반례가 존재하는 코드이다.

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> s[1000001];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i].first >> s[i].second;
    }

    sort(s, s + n);  // 시작점 기준 오름차순 정렬
    int res = s[0].second - s[0].first;
    for (int i = 1; i < n; i++) {
        if (s[i].first < s[i - 1].second) {
            res += s[i].second - s[i - 1].second; // ⚠️ 이 부분에서 문제 발생!
        }
        else {
            res += s[i].second - s[i].first;
        }
    }
    cout << res << '\n';
    return 0;
}
```

위 코드는 시작점 기준으로 배열을 오름차순 정렬하고, 배열을 순회하며 결과값을 구한다. 이때 첫번째 if문 안에 실행되는 코드에서 문제가 발생한다. **정렬 결과, 끝점이 무조건 오름차순이지 않을 것이다. 그러므로, `s[i].second - s[i - 1].second` 식의 값이 음수가 될 수 있다. 하지만 전략 상, 결과값을 절대 감소해서는 안된다.** 그래서 해당 코드를 수정해야 한다.

> **반례**
>
> ```
> 입력
> 4
> 5 10
> 7 35
> 15 20
> 25 30
>
> 출력: 20
> 답: 30
> ```

위 코드의 시간복잡도는 `O(NlogN)`이고, `N`은 1,000,000 이하의 자연수이다. 그러면 보통 시간초과가 나질 않는데, 제출 결과, 시간 초과가 발생했다. 입력에서 시간이 오래 걸리는 것으로 예상해 아래 코드를 추가하기로 했다.

```cpp
ios::sync_with_stdio(0);
cin.tie(0);
```

<br/>

## 최종 제출 코드

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> s[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i].first >> s[i].second;
    }

    sort(s, s + n);
    int res = s[0].second - s[0].first;
    for (int i = 1; i < n; i++) {
        if (s[i].first < s[i - 1].second) {
            if (s[i].second < s[i - 1].second) { // if문 추가
                s[i].second = s[i - 1].second;
            } else {
                res += s[i].second - s[i - 1].second;
            }
        }
        else {
            res += s[i].second - s[i].first;
        }
    }
    cout << res << '\n';
    return 0;
}
```

> [문제 보러가기](https://www.acmicpc.net/problem/2170)
