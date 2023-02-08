#include <iostream>
using namespace std;

int a[10003];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int res = 0;
    int i = 0;
    int j = 0;
    int sum = a[0];
    while (i < n && j < n) {
        if (i > j) sum += a[++j];
        if (sum < m) sum += a[++j];
        else if (sum > m) sum -= a[i++];
        else {
            res++;
            sum -= a[i++];
        }
    }
    cout << res;
    return 0;
}