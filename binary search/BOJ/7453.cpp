#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> a[4];
vector<int> two1;
vector<int> two2;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            int num;
            cin >> num;
            a[j].push_back(num);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            two1.push_back(a[0][i] + a[1][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            two2.push_back(a[2][i] + a[3][j]);
        }
    }
    long long res = 0;
    sort(two1.begin(), two1.end());
    for (int i = 0; i < two2.size(); i++) {
        int u = upper_bound(two1.begin(), two1.end(), -two2[i]) - two1.begin();
        int l = lower_bound(two1.begin(), two1.end(), -two2[i]) - two1.begin();
        res += (u - l);
    }
    cout << res << '\n';
    return 0;
}