#include <algorithm>
#include <vector>

using namespace std;

// 1. 정렬
/*
majority element가  배열의 길이 절반 이상으로 차지하는 것이므로, 
배열을 정렬한다면 해당 원소는 반드시 배열의 중앙에 위치하게 된다.
*/ 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

// 2. Boyer-Moore Voting
// 배열에 포함된 원소들 중 절반 이상 포함된 원소를 linear time 과 constant space 로 찾을 수 있는 알고리즘

int majorityElement(int* nums, int numsSize){
  int major, count = 0;
	for (int i = 0; i < numsSize; i++){
		if (count == 0) {
			major = nums[i];
			count++;
		}
		else if (major == nums[i]){
			count++;
		}
		else count--;
	}
	return major;
}




// https://leetcode.com/problems/majority-element/