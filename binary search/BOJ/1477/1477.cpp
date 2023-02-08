#include <iostream>
#include <algorithm>
using namespace std;

int n, m, l;
int a[52];
int dis[52];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> l;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a, a + n);
    if (n > 0) {
        dis[0] = a[0];
        for (int i = 1; i < n; i++) {
            dis[i] = a[i] - a[i - 1];
        }
        dis[n] = l - a[n - 1]; 
    }
    else dis[n] = l;
    
    int left = 1;
    int right = *max_element(dis, dis + n + 1);
    int mid, sum;
    while (left < right) {
        mid = left + (right - left) / 2;
        sum = 0;
        for (int i = 0; i <= n; i++) {
            if (dis[i] <= mid) continue;
            if (dis[i] % mid != 0) sum += dis[i] / mid;
            else sum += dis[i] / mid - 1;
        }
        if (sum > m) left = mid + 1;
        else right = mid;
    }
    cout << left;
    return 0;
}