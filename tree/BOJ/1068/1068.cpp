#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int delNode;
int p[51];
vector<int> child[51];
int res;

void traversal(int cur) {
    if (child[cur].size() == 0) res++;
    for (int nxt: child[cur]) {
        traversal(nxt);
    }
}

int main() {
    int n, num, root;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num == -1) root = i;
        else {
            p[i] = num;
            child[num].push_back(i);
        }
    }
    cin >> delNode;
    if (delNode == root) {
        cout << 0;
        return 0;
    }
    int parent = p[delNode];
    child[parent].erase(find(child[parent].begin(), child[parent].end(), delNode));
    traversal(root);
    cout << res;
    return 0;
}