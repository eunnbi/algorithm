# 주식 🥈

## 제출 코드

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int t, n;
int s[1000001];
long long res;
int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        int start = 0;
        res = 0; // ⚠️ res 값 초기화!!
        while (true) {
            // 1. start ~ n - 1 구간의 최댓값 인덱스 찾기
            int idx = max_element(s + start, s + n) - s;

            // 2. start ~ idx - 1 구간의 주식 구매
            for (int i = start; i < idx; i++) {
                res -= s[i];
            }
            res += s[idx] * (idx - start); // 3. idx에서 주식 판매
            start = idx + 1; // 4. 다음 구간을 이동
            if (idx == 0 || idx >= n - 2) break; // 만약 최댓값의 인덱스가 0이거나 n - 2 이상이면 종료
        }
        cout << res << '\n';
    }
}
```

👉 관찰 결과, 배열의 어떤 구간의 최댓값을 만나기 전까지는 주식을 계속 판매하고, 최댓값을 만나면 주식을 판매하는 패턴을 이용하면 된다.

먼저 전체 구간의 최댓값을 찾아, 계산하고, 뒤로 구간이 남아 있다면 해당 구간의 최댓값을 찾아 또 계산하는 식의 코드를 작성했다.

> ⚠️ 주의: 여러 테스트케이스가 입력으로 주어지는 경우, 공통으로 사용되는 변수는 초기화가 반드시 필요하다!

<br/>

## Best Solution

이 문제는 시간제한이 5초라서 제출한 코드가 통과할 수 있었던 것 같다.
아래 코드는 모범 답안이다.

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int t, n;
int s[1000001];
int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        long long res = 0;
        int mx = s[n - 1];
        // 배열의 오른쪽부터 탐색하여 최댓값을 찾고, 최댓값에서 현재 주식값을 뺀 값을 더해간다.
        for (int i = n - 2; i >= 0; i--) {
            mx = max(mx, s[i]);
            res += mx - s[i];
        }
        cout << res << '\n';
    }
}
```
