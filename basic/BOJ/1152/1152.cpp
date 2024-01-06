#include <iostream>
#include <string>

using namespace std;

int main() {
    string a;
    getline(cin, a); // ⚠️ 공백 있는 문자열 입력 받기
    if (a == " ") {
        cout << 0;
        return 0;
    }
    int res = 0;
    int size = a.size();
    for (int i = 0 ; i < size; i++) {
        if (i != 0 && i != size - 1 && a.at(i) == ' ') {
            res++;
        }
    }
    cout << res + 1 << '\n';
    return 0;
}