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
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            string start = "";
            start = a[i][j];
            q.push({ start, i, j });
            while (!q.empty()) {
                string substr;
                int x, y;
                tie(substr, x, y) = q.front(); q.pop();
                if (substr.size() > 5) continue;
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
                    str = a[nx][ny];
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