#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> serials;

int sum(const string& str) {
    int size = str.size();
    int res = 0;
    for (int i = 0; i < size; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            res += str[i] - '0';
        }
    }
    return res;
}

bool cmp(const string& a, const string& b) {
    if (a.size() != b.size()) return a.size() < b.size();
    else if (sum(a) != sum(b)) return sum(a) < sum(b);
    else {
        int size = a.size();
        for (int i = 0; i < size; i++) {
            if (a[i] == b[i]) continue;
            return a[i] < b[i];
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    string str;
    for (int i = 0; i < N; i++) {
        cin >> str;
        serials.push_back(str);
    }
    sort(serials.begin(), serials.end(), cmp);

    for (int i = 0; i < N; i++) {
        cout << serials[i] << '\n';
    }
    return 0;
}