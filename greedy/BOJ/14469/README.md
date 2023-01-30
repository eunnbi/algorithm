# 소가 길을 건너간 이유 3 🥈

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> s[101];
int res;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i].first >> s[i].second;
    }
    sort(s, s + n); // 소가 도착한 순서대로 정렬, 도착한 시간이 같다면 검문 시간이 짧은 순대로 정렬
    for (int i = 0; i < n; i++) {
        if (res >= s[i].first) {
            res += s[i].second;
        }
        else {
            res = s[i].first + s[i].second;
        }
    }
    cout << res << '\n';
}
```

👉 도착한 순으로 검사를 받는 것이 농장을 입장하는데 걸리는 시간을 최소화한다. 만약 도착한 시간이 같다면 검문 시간이 짧은 순으로 검사를 받아야 한다. (정렬 필수!)
