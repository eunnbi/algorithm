#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> a;
long long res;
int convertTimetoInt(string t) {
    string h = t.substr(0, 2);
    string m = t.substr(3, 5);
    return (h[0] * 10 + h[1]) * 60 + m[0] * 10 + m[1];
}

int main() {
    string s, e, q;
    cin >> s >> e >> q;
    
    int start = convertTimetoInt(s);
    int end = convertTimetoInt(e);
    int streaming = convertTimetoInt(q);
    while (true) {
        string t, name;
        cin >> t >> name;
        if (cin.eof() == true) break;
        int c = convertTimetoInt(t);
        if (c <= start) a[name] = c;
        else if (c >= end && c <= streaming && a.find(name) != a.end()) {
            res++;
            a.erase(name);
        }
        
    }
    cout << res << '\n';
    return 0;
}