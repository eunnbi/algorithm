#include <iostream>

using namespace std;

int count[100002];
int a[200002];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int mx = 0;
    int left = 0;
    int right = 0;
    while (left < n && right < n) {
        while (count[a[right]] >= k) {
            count[a[left++]]--;
        }
        count[a[right]]++;
        mx = max(mx, right - left + 1);
        right++;
    }
    cout << mx;
    return 0;
}