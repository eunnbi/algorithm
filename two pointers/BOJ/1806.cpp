#include <iostream>
#include <algorithm>
using namespace std;

int a[100001];

int main() {
    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
	// ⚠️ 배열 a를 정렬할 필요 없음!
    int i = 0;
    int j = 0;
    int sum = a[0];
    int mn = 100002;
    while (i <= j && j < n) {
        if (sum >= s) {
            mn = min(mn, j - i + 1);
            sum -= a[i++];
        }
        else sum += a[++j];
    }
    if (mn == 100002) cout << 0;
    else cout << mn;
    return 0;
}
