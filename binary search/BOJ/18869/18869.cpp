#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int m, n;
int s[101][10001];

// 좌표압축
void compress(int* a) {
    vector<int> v(a, a + n);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
        }
        compress(s[i]);
    }
    
    int res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            bool isPossible = true;
            for (int k = 0; k < n; k++) {
                if (s[i][k] != s[j][k]) {
                    isPossible = false;
                    break;
                }
            }
            if (isPossible) res++;
        }
    }
    cout << res << '\n';
    return 0;
}