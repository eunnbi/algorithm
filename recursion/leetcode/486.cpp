// Predict the Winner

#define max(a, b) (((a) > (b)) ? (a) : (b))
int predict(int* nums, int left, int right, int turn){
    if (left == right){
        return turn * nums[left]; 
    }
    
    // left 선택
    int a = turn * nums[left] + predict(nums, left + 1, right, -turn);
    // right 선택
    int b = turn * nums[right] + predict(nums, left, right - 1, -turn);
    
    return turn * max(turn * a, turn * b);
}

bool PredictTheWinner(int* nums, int numsSize){
    return predict(nums, 0, numsSize - 1, 1) >= 0;
}