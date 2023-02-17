# 수업 🥇

```cpp
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

pair<int, int> a[500001];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n, greater<pair<int, int>>());
    multiset<int> group;
    for (int i = 0; i < n; i++) {
        auto itr = group.lower_bound(a[i].second);
        if (itr == group.begin()) group.insert(1);
        else {
            int size = *prev(itr);
            group.erase(prev(itr));
            group.insert(size + 1);
        }
    }
    cout<< group.size();
    return 0;
}
```

**그리디**와 **이진 검색 트리**를 이용하여 해결할 수 있다.

- 키 큰 사람부터 그룹에 넣어주면, 앞서 그룹에 할당된 학생들의 키는 현재 그룹을 할당하려는 학생의 키보다 크다.
- 따라서 `i`번째 학생은 그룹의 크기가 `ki`보다 작은 그룹 중 하나에 할당시키면 된다.
- 이때, 그룹의 개수는 최소가 되야 하므로 그룹의 크기가 `ki`보다 작은 그룹 중 크기가 가장 큰 그룹을 선택하면 된다.
- `N`의 크기가 500,000 이하이므로 그룹의 크기를 탐색하기 위해 이진 검색 트리의 `lower_bound`를 사용한다.
