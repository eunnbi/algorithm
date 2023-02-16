# 문제 추천 시스템 Version 1 🥇

```cpp
#include <iostream>
#include <set>
#include <map>
using namespace std;

set<pair<int, int>> a;
int level[100002]; // 문제의 난이도를 저장

int main() {
    int n, p, l, m;
    string order;
    cin >> n;
    while (n--) {
        cin >> p >> l;
        a.insert({ l, p });
        level[p] = l;
    }
    cin >> m;
    while (m--) {
        cin >> order;
        if (order == "add") {
            cin >> p >> l;
            a.insert({ l, p });
            level[p] = l;
        }
        else if (order == "solved") {
            cin >> p;
            a.erase({ level[p], p });
        }
        else {
            cin >> p;
            if (p == 1) cout << (*prev(a.end())).second << '\n';
            else cout << (*a.begin()).second << '\n';
        }
    }
    return 0;
}
```

👉 난이도가 최소인 문제와 최대인 문제를 `O(logN)`에 구할 수 있도록 이진 검색 트리를 이용했다.
