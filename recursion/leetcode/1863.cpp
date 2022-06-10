// Sum of All Subset XOR Totals

int sol(int* nums, int numsSize, int i, int res){
    if (i == numsSize) return res;
    
    int a = sol(nums, numsSize, i + 1, res);
    int b = sol(nums, numsSize, i + 1, res ^ nums[i]);
    
    return a + b;
}


int subsetXORSum(int* nums, int numsSize){
   return sol(nums, numsSize, 0, 0);
}