#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int res;
string s;
int zero, one;
int main() {
    cin >> s;
    int size = s.size();
    for (int i = 1; i < size; i++) {
        if (s[i] != s[i - 1]) {
            if (s[i - 1] == '0') zero++;
            else one++;
        }
    }
    if (s[size - 1] == '0') zero++;
    else one++;

    if (zero + one == 1) res = 0;
    else res = min(zero, one);
    
    cout << res << '\n';
    return 0;
}
