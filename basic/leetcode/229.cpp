#include <vector>
#include <algorithm>

using namespace std;

// 1. sorting
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> res;
        int num = nums[0];
        int cnt = 0;
        for (int i = 0; i < size; i++) {
            if (num == nums[i]) {
                cnt++;
                if (cnt ==  size / 3 + 1) { // 개수가 n / 3 넘는 최초의 순간만
                    res.push_back(num);
                }
            }
            else {
                num = nums[i--];
                cnt = 0;
            }
        }
        return res;
    }
};

// 2. Boyer-Moore Voting
int* majorityElement(int* nums, int numsSize, int* returnSize){
    int major1, major2;
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < numsSize; i++){
        if (nums[i] == major1) count1++;
        else if (nums[i] == major2) count2++;
        else if (count1 == 0) {
            major1 = nums[i];
            count1++;
        }
        else if (count2 == 0){
            major2 = nums[i];
            count2++;
        }
        else{
            count1--;
            count2--;
        }
        
    }

    count1 = 0;
    count2 = 0;
    for (int i = 0; i < numsSize; i++){
        if (nums[i] == major1) count1++;
        else if (nums[i] == major2) count2++;
    }
    int size = 0;
    if (count1 > numsSize / 3) size++;
    if (count2 > numsSize / 3) size++;

    *returnSize = size;
    
    int* res = (int *)malloc(sizeof(int) * size);
    if (size == 2) {
        res[0] = major1;
        res[1] = major2;
    }
    else {
        if (count1 > numsSize / 3) res[0] = major1;
        else if (count2 > numsSize / 3) res[0] = major2;
    }
    return res;
}

// https://leetcode.com/problems/majority-element-ii/