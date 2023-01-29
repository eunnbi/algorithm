#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> s[100001]; // end time, start time
int endTime, res;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i].second >> s[i].first;
    }
    sort(s, s + n);
    for (int i = 0; i < n; i++) {
        if (s[i].second >= endTime) {
            endTime = s[i].first;
            res++;
        }
    }
    cout << res << '\n'; 
}