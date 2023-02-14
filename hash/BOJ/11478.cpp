#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<string> a;

int main() {
    string s;
    cin >> s;
    int size = s.size();
    for (int i = 0; i < size; i++) {
        string substr = "";
        for (int j = i; j < size; j++) {
            substr += s[j];
            a.insert(substr);
        }
    }
    long long res = 0;
    for (auto val: a) res++;
    cout << res << '\n';
    return 0;
}