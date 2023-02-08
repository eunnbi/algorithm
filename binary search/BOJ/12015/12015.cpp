#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int a[1000001];
vector<int> LIS;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < n; i++) {
        if (LIS.empty() || LIS.back() < a[i]) LIS.push_back(a[i]);
        else {
            int idx = lower_bound(LIS.begin(), LIS.end(), a[i]) - LIS.begin();
            LIS[idx] = a[i];
        }
    }
    cout << LIS.size() << '\n';
    return 0;
}