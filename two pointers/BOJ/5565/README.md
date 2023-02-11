# 회전초밥 🥈

```cpp
#include <iostream>
#include <deque>
using namespace std;

int exist[3002];
deque<int> a;

int main() {
    int n, d, k, c;
    cin >> n >> d >> k >> c;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        a.push_back(num);
    }

    // 원형 배열 문제라서 뒤로 배열 원소 추가
    for (int i = 0; i < n; i++) {
        a.push_back(a[i]);
    }

    int size = a.size();
    int left = 0;
    int right = 1;
    int mx = 0;
    int num = 1; // 배열 구간 내 중복되지 않은 초밥 개수
    exist[a[left]]++;
    while (left < size && right < size) {
        if (!exist[a[right]]) num++;
        exist[a[right]]++;
        if (right - left + 1 == k) {
            if (exist[c]) mx = max(mx, num);
            else mx = max(mx, num + 1);
            exist[a[left]]--;
            if (exist[a[left]] == 0) num--;
            left++;
        }
        right++;
    }
    cout << mx;
    return 0;
}
```

👉 원소의 개수가 `k`인 배열 구간에서 중복되지 않은 원소의 개수를 탐색하며 최대값을 구하는 문제이다.

> [문제 보러가기](https://www.acmicpc.net/problem/2531)
