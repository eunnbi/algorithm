# 로프 🥈

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int w[100001];
int res;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    sort(w, w + n);
    for (int i = n - 1; i >= 0; i--) {
        int weight = w[i] * (n - i); // i번재 로프를 포함할 때 들 수 있는 최대 무게
        if (res < weight) {
            res = weight;
        }
    }
    cout << res << '\n';
}
```

👉 최대한 많은 무게를 들기 위해서는 많은 무게를 들 수 있는 로프 순으로 선택해야 한다.

> [문제 보러가기](https://www.acmicpc.net/problem/2217)
