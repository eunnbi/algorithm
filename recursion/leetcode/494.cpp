
// 1.
int test(int* nums, int n, int i, int target){
	if (i == n){
	  if (target == 0) return 1;
	  else return 0;
    }
    
	int sum = 0;
	for (int j = i; j < n; j++) sum += nums[j];
	if (target > sum || -sum > target) return 0; // pruning (가지치기) - narrow down search space

    return test(nums, n, i + 1, target-nums[i]) + test(nums, n, i + 1, target + nums[i]);
}

int findTargetSumWays(int* nums, int numsSize, int target){
  return test(nums, numsSize, 0, target);
}



// 2.
int cnt;
void sol(int* nums, int numsSize, int target, int i, int res){
    if (i == numsSize){
        if (target == res) cnt++;
        return;
    }
    
    sol(nums, numsSize, target, i + 1, res + nums[i]);
    sol(nums, numsSize, target, i + 1, res - nums[i]);
}

int findTargetSumWays(int* nums, int numsSize, int target){
    cnt = 0;
    sol(nums, numsSize, target, 0, 0);
    return cnt;
}

// https://leetcode.com/problems/target-sum/