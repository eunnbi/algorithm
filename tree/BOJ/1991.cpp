#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int lc[30];
int rc[30];

void preorder(int cur) {
    cout << (char)(cur + 'A' - 1);
    if (lc[cur]) preorder(lc[cur]);
    if (rc[cur]) preorder(rc[cur]);
}
void inorder(int cur) {
    if (lc[cur]) inorder(lc[cur]);
    cout << (char)(cur + 'A' - 1);
    if (rc[cur]) inorder(rc[cur]);
}
void postorder(int cur) {
    if (lc[cur]) postorder(lc[cur]);
    if (rc[cur]) postorder(rc[cur]);
    cout << (char)(cur + 'A' - 1);
}
int main() {
    int n;
    char k, l, r;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k >> l >> r;
        if (l != '.') lc[k - 'A' + 1] = l - 'A' + 1;
        if (r != '.') rc[k - 'A' + 1] = r - 'A' + 1;
    }
    preorder(1);
    cout << '\n';
    inorder(1);
    cout << '\n';
    postorder(1);
    return 0;
}
