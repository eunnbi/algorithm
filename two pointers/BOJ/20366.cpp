#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <tuple>
using namespace std;

int a[602];
vector<tuple<int, int, int>> two;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            two.push_back({ a[i] + a[j], i, j });
        }
    }
    sort(two.begin(), two.end());
    int size = two.size();
    int mn = 1000000001;
    int left = 0;
    int right = 1;
    while (left < size && right < size) {
        int leftIdx1, leftIdx2, leftSum;
        tie(leftSum, leftIdx1, leftIdx2) = two[left];
        int rightIdx1, rightIdx2, rightSum;
        tie(rightSum, rightIdx1, rightIdx2) = two[right++];
        if (leftIdx1 == rightIdx1 || leftIdx1 == rightIdx2) continue;
        if (leftIdx2 == rightIdx1 || leftIdx2 == rightIdx2) continue;
        mn = min(mn, abs(leftSum - rightSum));
        left++;
        right = left + 1;
    }
    cout << mn;
    return 0;
}