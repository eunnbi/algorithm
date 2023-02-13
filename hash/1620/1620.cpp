#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <cctype>
#include <string>
using namespace std;

unordered_map<string, int> a;
string name[100002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> name[i];
        a[name[i]] = i;
    }
    
    string input;
    while (m--) {
        cin >> input;
        if (isdigit(input[0])) {
            cout << name[stoi(input)] << '\n';
        }
        else {
            cout << a[input] << '\n';
        }
    }
    return 0;
}