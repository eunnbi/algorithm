# 무한 수열 🥇

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

long long n, p, q;
unordered_map<long long, long long> a;
long long solve(long long num) {
    if (num == 0) return 1;
    else if (a[num] != 0) return a[num];
    return a[num] = solve(num / p) + solve(num / q);
}

int main() {
    cin >> n >> p >> q;
    cout << solve(n);
    return 0;
}
```

👉 **재귀**와 **메모이제이션**을 이용하여 답을 구한다. 이때, `N`은 `10^12` 이하이기 때문에, 배열 대신 해시를 이용하여 메모이제이션한다.
