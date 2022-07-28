#include <bits/stdc++.h>
using namespace std;

int N;
int nums[1002];

int main(void) {
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> nums[i];
    }
    sort(nums, nums + N);
    for (int i = 0; i < N; i++){
        printf("%d\n", nums[i]);
    }
    return 0;
}