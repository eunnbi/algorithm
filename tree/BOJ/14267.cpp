#include <iostream>
#include <vector>
using namespace std;

vector<int> child[100002];
int res[100002];
void traversal(int cur) {
    for (int nxt: child[cur]) {
        res[nxt] += res[cur];
        traversal(nxt);
    }
}
int main() {
    int n, m, u, v, root;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> u;
        if (u == -1) root = i;
        else {
            child[u].push_back(i);
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        res[u] += v;
    }
    traversal(root);
    for (int i = 1; i <= n; i++) {
        cout << res[i] << ' ';
    }
    return 0;
}