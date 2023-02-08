# 가장 긴 증가하는 부분 수열 2 🥇

## DP 이용

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[1001];
int dp[1001];

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		dp[i] = 1;
	}

	for (int i = 0; i < n; i++) {
		int mx = dp[i];
		for (int j = 0; j < i; j++) {
			if (a[i] <= a[j]) continue;
            mx = max(mx, dp[i] + dp[j]);
		}
		dp[i] = mx;
	}
	cout << *max_element(dp, dp + n);
	return 0;
}
```

dynamic programming을 이용하면 답은 구할 수 있지만, 시간 복잡도가 `O(N^2)`이고, `N`은 최대 1,000,000라서 시간초과가 발생한다.

<br/>

## 이분탐색 이용

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int a[1000001];
vector<int> LIS;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        // LIS가 비어 있거나, 마지막 원소가 a[i]보다 작다면
        if (LIS.empty() || LIS.back() < a[i]) LIS.push_back(a[i]);
        else {
            // 마지막 원소가 a[i]보다 크다면
            int idx = lower_bound(LIS.begin(), LIS.end(), a[i]) - LIS.begin();
            LIS[idx] = a[i];
        }
    }
    cout << LIS.size() << '\n';
    return 0;
}
```

- LIS가 비어 있거나, 마지막 원소가 `a[i]`보다 작다면 원소를 추가한다.
- 하지만, 마지막 원소가 `a[i]`보다 크다면 LIS의 이분탐색을 통해 `a[i]`와 같거나 크지만 작은 값의 위치를 찾아 값을 바꾼다. 값을 바꾸는 이유는 더 작은 값으로 교체해 이후 원소가 더 많이 들어올 수 있는 가능성을 넓힐 수 있기 때문이다. (최대한 많은 원소가 포함되어야 하기 때문에)

> [문제 보러가기](https://www.acmicpc.net/problem/12015)

<br/>

### LIS의 원소를 구한다면? 🤔

앞서 설명한 방법을 수행했을 때, 최종 LIS에 들어있는 원소들이 LIS를 구성하는 원소들은 아니다. 단지 LIS의 길이만 알 수 있다. 만약 LIS를 구성하는 원소들을 구하고 싶다면, 추가적인 처리가 필요하다.

배열 `p`를 하나 만들고, `p[i]` 에 수열의 i번째 원소가 LIS내에서 위치하는 인덱스를 저장한다. `p` 배열이 완성된 후 오른쪽부터 탐색하여 (LIS의 길이 - 1)부터 0까지 수가 가장 처음 나타나는 인덱스 값을 찾고 해당 인덱스에 위치한 수열의 값이 LIS를 구성하는 원소이다.

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int a[1000001];
int p[1000001];
vector<int> LIS;

void backtrace(int idx, int num) {
    if (idx < 0) return;
    if (p[idx] == num) {
        backtrace(idx - 1, num - 1);
        cout << a[idx] << ' ';
    }
    else backtrace(idx - 1, num);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        if (LIS.empty() || LIS.back() < a[i]) {
            LIS.push_back(a[i]);
            p[i] = LIS.size() - 1;
        }
        else {
            int idx = lower_bound(LIS.begin(), LIS.end(), a[i]) - LIS.begin();
            LIS[idx] = a[i];
            p[i] = idx;
        }
    }
    cout << LIS.size() << '\n';
    backtrace(n - 1, LIS.size() - 1);
    return 0;
}
```
