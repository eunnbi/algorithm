# 크게 만들기 🥇

## 수정 전 제출 코드

```cpp
#include <iostream>
#include <deque>
using namespace std;

int n, k;
string s;
deque<int> res;
int main() {
    cin >> n >> k;
    cin >> s;
    for (int i = 0; i < n; i++) {
        while (k && !res.empty() && res.back() < s[i] - '0') {
            res.pop_back();
            k--;
        }
        res.push_back(s[i] - '0');
    }
    while (!res.empty()) {
        cout << res.front();
        res.pop_front();
    }
    return 0;
}
```

👉 **앞자리 수가 클수록 전체 수가 더 커진다는 성질을 이용하자. 자신보다 앞에 있는 수가 자신보다 작고 기회가 남아 있다면 해당 수를 지우는 전략을 취한다.**

하지만 반례가 존재한다.

```
10 5
9993333932
답: 99993
출력: 999932
```

- 최종 출력 숫자는 `n-k` 자리여야 하는데, 위 코드를 실행하면 `n-k` 자리 이상의 숫자가 출력되는 예시가 존재한다.
- 자릿수를 제한하는 코드를 `for`문 혹은 `while`문에 추가해야 하는데 `while`문에 코드를 추가하는 것이 더 안전하다고 판단하여 아래와 같이 코드를 수정했다.

<br/>

## 최종 제출 코드

```cpp
#include <iostream>
#include <deque>
using namespace std;

int n, k;
int k_copy; // k의 복사본
string s;
deque<int> res;
int num;
int main() {
    cin >> n >> k;
    cin >> s;
    k_copy = k;
    for (int i = 0; i < n; i++) {
        while (k && !res.empty() && res.back() < s[i] - '0') {
            res.pop_back();
            k--;
        }
        res.push_back(s[i] - '0');
    }

    // ⚠️ 최종 출력될 숫자가 "n - k" 자리여야 함.  본래의 k의 값이 앞선 for문에서 수정되기 때문에 복사본 이용
    while (num < n - k_copy) {  
        num++;
        cout << res.front();
        res.pop_front();
    }
    return 0;
}
```
