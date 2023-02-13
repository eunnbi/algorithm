#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

unordered_map<string, string> a;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    string site, password;
    cin >> n >> m;
    while (n--) {
        cin >> site >> password;
        a[site] = password;
    }
    while (m--) {
        cin >> site;
        cout << a[site] << '\n';
    }
    return 0;
}
