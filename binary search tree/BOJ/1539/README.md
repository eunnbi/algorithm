# 이진 검색 트리

## 시간 초과 나는 코드

균형이 유지되지 않는 일반 이진 검색 트리의 경우 노드를 추가할 때 시간 복잡도가 최악의 경우 `O(N)`이다. 이 코드의 최악의 경우 시간 복잡도는 `O(N^2)`이고, `N`은 `250,000` 이하이므로 시간초과가 발생한다.

```cpp
#include <iostream>
#include <cstdlib>
using namespace std;

long long res;
typedef struct _node {
    int key;
    struct _node* left;
    struct _node* right;
} Node;

typedef struct _tree {
    Node* root;
    int num;
} Tree;

void insert(Tree* ptree, int key) {
    int height = 0;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->key = key;
    Node* cur = ptree->root;
    Node* parent = NULL;
    while (cur != NULL) {
        parent = cur;
        if (cur->key < key) cur = cur->right;
        else cur = cur->left;
        height++;
    }
    if (parent == NULL) ptree->root = newNode;
    else if (parent->key < key) parent->right = newNode;
    else  parent->left = newNode;
    res += height + 1;
    ptree->num++;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, key;
    Tree tree;
    tree.root = NULL;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> key;
        insert(&tree, key);
    }
    cout << res;
    return 0;
}
```

## 최종 제출 코드

```cpp
#include <iostream>
#include <set>
using namespace std;

set<int> a;
int height[250002];
long long res;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, key;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> key;
        auto itr = a.lower_bound(key);
        long long left = 0;
        long long right = 0;
        if (itr != a.begin()) left = height[*prev(itr)];
        if (itr != a.end()) right = height[*itr];
        height[key] = max(left, right) + 1;
        res += height[key];
        a.insert(key);
    }
    cout << res;
    return 0;
}
```

👉 이진 검색 트리를 inorder로 순회하면 오름차순 정렬 리스트를 구할 수 있다. 즉, 노드를 추가해도 inorder로 순회하면 오름차순으로 정렬된다. 따라서, 트리를 정렬된 리스트로 볼 때, 노드를 추가하면 `lower_bound`와 그 이전의 노드 사이에 추가됨을 알 수 있다. (중복 키가 없다는 가정 하에) 높이는 `lower_bound`와 그 이전 노드의 높이 중 최대값을 골라 +1를 하면 추가된 노드의 높이가 된다.
