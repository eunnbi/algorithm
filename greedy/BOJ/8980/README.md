# 택배 🥇

## 오답 코드

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

vector<tuple<int, int, int>> v;
int box[2002];
int main() {
    int n, c, m;
    cin >> n >> c;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({ a, b, c });
    }
    sort(v.begin(), v.end());

    int size = v.size();
    int res = 0;
    int truck = 0;
    for (int i = 0; i < size; i++) {
        int x, y, z; // x: 보내는 마을, y: 받는 마을, z: 박스 개수
        tie(x, y, z) = v[i];
        if (box[x]) { // 보내는 마을 기준으로 박스를 내림.
            truck -= box[x];
            res += box[x];
            box[x] = 0;
        }
        if (truck + z <= c) {
            truck += z;
            box[y] += z;
        }
        else {
            int w = c - truck;
            truck += w;
            box[y] += w;
        }
    }
    cout << res << '\n';
    return 0;
}
```

- 관찰 결과, **보내는 박스들 중 가장 빨리 내릴 수 있는 박스를 우선적으로 싣는 것**이 배송할 수 있는 최대 박스 수를 구할 수 있다고 판단했다.
- 그래서, 보내는 마을이 같다면 가장 작은 마을 번호 순대로 정렬하도록 했다.
- 하지만, 위 코드의 큰 문제점은 박스를 내려야 할 모든 마을에 방문하지 않는다는 것이다. 보내는 마을 기준으로 박스를 내리기 때문에 반례가 존재한다. (예제 코드마저도 통과하지 못함.)
- 그래서 **역으로 생각하여 박스를 받는 마을 기준으로 정렬하고, `vector`를 순회하여 받는 마을에서 박스를 최대 몇 개 받을 수 있는지 구하는 코드로 수정했다.**

<br/>

## 최종 제출 코드

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

vector<tuple<int, int, int>> v;
int truck[2002]; // 각 마을에서 트럭에 싣는 박스 개수

int main() {
    int n, c, m;
    cin >> n >> c;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        v.push_back({ y, x, z });
    }

    sort(v.begin(), v.end()); // 받는 마을 기준 오름차순 정렬
    int size = v.size();
    int res = 0;
    for (int i = 0; i < size; i++) {
        int x, y, z;
        tie(y, x, z) = v[i];
        bool loadable = true;
        for (int j = x; j < y; j++) { // 보내는 마을부터 순회하여 받을 수 있는 박스 개수를 구함.
            z = min(z, c - truck[j]); // truck[j]: j번 마을에서 실은 박스 개수
            if (!z) {
                loadable = false;
                break;
            }
        }
        if (loadable) {
            res += z;
            for (int j = x; j < y; j++) truck[j] += z;
        }
    }
    cout << res << '\n';
    return 0;
}
```

- 빨리 내릴 수 있는 박스를 많이 실을수록 더 많은 박스를 배송할 수 있기 때문에, 받는 마을을 기준으로 오름차순 정렬했다.
- `vector`를 순회하며 받는 마을에서 받을 수 있는 박스 개수를 구한다.

> [문제 보러가기](https://www.acmicpc.net/problem/8980)
