void moveZeroes(int* nums, int numsSize){
	int index = 0;
	for (int i = 0; i < numsSize; i++){
		if (nums[i]) nums[index++] = nums[i];
	}
	for (; index < numsSize; index++) nums[index] = 0;
}


// https://leetcode.com/problems/move-zeroes/