#include <iostream>
#define MAX 1000001
using namespace std;

int a[1000001];

int main() {
    int n, k, l, r;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        for (int j = l + 1; j <= r; j++) a[j]++;
    }
    
    int left = 0;
    int right = 0;
    int sum = 0;
    while (left < MAX && right < MAX) {
        if (sum < k) sum += a[++right];
        else if (sum > k) sum -= a[++left];
        else {
            cout << left << ' ' << right;
            return 0;
        }
    }
    cout << "0 0";
    return 0;
}
