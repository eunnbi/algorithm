#include <bits/stdc++.h>
using namespace std;

int N;
int nums[1000001];
int sorted[1000001];

void merge(int left, int mid, int right){
    int first = left, second = mid + 1;
    int index = left;
    while (first <= mid && second <= right){
        if (nums[first] < nums[second]){
            sorted[index++] = nums[first++];
        }
        else {
            sorted[index++] = nums[second++];
        }
    }

    while (first <= mid) {
        sorted[index++] = nums[first++];
    }
    while (second <= right) {
        sorted[index++] = nums[second++];
    }

    for (int i = left; i <= right; i++){
        nums[i] = sorted[i];
    }

}

void mergeSort(int left, int right){
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}

int main(void) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    mergeSort(0, N - 1);
    for (int i = 0; i < N; i++) {
        printf("%d\n", nums[i]);
    }
    return 0;
}