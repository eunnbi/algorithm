#include <iostream>
using namespace std;

int a[100003];
bool exist[100003];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    long long res = 0; // ⚠️ integer overflow 주의!!
    int i = 0;
    int j = 0;
    while (i < n && j < n) {
        while (exist[a[j]] == true) {
            exist[a[i++]] = false;
        }
        res += j - i + 1;
        exist[a[j++]] = true;
    }
    cout << res;
    return 0;
}