# 홍익 투어리스트 🥇

```cpp
#include <iostream>
#include <set>
using namespace std;

set<int> landmark;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q, num, x;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (x) landmark.insert(i);
    }
    int pos = 1;
    while (q--) {
        cin >> num;
        if (num == 1) {
            cin >> x;
            if (landmark.find(x) != landmark.end()) {
                landmark.erase(x);
            }
            else landmark.insert(x);
        }
        else if (num == 2) {
            cin >> x;
            pos = (pos + x - 1) % n + 1;
        }
        else {
            if (landmark.empty()) cout << -1 << '\n';
            else {
                auto it = landmark.lower_bound(pos);
                if (it != landmark.end()) {
                    cout << *it - pos << '\n';
                }
                else {
                    cout << n - pos + *landmark.begin() << '\n';
                }
            }
        }
    }
    return 0;
}
```

- `N`이 500,000 이하이고, `Q`가 100,000 이하라서 탐색하는데 시간 복잡도가 `O(logN)`인 이진 탐색 트리 자료구조를 선택했다. (이분 탐색을 이용하면 삽입 후 정렬을 해야 하지만, 이진 탐색 트리는 삽입 후 정렬할 필요가 없다.)
- 현재 위치와 가장 가까운 명소를 찾아야 하기 때문에 명소의 위치를 이진 검색 트리에 저장하고, `lower_bound`를 이용하여 답을 찾는다.

> [문제 보러가기](https://www.acmicpc.net/problem/23326)
