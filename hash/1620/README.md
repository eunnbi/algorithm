# 나는야 포켓몬 마스터 이다솜 🥈

```cpp
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <cctype>
#include <string>
using namespace std;

// 두 개의 자료구조 이용
unordered_map<string, int> a; // unordered map
string name[100002]; // string array

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
        if (isdigit(input[0])) { // 입력이 숫자이면
            cout << name[stoi(input)] << '\n'; // stoi 함수를 이용하여 int형으로 변환
        }
        else {
            cout << a[input] << '\n';
        }
    }
    return 0;
}
```
