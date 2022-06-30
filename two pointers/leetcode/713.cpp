
int numSubarrayProductLessThanK(int* nums, int numsSize, int k){
    int i = 0, j = 0; // two pointers ✌️
    int res = 0;
    int prod = 1;
    for (i = 0; i < numsSize; i++){
        if (j < i) {
            j = i;
            prod = 1;
        }
        while (j < numsSize && prod * nums[j] < k){
            prod *= nums[j++];
        } 
        if (i < j){
            res += j - i;
            prod /= nums[i];
        }
    }
    return res;
}

// 👉 Reuse the intermediate result (previous product)
// https://leetcode.com/problems/subarray-product-less-than-k/