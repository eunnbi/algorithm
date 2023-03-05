#include <iostream>
using namespace std;

int n;
int lc[100002];
int rc[100002];
int p[100002];
bool vis[100002];

int main() {
    int a, b, c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        if (b != -1) {
            lc[a] = b;
            p[b] = a;
        }
        if (c != -1) {
            rc[a] = c;
            p[c] = a;
        }
    }
    int lastNode = 1;
    while (rc[lastNode]) lastNode = rc[lastNode];
    int cur = 1;
    int res = 0;
    while (true) {
        if (lc[cur] && !vis[lc[cur]]) {
            cur = lc[cur];
            vis[cur] = true;
            res++;
        }
        else if (rc[cur] && !vis[rc[cur]]) {
            cur = rc[cur];
            vis[cur] = true;
            res++;
        }
        else if (lastNode == cur) break;
        else if (p[cur]) {
            cur = p[cur];
            res++;
        }
    }
    cout << res;
    return 0;
}