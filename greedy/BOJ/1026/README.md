# 보물 🥈

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[51];
int b[51];
int res;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    for (int i = 0; i < n; i++) {
        res += a[i] * b[n - i - 1];
    }
    cout << res << '\n';
}
```

👉 `S = A[0] × B[0] + ... + A[N-1] × B[N-1]` 일때, A의 값이 큰 것부터, B의 값이 작은 것부터 곱해서 더하거나 반대로 A의 값이 작은 것부터, B의 값이 큰 것부터 곱해서 더하면 된다.
