// Target Sum

int sol(int* nums, int numsSize, int target, int i){
    if (i == numsSize){
        if (target == 0) return 1;
        else return 0;
    }
    int sum = 0;
    for (int j = i; j < numsSize; j++) sum += nums[j];
    if (target > sum || target < - sum) return 0;
    int a = sol(nums, numsSize, target - nums[i], i + 1);
    int b = sol(nums, numsSize, target + nums[i], i + 1);
    return a + b;
}


int findTargetSumWays(int* nums, int numsSize, int target){
    return sol(nums, numsSize, target, 0);
}