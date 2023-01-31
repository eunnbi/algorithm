# 수 묶기 🥇

## 제출 코드

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int s[51];
int res;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s, s + n);
    if (n == 1) {
        cout << s[0] << '\n';
        return 0;
    }
    // 이진 검색을 통해 0과 같거나 크지만 가장 작은 값을 찾는다.
    int idx = lower_bound(s, s + n, 0) - s;
    if (s[idx] == 0) { // 수열에 0이 포함되어 있다면
        int i = n - 1;
        while (i > idx + 1) {
            if (s[i] == 1 || s[i - 1] == 1) {
                res += s[i] + s[i - 1];
            }
            else {
                res += s[i] * s[i - 1];
            }
            i -= 2;
        }
        if ((n - 1 - idx) & 1) {
            res += s[idx + 1];
        }
        i = 0;
        while (i < idx) {
            res += s[i] * s[i + 1];
            i += 2;
        }
    }
    else { // 수열에 0이 없다면
        int i = n - 1;
        while (i > idx) {
            if (s[i] == 1 || s[i - 1] == 1) {
                res += s[i] + s[i - 1];
            }
            else {
                res += s[i] * s[i - 1];
            }
            i -= 2;
        }
        if ((n - idx) & 1) {
            res += s[idx];
        }
        i = 0;
        while (i < idx - 1) {
            res += s[i] * s[i + 1];
            i += 2;
        }
        if (idx & 1) {
            res += s[idx - 1];
        }
    }
    cout << res << '\n';
    return 0;
}
```

👉 **관찰 결과, 양수는 양수끼리, 음수는 음수끼리 곱하고 더하는 것이 결과값이 최대가 된다. (0은 음수에 포함) 이때 정렬이 필요하며, 양수는 최대값부터 곱하면서 더하고, 음수는 최소값부터 곱하면서 더한다. 예외처리로 1은 어떤 수와 곱하지 않고, 무조건 더한다.**

> 입력받은 수열에 0이 포함된 경우랑 포함되지 않은 경우랑 인덱스 처리하는 것이 조금씩 달라서 if문으로 분기했다. 하지만, 적용된 원리는 동일하다.

## Best Solution

아래 코드는 모범답안으로, 제출한 코드와 거의 비슷한 전략을 사용했지만, 훨씬 구현이 깔끔한 코드이다.

- 양수와 음수를 한 배열에 모두 저장하지 않고, 처음부터 각각 다른 vector에 저장한다.
- 이때, 예외 처리로 1은 vector에 넣지 않고, 결과값을 1 증가시킨다. (1은 곱할 필요가 없기 때문이다.)
- 처음부터 양수와 음수를 다른 자료형에 저장하여 인덱스 처리하는데 있어서 문제가 발생하지 않도록 한다.
- 양수는 오름차순 정렬, 음수는 내림차순 정렬하여 vector의 오른쪽부터 곱하면서 더하는 계산을 수행한다. 이때 개수가 홀수이면 첫번째 요소를 따로 더한다. 그러면 양수는 최댓값 순대로, 음수는 최솟값 순대로 곱하면서 더하므로 최종 결과값은 최대가 된다.

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, s;
int res;
vector<int> seqP, seqN; // 각각 양수와 음수(0포함)를 저장할 vector

void seqSum(vector<int>& v) {
    int size = v.size();
    for (int i = size - 1; i > 0; i -= 2) {
        res += v[i] * v[i - 1];
    }
    if (size & 1) {
        res += v[0];
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == 1) res++; // 1이면 결과값 1 증가
        else if (s > 0) { // 양수면
            seqP.push_back(s);
        }
        else { // 음수면
            seqN.push_back(s);
        }
    }
    sort(seqP.begin(), seqP.end()); // 오름차순 정렬
    sort(seqN.begin(), seqN.end(), greater<>()); // 내림차순 정렬
    seqSum(seqP);
    seqSum(seqN);
    cout << res << '\n';
    return 0;
}
```

> [문제 보러가기](https://www.acmicpc.net/problem/1744)
