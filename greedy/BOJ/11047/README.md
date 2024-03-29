# 동전 0 🥈

```cpp
#include <iostream>
using namespace std;

int n, k;
int coin[11];
int res;
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        if (k < coin[i]) continue;
        int num = k / coin[i];
        res += num;
        k -= coin[i] * num;
        if (k == 0) break;
    }
    cout << res << '\n';
}
```

👉 사용할 수 있는 가장 큰 금액의 동전을 많이 사용하는 전략을 취해야 한다.

> ex) `620` = `500 * 1 + 100 * 1 + 10 * 2`

🤔 왜 위 전략이 통할까?

- 그 이유는 사용하는 동전을 보면 **큰 액수의 동전이 작은 액수의 동전의 배수이기 때문이다.**
- 큰 액수의 동전을 자신의 약수인 작은 액수의 동전 여러개로 교체하면 동전 개수는 늘어지만, 반대로 작은 액수의 동전 여러개를 큰 액수의 동전으로 바꾸면 동전 개수는 줄어든다.
- **배수 성질이 성립하지 않으면, Greedy 알고리즘을 더 이상 사용할 수 없다.**
- 60, 50, 10원짜리 동전을 사용한다고 해보자. 60은 50보다 크지만, 50의 배수는 아니다. 220원을 표현하려고 할 때, 앞선 Greedy 알고리즘 전략을 사용하면 동전 7개를 사용하게 된다. 그러나 답은 6개이다. (50원짜리 4개, 10원짜리 2개)

> [문제 보러가기](https://www.acmicpc.net/problem/11047)
