# 공주님의 정원 🥇

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> s[100001];
int now = 301;
int res, mx;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        s[i].first = a * 100 + b;
        s[i].second = c * 100 + d;
    }
    sort(s, s + n); // 꽃이 피는 순서대로 정렬, 꽃이 피는 시간이 같다면 지는 순대로 정렬
    for (int i = 0; i < n; i++) {
        if (now > 1130) break;

        // 현재 피어 있는 꽃들 중 가장 오래 피는 꽃 찾기
        if (now >= s[i].first) {
            mx = max(mx, s[i].second);
        }

        // 미래에 필 꽃인 경우
        if (now < s[i].first) {
            if (mx == 0) { // 현재 피어 있는 꽃이 없는 경우 (첫번째 조건을 만족하지 않는 경우)
                res = 0;
                break;
            }
            else { // 현재 피어 있는 꽃이 있는 경우
                res++;
                now = mx;
                mx = 0;
                i--;
            }
        }
    }
    if (mx != 0) { // 마지막까지 확인!
        now = mx;
        res++;
    }
    if (now <= 1130) {
        res = 0;
    }
    cout << res << '\n';
    return 0;
}
```

👉 입력 받은 모든 꽃이 필 수 있다고 가정했을 때, 현재 피어 있는 꽃들 중 가장 오래 피는 꽃을 선택하면 된다.

> 현재 피어 있는 모든 꽃을 고려해야 하고, 꽃들이 피는 순서대로 정렬해야 한다.
