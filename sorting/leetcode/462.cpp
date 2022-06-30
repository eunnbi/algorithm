#include <vector>
#include <algorithm>

using namespace std;


// 1. implement merge sort and use it
int sorted[100003];
void merge(int* nums, int left, int right, int mid){
    int first = left, second = mid + 1;
    int i = left;
    while (first <= mid && second <= right){
        if (nums[first]  < nums[second]) sorted[i++] = nums[first++];
        else sorted[i++] = nums[second++];
    }
    while (first <= mid){
        sorted[i++] = nums[first++];
    }
    while (second <= right){
        sorted[i++] = nums[second++];
    }
    
    for (int j = left; j <= right; j++){
        nums[j] = sorted[j];
    }
}

void mergeSort(int* nums, int left, int right){
    if (left < right){
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, right, mid);
    }
}


int minMoves2(int* nums, int numsSize){
    mergeSort(nums, 0, numsSize - 1);
    int median = nums[numsSize / 2]; // 핵심 : 중앙값 찾기
    int res = 0;
     for (int i = 0; i < numsSize; i++){
        int num = nums[i] - median;
        res += (num >= 0) ? num : -num;
    }
    return res;
}


// 2. using sort function (STL)
int minMoves2(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int size = nums.size();
    int median = nums[size / 2];
    int res = 0;
    for (int i = 0; i < size; i++){
        int num = nums[i] - median;
        res += (num >= 0) ? num : -num;
    }
    return res;        
}

// This problem is equivalent to compute "argmin(x)Σ(arr(i) - x)" => Key : Sort and Get Median
// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/