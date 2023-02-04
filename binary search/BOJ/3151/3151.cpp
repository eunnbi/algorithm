#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[10005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    long long res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = a[i] + a[j];
            // lower_bound : 찾으려는 값과 같거나 큰 숫자가 몇 번째에서 처음 등장하는지 찾기 위함
            int l = lower_bound(a + (j + 1), a + n, -sum) - a;
            // upper_bound : 찾으려는 값보다 큰 숫자가 몇 번째에서 처음 등장하는지 찾기 위함
            int u = upper_bound(a + (j + 1), a + n, -sum) - a;
            res += (u - l);
        }
    }
    cout << res;
    return 0;
}