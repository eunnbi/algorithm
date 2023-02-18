# 문자열 지옥에 빠진 호석 🥇

## 시간 초과나는 코드

```cpp
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

char a[12][12];
queue<tuple<int, int, int>> q;
int dx[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int dy[8] = { 1, 0, -1, 0, 1, -1, 1, -1 };

int main() {
    int n, m, k;
    string s;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    // ⚠️ 문자열을 입력 받을 때마다 bfs를 수행하면 시간초과가 발생한다. (k는 최대 1000)
    while (k--) {
        cin >> s;
        long long res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i][j] != s[0]) continue;
                q.push({ 0, i, j });
                while (!q.empty()) {
                    int idx, x, y;
                    tie(idx, x, y) = q.front(); q.pop();
                    if (idx == s.size() - 1) {
                        res++;
                        continue;
                    }
                    for (int k = 0; k < 8; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx == 0) nx = n;
                        if (ny == 0) ny = m;
                        if (nx > n) nx = 1;
                        if (ny > m) ny = 1;
                        if (a[nx][ny] != s[idx + 1]) continue;
                        q.push({ idx + 1, nx, ny });
                    }
                }
            }
        }
        cout << res << '\n';
    }
    return 0;
}
```

문자열을 입력받을 때마다 bfs를 수행하여 시간초과가 발생한다. (문자열의 개수가 최대 1000개) 하지만, 문자열의 길이는 최대 5이므로 문자열을 입력받기 전에 bfs를 미리 수행하여 만들 수 있는 모든 문자열의 경우의 수를 구한다. 이후 문자열을 입력받을 때 미리 구한 경우의 수를 출력한다. 문자열을 만들 수 있는 경우의 수는 `map`을 사용하여 저장한다.

<br/>

## 최종 제출 코드

### 재귀

```cpp
#include <iostream>
#include <map>
using namespace std;

int n, m, k;
char a[12][12];
map<string, int> res;
int dx[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int dy[8] = { 1, 0, -1, 0, 1, -1, 1, -1 };

void bfs(int x, int y, string s) {
    if (s.size() > 5) return; // 문자열의 길이가 5이하라는 제한 이용

    // 경우의 수 저장
    auto itr = res.find(s);
    if (itr != res.end()) res[s]++;
    else res[s] = 1;

    for (int dir = 0; dir < 8; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx == 0) nx = n;
        if (ny == 0) ny = m;
        if (nx > n) nx = 1;
        if (ny > m) ny = 1;
        string str = "";
        str = a[nx][ny]; // char to string
        bfs(nx, ny, s + str);
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    // BFS : 만들 수 있는 모든 문자열의 경우의 수를 구한다.
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            string start = "";
            start = a[i][j]; // char to string
            bfs(i, j, start);
        }
    }
    while (k--) {
        string s;
        cin >> s;
        cout << res[s] << '\n';
    }
    return 0;
}
```

### 큐와 반복문

```cpp
#include <iostream>
#include <map>
#include <queue>
using namespace std;

char a[12][12];
queue<tuple<string, int, int>> q;
map<string, int> res;
int dx[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int dy[8] = { 1, 0, -1, 0, 1, -1, 1, -1 };

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    // BFS : 만들 수 있는 모든 문자열의 경우의 수를 구한다.
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            string start = "";
            start = a[i][j]; // char to string
            q.push({ start, i, j });
            while (!q.empty()) {
                string substr;
                int x, y;
                tie(substr, x, y) = q.front(); q.pop();
                if (substr.size() > 5) continue; // 문자열의 길이가 5이하라는 제한 이용

                // 경우의 수 저장
                auto itr = res.find(substr);
                if (itr != res.end()) res[substr]++;
                else res[substr] = 1;

                for (int dir = 0; dir < 8; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (nx == 0) nx = n;
                    if (ny == 0) ny = m;
                    if (nx > n) nx = 1;
                    if (ny > m) ny = 1;
                    string str = "";
                    str = a[nx][ny]; // char to string
                    q.push({ substr + str, nx, ny });
                }
            }
        }
    }
    while (k--) {
        string s;
        cin >> s;
        cout << res[s] << '\n';
    }
    return 0;
}
```
