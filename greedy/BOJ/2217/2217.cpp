#include <iostream>
#include <algorithm>
using namespace std;

int n;
int w[100001];
int res;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    sort(w, w + n);
    for (int i = n - 1; i >= 0; i--) {
        int weight = w[i] * (n - i);
        if (res < weight) {
            res = weight;
        }
    }
    cout << res << '\n'; 
}