# 보석 도둑 🥇

## 오답 코드

```cpp
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

pair<int, int> a[300001];
multiset<int> b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, num;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i].second >> a[i].first;
    }
    for (int i = 0; i < k; i++) {
        cin >> num;
        b.insert(num);
    }
    sort(a, a + n);
    long long res = 0;
    for (int i = n - 1; i >= 0; i--) {
        auto it = b.lower_bound(a[i].second);
        if (it == b.end()) continue;
        b.erase(*it); // ⚠️ multiset의 erase 함수에 값을 전달하면 해당 값을 모두 삭제한다! 하지만, 목적은 it가 가리키는 값만 삭제하는 것이다.
        res += a[i].first;
    }
    cout << res;
    return 0;
}
```

## 최종 제출 코드

```cpp
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

pair<int, int> a[300001];
multiset<int> b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, num;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i].second >> a[i].first;
    }
    for (int i = 0; i < k; i++) {
        cin >> num;
        b.insert(num);
    }
    sort(a, a + n); // 보석 가격 기준으로 오름차순 정렬
    long long res = 0;
    for (int i = n - 1; i >= 0; i--) {
        auto it = b.lower_bound(a[i].second); // 보석의 무게와 같거나 크지만 가장 작은 무게를 찾는다.
        if (it == b.end()) continue; // 없다면 pass
        b.erase(it); // 있다면 삭제. 이때, iterator 전달!!!
        res += a[i].first;
    }
    cout << res;
    return 0;
}
```

> [문제 보러가기](https://www.acmicpc.net/problem/1202)
