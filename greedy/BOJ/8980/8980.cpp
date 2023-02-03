#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

vector<tuple<int, int, int>> v;
int truck[2002];

int main() {
    int n, c, m;
    cin >> n >> c;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        v.push_back({ y, x, z });
    }
    
    sort(v.begin(), v.end());
    int size = v.size();
    int res = 0;
    for (int i = 0; i < size; i++) {
        int x, y, z;
        tie(y, x, z) = v[i];
        bool loadable = true;
        for (int j = x; j < y; j++) {
            z = min(z, c - truck[j]);
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