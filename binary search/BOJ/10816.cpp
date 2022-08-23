#include <bits/stdc++.h>
using namespace std;

int N, M;
int nums[500001];

int search_first(int target) {
    int left = 0;
    int right = N - 1;
    int mid, res = -1;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            res = mid;
            right = mid - 1;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return res;
}

int search_last(int target) {
    int left = 0;
    int right = N - 1;
    int mid, res = -1;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            res = mid;
            left = mid + 1;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return res;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    sort(nums, nums + N);

    cin >> M;
    int num;
    while (M--) {
        cin >> num;
        //  cout << upper_bound(nums, nums + N, num) - lower_bound(nums, nums + N, num) << ' ';
        int last = search_last(num);
        int first = search_first(num);
        if (last == -1) cout << 0 << ' ';
        else cout << last - first + 1 << ' ';
    }
    return 0;
}