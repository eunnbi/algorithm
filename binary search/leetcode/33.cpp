int search(int* nums, int numsSize, int target){
    int left = 0;
    int right = numsSize - 1;
    while (left <= right){
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        if (nums[left] <= nums[mid]){
            if (nums[left] <= target && target < nums[mid]) right = mid - 1;
            else left = mid + 1;
        }
        else {
            if (nums[mid] < target && target <= nums[right]) left = mid + 1;
            else right = mid - 1;
        }
    }
    return -1;
}

/*
👀 Approach
- A rotated array is not sorted (although the original array is sorted), so we cannot directly apply binary search.
- But the original array is sorted, so there is a "sorted subarray."
    - left sorted subarray → "arr[l] ≤ arr[mid]"
        - If "arr[l] ≤ target && target < arr[mid]", search the left subarray.
        - Otherwise, search the right subarray
    - right sorted subarray → "arr[l] > arr[mid]"
        - If "arr[mid] < target && target <= arr[r]" , search the right subarray.
        - Otherwise, search the left subarray
*/

// https://leetcode.com/problems/search-in-rotated-sorted-array/