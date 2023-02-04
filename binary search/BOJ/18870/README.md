# 좌표 압축 🥈

## 수정 전 코드

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> v; // 값, 인덱스
int temp[1000001];
int res[1000001];

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back({ num, i });
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        int idx = v[i].second; // 원래 인덱스
        int first = lower_bound(v.begin(), v.begin() + i, v[i], comp) - v.begin(); // 해당 요소가 처음 등장하는 인덱스
        if (temp[first]) temp[i] = temp[first]; // 만약 답을 이미 구했다면 복사
        else if (first == 0) temp[i] = 0; // 첫 요소라면 답은 0
        else temp[i] = temp[first - 1] + 1; // 처음 답을 구한다면 자신보다 작지만 큰 요소의 답에서 1 증가
        res[idx] = temp[i];
    }
    for (int i = 0; i < n; i++) {
        cout << res[i] << ' ';
    }
    return 0;
}
```

> 배열의 요소 중복을 제거하고 이진 탐색을 적용하면 될 거 같았는데 중복 제거하는 방법을 몰라 다른 방법을 진행했다.

## 최종 제출 코드

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int a[1000001];
vector<int> v;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        v.push_back(a[i]);
    }

    sort(v.begin(), v.end()); // 정렬
    v.erase(unique(v.begin(), v.end()), v.end()); // 중복 제거 🔥
    for (int i = 0; i < n; i++) {
        cout << lower_bound(v.begin(), v.end(), a[i]) - v.begin() << ' ';
    }
    return 0;
}
```

> [문제 보러가기](https://www.acmicpc.net/problem/18870)
