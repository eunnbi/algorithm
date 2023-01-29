#include <iostream>
#include <deque>
using namespace std;

int n, k;
int k_copy;
string s;
deque<int> res;
int num;
int main() {
    cin >> n >> k;
    cin >> s;
    k_copy = k;
    for (int i = 0; i < n; i++) {
        while (k && !res.empty() && res.back() < s[i] - '0') {
            res.pop_back();
            k--;
        }
        res.push_back(s[i] - '0');
    }
    while (num < n - k_copy) {
        num++;
        cout << res.front();
        res.pop_front();
    }
    cout << '\n';
    return 0;
}