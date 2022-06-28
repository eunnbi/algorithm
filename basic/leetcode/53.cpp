#include <limits.h>
int maxSubArray(int* nums, int numsSize){
	int max_sum = INT_MIN, sum = 0;
	for (int i = 0; i < numsSize; i++){
		if (sum >= 0) sum += nums[i];
		else sum = nums[i];

		if (sum > max_sum) max_sum = sum;
	}
	return max_sum;
}

// Naive Approach: 시간초과
/*
🤔 sum을 어떻게 업데이트해야 할까??
`Greedy Approach`
- `sum >= 0`: 현재 원소를 더해 업데이트
- `sum < 0`: sum을 현재 원소값으로 초기화하여 다시 시작
*/


// https://leetcode.com/problems/maximum-subarray/