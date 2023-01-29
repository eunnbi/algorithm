# ATM 🥈

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int p[1002];
int res;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; i++) {
        p[i] = p[i] + p[i - 1]; // 누적 합
        res += p[i];
    }
    cout << res << '\n';
}
```

👉 돈을 인출하는 데 제일 오래 걸리는 사람을 앞에 둘수록 그 만큼 기다리는 시간이 계속 누적되기 때문에, 돈을 인출하는 데 가장 적게 걸리는 사람 순으로 시간을 누적하여 더해야 한다.
