#include <iostream>
#include <algorithm>
using namespace std;

int a[100001];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int mn = 2000000001;
    sort(a, a + n);
    int i = 0;
    int j = 0;
    while (i <= j && j < n) {
       if (a[j] - a[i] >= m) {
            mn = min(mn, a[j] - a[i]);
            i++;
        }
        else j++;
    }
    cout << mn;
    return 0;
}