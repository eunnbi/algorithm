#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int s[102];
bool power[102];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> s[i];
    }
    
    int cnt = 0;
    int res = 0;
    for (int i = 1; i <= k; i++) {
        int cur = s[i];
        if (power[cur]) continue;
        if (cnt < n) {
            power[cur] = true;
            cnt++;
        }
        else {
            vector<pair<int, int>> idx;
            for (int x = 1; x <= k; x++) {
                if (!power[x]) continue;
                bool vis = false;
                for (int y = i + 1; y <= k; y++) {
                    if (s[y] == x) {
                        idx.push_back({ y, x });
                        vis = true;
                        break;
                    }
                }
                if (!vis) idx.push_back({ k + 1, x });
            }
            sort(idx.begin(), idx.end(), greater<pair<int, int>>());
            int target = idx[0].second;
            power[target] = false;
            power[s[i]] = true;
            res++;
        }
    }
    cout << res << '\n';
    return 0;
}
