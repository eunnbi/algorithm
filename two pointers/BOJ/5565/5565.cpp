#include <iostream>
#include <deque>
using namespace std;

int exist[3002];
deque<int> a;

int main() {
    int n, d, k, c;
    cin >> n >> d >> k >> c;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        a.push_back(num);
    }
    for (int i = 0; i < n; i++) {
        a.push_back(a[i]);
    }
    
    int size = a.size();
    int left = 0;
    int right = 1;
    int mx = 0;
    int num = 1;
    exist[a[left]]++;
    while (left < size && right < size) {
        if (!exist[a[right]]) num++;
        exist[a[right]]++;
        if (right - left + 1 == k) {
            if (exist[c]) mx = max(mx, num);
            else mx = max(mx, num + 1);
            exist[a[left]]--;
            if (exist[a[left]] == 0) num--;
            left++;
        }
        right++;
    }
    cout << mx;
    return 0;
}