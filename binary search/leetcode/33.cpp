// Search in Rotated Sorted Array

int search(int* nums, int numsSize, int target){
    int left = 0;
    int right = numsSize - 1;
    while (left <= right){
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] >= nums[left]){
            if (nums[mid] > target && target >= nums[left]) right = mid - 1;
            else left = mid + 1;
        }
        else {
            if (nums[mid] < target && target <= nums[right]) left = mid + 1;
            else right = mid - 1;
        }
    }
    return -1;
}