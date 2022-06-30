int maximumScore(int* nums, int numsSize, int k){
    int left, right, min, res;
    left = right = k; // two pointers ✌️
    res = min = nums[k];
    
    while (min > 0){
        int left_num = left > 0 ? nums[left - 1] : 0;
        int right_num = right < numsSize - 1 ? nums[right + 1] : 0;
        if (left_num > right_num){
            if (min > left_num) min = left_num;
            left--;
        }
        else{
            if (min > right_num) min = right_num;
            right++;
        }
        if (min * (right - left + 1) > res) res = min * (right - left + 1);
    }
    return res;
}

/*
📝 Approach
- Find the maximum of "min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1)" (i <= k <= j)
- 'num[k]' must be included in the subarray
- Two pointers: initially, "left = right = k"
    - if nums[left - 1] > num[right + 1], left decreases
    - else, right increases
*/

// https://leetcode.com/problems/maximum-score-of-a-good-subarray/