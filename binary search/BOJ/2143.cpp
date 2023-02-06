#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[1001];
int b[1001];
vector<int> sumA;
vector<int> sumB;
int main() {
    int t, n, m;
    cin >> t;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    
    for (int i = 0; i < n; i++) {
        sumA.push_back(a[i]);
        int sum = a[i];
        for (int j = i + 1; j < n; j++) {
            sum += a[j];
            sumA.push_back(sum);
        }
    }
     for (int i = 0; i < m; i++) {
        sumB.push_back(b[i]);
        int sum = b[i];
        for (int j = i + 1; j < m; j++) {
            sum += b[j];
            sumB.push_back(sum);
        }
    }
    sort(sumA.begin(), sumA.end());
    long long res = 0; // ⚠️ integer overflow 주의!!
    for (int val: sumB) {
        int target = t - val;
        int u = upper_bound(sumA.begin(), sumA.end(), target) - sumA.begin();
        int l = lower_bound(sumA.begin(), sumA.end(), target) - sumA.begin();
        res += (u - l);
    }
    cout << res << '\n';
    return 0;
}


// Prefix Sum + Binary Search
// https://www.acmicpc.net/problem/2143