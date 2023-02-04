#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[100001];

int main() {
    // ⚠️ 아래 두줄 없으면 시간초과 발생
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    cin >> m;
    while (m--) {
        int num;
        cin >> num;
        cout << binary_search(a, a + n, num) << '\n';
    }
    return 0;
}
