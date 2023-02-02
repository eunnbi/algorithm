# 멀티탭 스케줄링 🥇

## 오답 코드

```cpp
#include <iostream>
#include <vector>

using namespace std;

int n, k;
int s[102];
int freq[102];
vector<int> tab;
int res;

int main() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> s[i];
        freq[s[i]]++;
    }
    if (n >= k) {
        cout << 0 << '\n';
        return 0;
    }
    for (int i = 0; i < k; i++) {
        freq[s[i]]--;
        int isExist = 0;
        for (int j = 0; j < tab.size(); j++) {
            if (tab[j] == s[i]) {
                isExist = 1;
                break;
            }
        }
        if (isExist) continue;
        if (tab.size() < n) {
            tab.push_back(s[i]);
        }
        else { // ⚠️ 어떤 플러그를 빼야 할지 고르는 로직이 틀림
            int mn = 1000000;
            int mIdx = -1;
            for (int j = 0; j < tab.size(); j++) {
                if (mn > freq[tab[j]]) {
                    mn = freq[tab[j]];
                    mIdx = j;
                }
            }
            tab[mIdx] = s[i];
            res++;
        }
    }
    cout << res << '\n';
    return 0;
}
```

멀티탭이 다 사용 중일 때, 어떤 전기용품의 플러그를 빼야할지 고르는 로직이 틀렸다. 위 코드는 가장 적게 사용할 전기용품의 플러그를 고른다. 하지만, 아래 반례를 보면 이 방법이 옳지 않다는 것을 증명한다. **즉, 전기용품의 사용횟수가 아닌 사용시점이 기준이 되어야 한다. 가장 나중에 사용하거나 미래에 사용하지 않을 전기용품의 플러그를 골라야 한다.**

> **반례**
>
> ```
> 입력
> 2 15
> 3 2 1 2 1 2 1 2 1 3 3 3 3 3 3
>
> 출력: 7
> 정답: 2
> ```

<br/>

## 최종 제출 코드

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int s[102]; // 전기용품 사용 순서
bool power[102]; // 전기용팜이 멀티탭에 꽃혀 있는가?

int main() {
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> s[i];
    }

    int cnt = 0; // 멀티탭에 꽃혀 있는 전기용품 개수
    int res = 0;
    for (int i = 1; i <= k; i++) {
        int cur = s[i];
        if (power[cur]) continue; // 이미 멀티탭에 꽂혀 있으면 넘어감
        if (cnt < n) { // 멀티탭에 자리가 남으면
            power[cur] = true;
            cnt++;
        }
        else {
            // 멀티탭에 꽂혀 있는 전기용품 중 배열 s에서 앞으로 가장 빨리 나올 인덱스와 값을 저장함.
            vector<pair<int, int>> idx;
            for (int x = 1; x <= k; x++) {
                if (!power[x]) continue;
                bool vis = false;
                for (int y = i + 1; y <= k; y++) {
                    if (s[y] == x) {
                        idx.push_back({ y, x });
                        vis = true;
                        break;
                    }
                }
                if (!vis) idx.push_back({ k + 1, x }); // 더 이상 s에서 나오지 않는다면 인덱스를 가장 큰 값으로 처리
            }
            sort(idx.begin(), idx.end(), greater<pair<int, int>>());
            int target = idx[0].second;
            power[target] = false;
            power[s[i]] = true;
            res++;
        }
    }
    cout << res << '\n';
    return 0;
}
```

> [문제 보러가기](https://www.acmicpc.net/problem/1700)
