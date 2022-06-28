// 1. 
int mask[14];
int generate_subset(int* nums, int numsSize, int i){
    if (i == numsSize){
        int xor = 0;
        for (int j = 0; j < numsSize; j++) xor ^= mask[j] ? nums[j] : 0;
        return xor;
    }
    mask[i] = 0;
    int total1 = generate_subset(nums, numsSize, i + 1);
    
    mask[i] = 1;
    int total2 = generate_subset(nums, numsSize, i + 1);
    
    return total1 + total2;
}

int subsetXORSum(int* nums, int numsSize){
    return generate_subset(nums, numsSize, 0);
}

/*
📝 Approach
- consider all subset ⇒ recursion
- How to generate all subsets?
    - This is equivalent to generating all strings of length N only using 0 and 1. (`N`은 배열의 길이!)
    - 0 in mask[i] means nums[i] is excluded in the subset while 1 means nums[i] is included.
- Once the subset is determined, we compute the XOR value and accumulate it
*/



// 2.
// Update the total incrementally in parallel with generating subsets
// Don’t have to maintain the global mask array
int generate_subset(int* nums, int numsSize, int i, int currentTotal){
    if (i == numsSize) return currentTotal;

    int total1 = generate_subset(nums, numsSize, i + 1, currentTotal);
    int total2 = generate_subset(nums, numsSize, i + 1, currentTotal ^ nums[i]);
    
    return total1 + total2;
}

int subsetXORSum(int* nums, int numsSize){
    return generate_subset(nums, numsSize, 0, 0);
}


// 3.
// compute the OR of all numbers and left shift it by (n - 1) times
int subsetXORSum(int* nums, int numsSize){
	int ans = 0;
	for (int i = 0; i < numsSize; i++) ans |= nums[i];
	return ans << (numsSize - 1);
}

// https://leetcode.com/problems/sum-of-all-subset-xor-totals/