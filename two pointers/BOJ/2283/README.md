# 구간 자르기 🥇

```cpp
#include <iostream>
#define MAX 1000001
using namespace std;

int a[1000001]; //💡 a[i]: (i - 1)와 i에 포함된 수직선의 개수

int main() {
    int n, k, l, r;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        for (int j = l + 1; j <= r; j++) a[j]++;
    }

    int left = 0;
    int right = 0;
    int sum = 0;
    while (left < MAX && right < MAX) {
        if (sum < k) sum += a[++right];
        else if (sum > k) sum -= a[++left];
        else {
            cout << left << ' ' << right;
            return 0;
        }
    }
    cout << "0 0";
    return 0;
}
```

👉 **배열의 구간합을 구하는 문제지만, 배열의 원소들이 직접 입력되는 것이 아니라 입력에 따라서 배열의 원소를 채워나가야 한다.**
